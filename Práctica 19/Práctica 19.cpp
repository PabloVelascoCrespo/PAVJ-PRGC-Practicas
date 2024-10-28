#include <iostream>

class CCounter
{
	int iCounter = 0;
	int iWeaks = 0;
};

template <typename T>
class CUniquePtr
{
public:
	CUniquePtr(T* _pPtr)
		: m_pPtr(_pPtr)
	{
	}
	~CUniquePtr()
	{
		delete m_pPtr;
		m_pPtr = nullptr;
	}
	CUniquePtr& operator =(T* _pPtr) =  delete;

	T& operator*() { return *m_pPtr; }
	T* operator->() { return m_pPtr; }
private:
	T* m_pPtr = nullptr;
};

template <typename T>
class CSharedPtr
{
	explicit CSharedPtr(T* _pPtr)
		: m_pPtr(_pPtr)
	{
		m_pCounter = new cCounter();
		if (m_pPtr)
		{
			m_pCounter.iCounter++;
		}
	}
	explicit CSharedPtr(const CSharedPtr<T>& _rOther)
		: m_pPtr(_rOther)
		, m_pCounter(_rOther.m_pCounter)
	{
		m_pCounter = new cCounter();
		if (m_pPtr)
		{
			m_pCounter.iCounter++;
		}
	}

	~CSharedPtr()
	{
		m_pCounter->iCounter--;
		if (m_pCounter->iCounter == 0)
		{
			delete m_pPtr;
			delete m_pCounter;
		}
	}
	T* Get() { return m_pPtr; }
	unsigned int GetCount() const { return m_pCounter->iCounter; }

private:
	T* m_pPtr;
	CCounter* m_pCounter = nullptr;

};

int main()
{

}