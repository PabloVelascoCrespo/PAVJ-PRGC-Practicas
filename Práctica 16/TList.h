#pragma once

#include "IStorable.h"
#include <iostream>

class TList
{
private:
    struct Node
    {
        IStorable* m_pData;
        Node* m_tNext;

        Node(const IStorable& _pElement) 
            : m_pData(_pElement.Clone())
            , m_tNext(nullptr) 
        {
        }

        ~Node() { delete m_pData; }
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

    TList(const TList& other) 
        : m_tHead(nullptr)
        , m_tCurrent(nullptr),
        m_iSize(0)
    {
        Node* temp = other.m_tHead;
        while (temp)
        {
            this->Push(*(temp->m_pData));
            temp = temp->m_tNext;
        }
    }

    TList& operator=(const TList& lOriginal)
    {
        if (this != &lOriginal)
        {
            Reset();
            
            Node* temp = lOriginal.m_tHead;
            while (temp)
            {
                this->Push(*(temp->m_pData));
                temp = temp->m_tNext;
            }
        }
        return *this;
    }

    ~TList()
    {
        Reset();
    }

    void Push(const IStorable& _pElement)
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
        m_tCurrent = m_tHead;
        m_iSize++;
    }

    int Size() const 
    {
        return m_iSize;
    }


    const IStorable* First() 
    {
        m_tCurrent = m_tHead;
        if (m_tCurrent)
        {
            return m_tCurrent->m_pData;
        }
        return nullptr;
    }

    const IStorable* Next() 
    {
        if (m_tCurrent && m_tCurrent->m_tNext) 
        {
            m_tCurrent = m_tCurrent->m_tNext;
            return m_tCurrent->m_pData;
        }
        return nullptr;
    }

    IStorable* Pop() 
    {
        if (!m_tHead) 
        {
            return nullptr;
        }

        Node* temp = m_tHead;
        IStorable* dataCopy = temp->m_pData->Clone();

        m_tHead = m_tHead->m_tNext;
        delete temp;
        m_iSize--;

        return dataCopy;
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
            Node* newNode = new Node(*(temp->m_pData));
            newNode->m_tNext = reversedList.m_tHead;
            reversedList.m_tHead = newNode;
            reversedList.m_iSize++;

            temp = temp->m_tNext;
        }
        return reversedList;
    }
};