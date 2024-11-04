#pragma once


#include <iostream>

template <typename T>
class TList 
{
private:
    struct Node 
    {
        T m_tData;
        Node* m_tNext;

        Node(const T& _m_tData)
            : m_tData(_m_tData),
            m_tNext(nullptr) 
        {
        }
    };

    Node* m_tHead;
    Node* m_tCurrent;
    int m_iSize;

public:
    TList() 
        : m_tHead(nullptr)
        , m_tCurrent(nullptr)
        , m_iSize(0) 
    {
    }

    TList(const TList& _lOriginal)
        : m_tHead(nullptr)
        , m_tCurrent(nullptr)
        , m_iSize(0) 
    {
        Node* temp = _lOriginal.m_tHead;
        while (temp) 
        {
            this->Push(temp->m_tData);
            temp = temp->m_tNext;
        }
    }

    TList& operator=(const TList& _lOriginal)
    {
        if (this != &_lOriginal)
        {
            Reset();

            Node* temp = _lOriginal.m_tHead;
            while (temp) 
            {
                this->Push(temp->m_tData);
                temp = temp->m_tNext;
            }
        }
        return *this;
    }

    ~TList()
    {
        Reset();
    }

    void Push(const T& _pElement)
    {
        Node* newNode = new Node(_pElement);

        if (!m_tHead) 
        {
            m_tHead = newNode;
        }
        else 
        {
            Node* temp = m_tHead;
            while (temp->m_tNext) 
            {
                temp = temp->m_tNext;
            }
            temp->m_tNext = newNode;
        }
        m_iSize++;
    }

    int Size() const 
    {
        return m_iSize;
    }

    const T* First() 
    {
        m_tCurrent = m_tHead;
        if (m_tCurrent)
        {
            return &(m_tCurrent->m_tData);
        }
        return nullptr;
    }

    const T* Next() 
    {
        if (m_tCurrent && m_tCurrent->m_tNext) 
        {
            m_tCurrent = m_tCurrent->m_tNext;
            return &(m_tCurrent->m_tData);
        }
        return nullptr;
    }

    T Pop() 
    {
        if (!m_tHead) 
        {
            throw std::out_of_range("La lista está vacía.");
        }

        Node* temp = m_tHead;
        T m_tDataCopy = temp->m_tData;

        m_tHead = m_tHead->m_tNext;
        delete temp;
        m_iSize--;

        return m_tDataCopy;
    }

    void Reset() 
    {
        while (m_tHead) 
        {
            Pop();
        }
        m_tCurrent = nullptr;
    }

    TList GetReversedList() const 
    {
        TList reversedList;

        Node* temp = m_tHead;
        while (temp) 
        {
            Node* newNode = new Node(temp->m_tData);
            newNode->m_tNext = reversedList.m_tHead;
            reversedList.m_tHead = newNode;
            reversedList.m_iSize++;

            temp = temp->m_tNext;
        }

        return reversedList;
    }
};