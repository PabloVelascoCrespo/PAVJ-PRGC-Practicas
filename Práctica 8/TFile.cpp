#include "TFile.h"
#include <iostream>
#include <string>

TFile::TFile() : pFile(nullptr) {}

TFile::~TFile()
{
	CloseFile();
}

void* TFile::OpenFile(const char* _sFilename, const char* _sMode)
{
	std::FILE* pFile2;
	fopen_s(&pFile2, _sFilename, _sMode);
	pFile = pFile2;
	return pFile;
}

bool TFile::CloseFile()
{
	std::FILE* pFile2 = reinterpret_cast<std::FILE*>(pFile);
	if (fclose(pFile2) == 0)
	{
		return true;
	}
	return false;
}

size_t TFile::ReadFile(char* _pBuffer, size_t _uSize)
{
	std::FILE* pFile2 = reinterpret_cast<std::FILE*>(pFile);
	return std::fread(_pBuffer, sizeof(*_pBuffer), _uSize, pFile2);
}

size_t TFile::WriteFile(char* _pBuffer, size_t _uSize)
{
	std::FILE* pFile2 = reinterpret_cast<std::FILE*>(pFile);
	return fwrite(_pBuffer, sizeof(*_pBuffer), _uSize, pFile2);
}