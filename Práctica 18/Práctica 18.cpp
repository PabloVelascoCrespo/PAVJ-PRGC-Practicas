#include <iostream>
#include <unordered_map>
#include <string>
#include <windows.h>
#define MEMORY_LEAKS_MONITOR
/*
PRÁCTICA 18
Implementar un sistema de Macros que permita la detección de
"memory leaks".
    a) El sistema sólo se activará cuando esté definida la macro
    MEMORY_LEAKS_MONITOR. Si la macro no está definida se tiene que
    funcionar sin ningún control de "memory leaks".
    b) Se definirán las macros NEW y NEW_ARRAY. Cuando se pida memoria se
    utilizarán dichas macros en lugar de los operaodres new y new[].
    c) Se definirán las macros DELETE y DELETE_ARRAY. Cuando se libere la memoria se
    utilizarán dichas macros en lugar de los operadores delete y delete [].
    d) Se definirá una macro para mostrar por la ventana de "output" del Visual
    Studio (usando la función OutputDebugString): las direcciones de memoria y el 
    tamaño pendientes de liberar. El formato de salida será similar al de los
    mensajes de aviso que saca VS para posibilitar que haciendo clic sobre el 
    mensaje nos lleve al sitio donde se encuentra la fuga de memoria.
*/
#ifdef MEMORY_LEAKS_MONITOR

struct SMemoryInfo
{
    size_t stSize;
    const char* sFile;
    unsigned int uLine;
};

std::unordered_map<void*, SMemoryInfo> g_memoryMap;

void RegisterAllocation(void* _ptr, size_t _stSize, const char* _sFile, unsigned int _uLine)
{
    g_memoryMap[_ptr] = { _stSize, _sFile, _uLine};
    std::string sMsg = "Allocated at: " + std::string(_sFile) + ":" + std::to_string(_uLine) + " - Address: " + std::to_string(reinterpret_cast<uintptr_t>(_ptr)) + " Size: " + std::to_string(_stSize) + "\n";
    wchar_t wtext[256];
    size_t* wtextSize = 0;
    mbstowcs_s(wtextSize, wtext, sMsg.c_str(), sMsg.length());
    OutputDebugString(wtext);
}

void RegisterDeallocation(void* _ptr)
{
    if (g_memoryMap.find(_ptr) != g_memoryMap.end())
    {
        g_memoryMap.erase(_ptr);
    }
    else 
    {
        OutputDebugString(L"Warning: Attempted to deallocate untracked memory!\n");
    }
}

void ReportMemoryLeaks()
{
    for (const auto& entry : g_memoryMap)
    {
        const auto& info = entry.second;
        std::string sMsg = "Memory leak at " + std::string(info.sFile) + ":" + std::to_string(info.uLine) +" - Address: " + std::to_string(reinterpret_cast<uintptr_t>(entry.first)) + " Size: " + std::to_string(info.stSize) + "\n";
        wchar_t wtext[256];
        size_t* wtextSize = 0;
        mbstowcs_s(wtextSize, wtext, sMsg.c_str(), sMsg.length());
        OutputDebugString(wtext);
    }
}

#define NEW(size) (RegisterAllocation(new char[size], size, __FILE__, __LINE__), new char[size])
#define NEW_ARRAY(type, count) (RegisterAllocation(new type[count], sizeof(type) * count, __FILE__, __LINE__), new type[count])
#define DELETE_(ptr) (RegisterDeallocation(ptr), delete ptr)
#define DELETE_ARRAY(ptr) (RegisterDeallocation(ptr), delete[] ptr)

#else // ELSE: MEMORY_LEAKS_MONITOR

#define NEW(size) new char[size]
#define NEW_ARRAY(type, count) new type[count]
#define DELETE_(ptr) delete ptr
#define DELETE_ARRAY(ptr) delete[] ptr

#endif // END_IF MEMORY_LEAKS_MONITOR

int main()
{
#ifdef MEMORY_LEAKS_MONITOR
    // Asignaciones de prueba
    int* pInt = NEW_ARRAY(int, 10);
    DELETE_ARRAY(pInt);
    int* pLeak = NEW_ARRAY(int, 5); // Esta memoria no será liberada para probar el reporte de memory leaks

    // Reporte de memory leaks
    ReportMemoryLeaks();
    DELETE_ARRAY(pLeak);

#endif
}