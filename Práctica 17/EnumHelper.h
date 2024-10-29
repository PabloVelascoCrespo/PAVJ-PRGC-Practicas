#include <string>
#include <unordered_map>

template <typename Enum>
class EnumHelper {
public:
    // Constructor que recibe un array de nombres de enumerados
    EnumHelper(const char* names[], int count) {
        for (int i = 0; i < count; ++i) {
            enumToStr[static_cast<Enum>(i)] = names[i];
            strToEnum[names[i]] = static_cast<Enum>(i);
        }
    }

    // Convierte Enum a const char*
    const char* AsStr(Enum eEnum) const {
        auto it = enumToStr.find(eEnum);
        return it != enumToStr.end() ? it->second.c_str() : nullptr;
    }

    // Convierte const char* a Enum
    Enum AsEnum(const char* sEnum) const {
        auto it = strToEnum.find(sEnum);
        return it != strToEnum.end() ? it->second : Enum();
    }

private:
    std::unordered_map<Enum, std::string> enumToStr;
    std::unordered_map<std::string, Enum> strToEnum;
};

#define DECLARE_ENUM(EnumName, ...) \
    enum class EnumName { __VA_ARGS__, COUNT }; \
    const char* EnumName##_Strings[] = { #__VA_ARGS__ }; \
    EnumHelper<EnumName> EnumName##_Helper(EnumName##_Strings, static_cast<int>(EnumName::COUNT));

#define ENUM_TO_STR(EnumName, eEnum) EnumName##_Helper.AsStr(eEnum)
#define STR_TO_ENUM(EnumName, sEnum) EnumName##_Helper.AsEnum(sEnum)

