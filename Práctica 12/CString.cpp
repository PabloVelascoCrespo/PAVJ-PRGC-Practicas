#include "CString.h"

CString::CString(const char* str)
{
	m_p = _strdup(str);
}

CString::CString(const CString& str)
{
	m_p = _strdup(static_cast<const char*>(str.m_p));
}

CString::~CString()
{
	delete [] m_p;
}

bool CString::operator==(const CString& other) const
{
	if (strcmp(static_cast<const char*>(m_p), static_cast<const char*>(other.m_p)) == 0)
	{
		return true;
	}
	return false;
}

bool CString::operator!=(const CString& other) const
{
	return !(*this == other);
}

bool CString::operator<(const CString& other) const
{
	if (strcmp(static_cast<const char*>(m_p), static_cast<const char*>(other.m_p)) < 0)
	{
		return true;
	}
	return false;
}

bool CString::operator>(const CString& other) const
{
	return !(*this < other);
}

CString CString::operator+(const CString& other) const
{
	const char* sString1 = static_cast<const char*>(m_p);
	const char* sString2 = static_cast<const char*>(other.m_p);
	size_t stLen1 = strlen(sString1);
	size_t stLen2 = strlen(sString2);
	char* sResult = new char[stLen1 + stLen2 + 1];
	strcpy_s(sResult, stLen1 + 1, sString1);
	strcat_s(sResult, stLen1 + stLen2 + 1, sString2);
	CString newString(sResult);
	delete sResult;
	sResult = nullptr;
	return newString;
}

CString CString::operator+(char c) const
{
	const char* sString1 = static_cast<const char*>(m_p);
	size_t stLen1 = strlen(sString1);
	char* sResult = new char[stLen1 + 1 + 1];
	strcpy_s(sResult, stLen1 + 1, sString1);
	sResult[stLen1] = c;
	sResult[stLen1+1] = '\0';
	CString newString(sResult);
	delete sResult;
	sResult = nullptr;

	return newString;
}

CString& CString::operator=(const CString& other)
{
	if (this != &other)
	{
		delete m_p;
		m_p = nullptr;
		const char* sOther = static_cast<const char*>(other.m_p);
		size_t stLen = strlen(sOther);
		m_p = new char[stLen+1];
		strcpy_s(static_cast<char*>(m_p), stLen+1, sOther);
	}
	return *this;
}

CString& CString::operator=(char c)
{
	delete m_p;
	m_p = nullptr;
	m_p = new char[2];
	static_cast<char*>(m_p)[0] = c;
	static_cast<char*>(m_p)[1] = '\0';
	return *this;
}

CString& CString::operator+=(const CString& other)
{
	*this = *this + other;
	return *this;
}

CString& CString::operator+=(char c)
{
	*this = *this + c;
	return *this;
}

char& CString::operator[](unsigned int pos)
{
	return static_cast<char*>(m_p)[pos];
}

const char& CString::operator[](unsigned int pos) const
{
	return static_cast<const char*>(m_p)[pos];
}

int CString::Length() const
{
	return static_cast<int>(strlen(static_cast<const char*>(m_p)));
}

CString CString::FromInt(int val)
{
	char sBuffer[12];
	sprintf_s(sBuffer, "%d", val);
	return CString(sBuffer);
}

CString CString::HexFromInt(int val)
{
	char sBuffer[9];
	sprintf_s(sBuffer, "%X", val);
	return CString(sBuffer);
}

CString CString::FromFloat(float val)
{
	char sBuffer[32];
	sprintf_s(sBuffer, "%f", val);
	return CString(sBuffer);
}

int CString::ToInt() const
{
	return atoi(static_cast<const char *>(m_p));
}

float CString::ToFloat() const
{
	return static_cast<float>(atof(static_cast<const char*>(m_p)));
}

const char* CString::ToCString() const
{
	return static_cast<const char *>(m_p);
}

CString CString::Left(int n) const
{
	char* sResult = new char[n+1];
	strncpy_s(sResult, n+1, static_cast<const char *>(m_p),n);
	sResult[n] = '\0';
	CString newString(sResult);
	delete[] sResult;
	sResult = nullptr;
	return newString;
}

CString CString::Right(int n) const
{
	int iLen = Length();
	const char* sStart = static_cast<const char *>(m_p) + (iLen - n);
	return CString(sStart);
}

CString CString::Mid(int ofs, int n) const
{
	char* sResult = new char[n+1];
	strncpy_s(sResult, n+1, static_cast<const char*>(m_p) + ofs, n);
	sResult[n] = '\0';
	CString newString(sResult);
	delete[] sResult;
	sResult = nullptr;
	return CString(newString);
}

int CString::Find(const CString& str, int ofs) const
{
	const char* sFound = strstr(static_cast<const char *>(m_p)+ ofs, str.ToCString());
	return sFound ? static_cast<int>(sFound - static_cast<const char*>(m_p)) : -1;
}

CString CString::ToUpper() const
{
	CString sUpper(*this);

	for (int uIndex = 0; uIndex < sUpper.Length(); uIndex++)
	{
		sUpper[uIndex] = static_cast<char>(toupper(sUpper[uIndex]));
	}

	return sUpper;
}

CString CString::ToLower() const
{
	CString sLower(*this);

	for (int uIndex = 0; uIndex < sLower.Length(); uIndex++)
	{
		sLower[uIndex] = static_cast<char>(tolower(sLower[uIndex]));
	}

	return sLower;
}

CString CString::LTrim() const
{
	const char* sStart = static_cast<const char*>(m_p);
	while (isspace(*sStart))
	{
		++sStart;
	}

	return CString(sStart);
}

CString CString::RTrim() const
{
	int iLen = Length();
	while (iLen > 0 && isspace(static_cast<char*>(m_p)[iLen - 1]))
	{
		iLen--;
	}
	char* sResult = new char[iLen+1];
	strncpy_s(sResult, iLen+1, static_cast<const char*>(m_p), iLen);
	sResult[iLen] = '\0';
	CString newString(sResult);
	delete[] sResult;
	sResult = nullptr;
	return CString(newString);
}

CString CString::Trim() const
{
	return LTrim().RTrim();
}

CString CString::LSet(int len, char c) const
{
	if (Length() >= len)
	{
		return *this;
	}
	int iPatternLength = len - Length();
	char* sResult = new char[len +1];
	memset(sResult, c, iPatternLength);
	strcpy_s(sResult + iPatternLength, Length() + 1, static_cast<const char *>(m_p));
	CString newString(sResult);
	delete[]sResult;
	sResult = nullptr;
	return newString;
}

CString CString::RSet(int len, char c) const
{
	if (Length() >= len)
	{
		return *this;
	}
	char* sResult = new char[len + 1];

	strcpy_s(sResult, Length() + 1, static_cast<const char*>(m_p));
}
