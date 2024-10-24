#pragma once

class TFile
{
private:
	void* pFile;

public:
	void* OpenFile(const char* _sFilename, const char* _sMode);
	bool CloseFile();
	size_t ReadFile(char* _pBuffer, size_t _uSize);
	size_t WriteFile(char* _pBuffer, size_t _uSize);
	TFile();
	~TFile();
};