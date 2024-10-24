#pragma once

namespace Practica5
{
	void* OpenFile(const char* _sFilename, const char* _sMode);
	bool CloseFile(void* _pFile);
	size_t ReadFile(char* _pBuffer, size_t _uSize, void* _pFile);
	size_t WriteFile(char* _pBuffer, size_t _uSize, void* _pFile);

	void* GetNumList(void* _pFile);
}
