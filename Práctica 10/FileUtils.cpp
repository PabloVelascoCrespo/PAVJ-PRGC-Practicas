#include "TList.h"
#include "FileUtils.h"
#include <iostream>
#include <string>
namespace Practica5
{
	void* OpenFile(const char* _sFilename, const char* _sMode)
	{
		std::FILE* pFile;
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

	void* GetNumList(void* _pFile)
	{
		TList* lLista = new TList();
		std::FILE* pFile = reinterpret_cast<std::FILE*>(_pFile);

		if (pFile == nullptr)
		{
			printf("Error al abrir el fichero.\n");
			return 0;
		}

		char sBuffer[20];
		int iIndex = 0;
		char cCaracter;
		while ((cCaracter = static_cast<char>(fgetc(pFile))) != EOF)
		{
			if (cCaracter == ',')
			{
				sBuffer[iIndex] = '\0';
				iIndex = 0;
				lLista->Push(sBuffer);
			}
			else
			{
				sBuffer[iIndex++] = cCaracter;
			}
		}

		if (iIndex > 0)
		{
			sBuffer[iIndex] = '\0';
			lLista->Push(sBuffer);
		}

		return static_cast<void*>(lLista);
	}
}