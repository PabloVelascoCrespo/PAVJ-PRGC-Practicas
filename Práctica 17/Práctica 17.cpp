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
        if (_sEnum == "Rojo")
        {
            return Enum::Rojo;
        }

        if (_sEnum == "Verde")
        {
            return Enum::Verde;
        }

        if (_sEnum == "Azul")
        {
            return Enum::Azul;
        }
        return Enum::null;
    }
};

// b)
#define CREATE_ENUM(EnumName, ...)\
enum class EnumName\
{ \
    Rojo, \
    Verde, \
    Azul, \
    null \
}; \

#define CREATE_CASE(...) \
case __VA_ARGS__: \
    return __VA_ARGS__\

#define CREATE_CLASS(ClassName, EnumName, ...) \
class CMyClassWithoutMacros2 \
{ \
private: \
    CREATE_ENUM(EnumName, ...) \
public: \
    const char* AsStr(EnumName _EnumName) \
    { \
        switch (EnumName) \
        { \
        CREATE_CASE(...) \
        } \
    } \
    EnumName AsEnumName(const char* _sEnum) \
    {
        if (_sEnum == "Rojo")
        {
            return Enum::Rojo;
        }

        if (_sEnum == "Verde")
        {
            return Enum::Verde;
        }

        if (_sEnum == "Azul")
        {
            return Enum::Azul;
        }
        return Enum::null;
    }
};
int main()
{

}