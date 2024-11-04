#include <iostream>

/*
PRÁCTICA 17
Macros. Utilidades para enumerados:
    a) Crear una clase que contenga la definición de un enumerado y ofrezca la
    siguiente funcionalidad:
        i) const char* AsStr(Enum _eEnum);
        ii) Enum AsEnum(const char* _sEnum);
    b) Mediante macros generalizar el código anterior para que sea más fácil crear
    enumerados con esa funcionalidad.
*/
// a)
class CMyClassWithoutMacros
{
private:
    enum class Enum
    {
        Rojo,
        Verde,
        Azul,
        null
    };
public:
    const char* AsStr(Enum _eEnum)
    {
        switch (_eEnum)
        {
        case Enum::Rojo:
            return "Rojo";
        case Enum::Verde:
            return "Verde";
        case Enum::Azul:
            return "Azul";
        default:
            return nullptr;
        }
    }
    Enum AsEnum(const char* _sEnum)
    {
        if (strcmp(_sEnum, "Rojo") == 0)
        {
            return Enum::Rojo;
        }

        if (strcmp(_sEnum, "Verde") == 0)
        {
            return Enum::Verde;
        }

        if (strcmp(_sEnum, "Azul") == 0)
        {
            return Enum::Azul;
        }
        return Enum::null;
    }
};

// b)

#define EXPAND_MACRO(x) x
#define SELECT_MACRO(_1, _2, _3, _4, _5, _6, _7, NAME) NAME
#define APPLY_1(_FUNC, X) _FUNC(X)
#define APPLY_2(_FUNC, X, ...) EXPAND_MACRO(_FUNC(X)APPLY_1(_FUNC, __VA_ARGS__))
#define APPLY_3(_FUNC, X, ...) EXPAND_MACRO(_FUNC(X)APPLY_2(_FUNC, __VA_ARGS__))
#define APPLY_4(_FUNC, X, ...) EXPAND_MACRO(_FUNC(X)APPLY_3(_FUNC, __VA_ARGS__))
#define APPLY_5(_FUNC, X, ...) EXPAND_MACRO(_FUNC(X)APPLY_4(_FUNC, __VA_ARGS__))
#define APPLY_6(_FUNC, X, ...) EXPAND_MACRO(_FUNC(X)APPLY_5(_FUNC, __VA_ARGS__))
#define FOR_EACH(_ACTION, ...) \
EXPAND_MACRO(SELECT_MACRO(__VA_ARGS__, APPLY_6, APPLY_5, APPLY_4, APPLY_3, APPLY_2, APPLY_1)(_ACTION, __VA_ARGS__))

#define DEFINE_ENUM_VALUE(_VALUE) _VALUE,

#define ENUM_TO_STRING_CASE(_VALUE) \
	case _VALUE: \
		return #_VALUE;

#define STRING_TO_ENUM_CASE(_VALUE) \
		if (strcmp(valueString, #_VALUE) == 0) \
		{ \
			return _VALUE; \
		}

#define DEFINE_ENUM_CLASS(_NAME, ...) \
struct _NAME \
{ \
	enum Enum \
	{ \
		FOR_EACH(DEFINE_ENUM_VALUE, __VA_ARGS__) \
	}; \
	static const char* AsStr(Enum value) \
	{ \
		switch (value) \
		{ \
		FOR_EACH(ENUM_TO_STRING_CASE, __VA_ARGS__) \
		default: \
			return nullptr; \
		} \
	} \
	static Enum AsEnum(const char* valueString) \
	{ \
		FOR_EACH(STRING_TO_ENUM_CASE, __VA_ARGS__) \
		return static_cast<Enum>(-1); \
	} \
};


DEFINE_ENUM_CLASS(EColor, Blue, Brown, Green, Red, Orange, Yellow)

int main()
{
    const char* sCadena = EColor::AsStr(EColor::Brown);
    printf("%s\n", sCadena);

    EColor::Enum oBlue = EColor::AsEnum("Blue");
    if (oBlue == EColor::Blue)
    {
        printf("We have found blue!");
    }
    else
    {
        printf("We coulnd't find blue :c");
    }
}