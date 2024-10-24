#include "FileUtils.h"
#include <iostream>
#include <string.h>


void* OpenFile(const char* _sFilename, const char* _sMode)
{
	std::FILE *pFile;
	fopen_s(&pFile, _sFilename, _sMode);
	return pFile;
}

bool CloseFile(void* _pFile)
{
	std::FILE* pFile = reinterpret_cast<std::FILE*>(_pFile);
	if (fclose(pFile) == 0)
	{
		return true;
	}
	return false;
}

size_t ReadFile(char* _pBuffer, size_t _uSize, void* _pFile)
{
	std::FILE* pFile = reinterpret_cast<std::FILE*>(_pFile);
	return std::fread(_pBuffer, sizeof(*_pBuffer), _uSize, pFile);
}

size_t WriteFile(char* _pBuffer, size_t _uSize, void* _pFile)
{
	std::FILE* pFile = reinterpret_cast<std::FILE*>(_pFile);
	return fwrite(_pBuffer, sizeof(*_pBuffer), _uSize, pFile);
}
