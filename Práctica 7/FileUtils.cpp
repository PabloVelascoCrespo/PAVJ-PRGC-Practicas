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
}


namespace Practica6
{
	unsigned int VecesQueApareceCadenaEnFichero(char* _sCadena, void* _pFile)
	{
		unsigned int VecesQueApareceCadena_ = 0;
		unsigned int const uBufferSize = 128;
		char sBuffer[uBufferSize];
		size_t uReadChars = Practica5::ReadFile(sBuffer, uBufferSize, _pFile);
		sBuffer[uReadChars] = '\0';

		char* cInicioFile = sBuffer;
		char* cInicioCadena = _sCadena;

		for (size_t uIndex = 0; uIndex < uReadChars; uIndex++)
		{
			if (*cInicioFile == *cInicioCadena)
			{
				cInicioCadena++;
			}
			else
			{
				cInicioCadena = _sCadena;
			}
			if (*cInicioCadena == '\0')
			{
				VecesQueApareceCadena_++;
				cInicioCadena = _sCadena;
			}
			cInicioFile++;
		}
		return VecesQueApareceCadena_;
	}

	int SumaNumerosFichero(void* _pFile)
	{
		std::FILE* pFile = reinterpret_cast<std::FILE*>(_pFile);

		if (pFile == nullptr) {
			printf("Error al abrir el fichero.\n");
			return 0;
		}

		int iSuma = 0;
		char sBuffer[20];
		int iIndex = 0;
		char cCaracter;
		while ((cCaracter = static_cast<char>(fgetc(pFile))) != EOF)
		{
			if (cCaracter == ',')
			{
				sBuffer[iIndex] = '\0';
				iSuma += std::atoi(sBuffer);
				iIndex = 0;
			}
			else
			{
				sBuffer[iIndex++] = cCaracter;
			}
		}

		if (iIndex > 0)
		{
			sBuffer[iIndex] = '\0';
			iSuma += atoi(sBuffer);
		}

		Practica5::CloseFile(_pFile);
		return iSuma;
	}
}