#include <iostream>
#include "CString.h"

/*
Operadores:
    a) Dada la clase "CString" declarada en el fichero "String.h" implimentar en un 
    fichero .cpp toda la funcionalidad de dicha clase.
    b) Mejora: Implementar funcionalidad para que se puedan realizar operaciones de tipo:
        i) CString str("hola");
        ii) CString str2 = "Hola " + str + " caracola";
*/

int main()
{
    // Prueba de constructores
    CString str1("Hello");
    CString str2(str1);
    CString str3;

    // Prueba de operadores
    str3 = str1 + " World";
    printf("Concatenation: %s\n", str3.ToCString());

    str3 += "!";
    printf("Append: %s\n", str3.ToCString());

    if (str1 == CString("Hello"))
        printf("Equality: Pass\n");
    else
        printf("Equality: Fail\n");

    if (str1 != str3)
        printf("Inequality: Pass\n");

    // Prueba de acceso a índices
    str3[6] = 'W';
    printf("Modified String: %s\n", str3.ToCString());

    // Prueba de métodos de conversión
    CString numStr = CString::FromInt(12345);
    printf("FromInt: %s\n", numStr.ToCString());
    printf("ToInt: %d\n", numStr.ToInt());

    CString floatStr = CString::FromFloat(3.14f);
    printf("FromFloat: %s\n", floatStr.ToCString());
    printf("ToFloat: %.2f\n", floatStr.ToFloat());

    // Pruebas de manipulación de cadenas
    printf("Uppercase: %s\n", str1.ToUpper().ToCString());
    printf("Lowercase: %s\n", str1.ToLower().ToCString());

    CString trimmedStr = CString("   trimmed   ");
    printf("Trimmed: [%s]\n", trimmedStr.Trim().ToCString());

    CString left = str3.Left(5);
    printf("Left: %s\n", left.ToCString());

    CString right = str3.Right(6);
    printf("Right: %s\n", right.ToCString());

    CString mid = str3.Mid(6, 5);
    printf("Mid: %s\n", mid.ToCString());

    // Pruebas de funciones relacionadas con archivos
    CString fileContent = CString::Read("prueba.txt");
    printf("File Content: %s\n", fileContent.ToCString());

    fileContent.Write("output.txt", false);

    // Prueba de métodos de formato
    CString filePath = CString("C:\\folder\\file.txt");
    printf("Directory: %s\n", filePath.ExtractDir().ToCString());
    printf("File Name: %s\n", filePath.StripDir().ToCString());
    printf("File Extension: %s\n", filePath.ExtractExt().ToCString());

    CString replaced = str3.Replace("World", "Everyone");
    printf("Replaced String: %s\n", replaced.ToCString());
}