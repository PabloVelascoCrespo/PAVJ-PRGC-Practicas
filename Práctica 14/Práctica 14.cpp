#include <iostream>
#define COLOR_ENUM \
	REG_MACRO(Rojo) \
	REG_MACRO(Azul) \
	REG_MACRO(Verde) \
	REG_MACRO(Amarillo)

struct EColor
{
	enum Enum
	{
#define REG_MACRO(_PARAM) _PARAM,

		COLOR_ENUM
#undef REG_MACRO
	};

	static const char* AsString(Enum _eEnum)
	{
#define REG_MACRO(_PARAM) \
	case _PARAM: \
		return #_PARAM;

		switch (_eEnum)
		{
			COLOR_ENUM
		default:
			return "a";
		}
#undef REG_MACRO
	}
	
	static Enum AsEnum(const char * _sEnum)
	{
#define REG_MACRO(_PARAM) \
	if (strcmp(_sEnum, #_PARAM) == 0) \
	{\
		return _PARAM;\
	}
		COLOR_ENUM
#undef REG_MACRO
			return Enum();
	}
};


int main()
{
	printf("%s\n", EColor::AsString(EColor::Enum::Rojo));
	printf("%s\n", EColor::AsString(EColor::Enum::Verde));

	EColor::Enum eColor = EColor::AsEnum("Azul");
	printf("%s\n", EColor::AsString(eColor));

	constexpr float PI = 3.1416f;
}