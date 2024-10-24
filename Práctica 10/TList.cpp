#include "TList.h"
#include <iostream>

TList::Node::Node(const char* psz)
{
    size_t len = strlen(psz) + 1;
    sData = new char[len];
    strcpy_s(sData, len, psz);
    nNext = nullptr;
}

TList::Node::~Node()
{
    delete[] sData;
}

TList::TList() : nHead(nullptr), nCurrent(nullptr), iSize(0) {}

TList::~TList()
{
    Reset();
}

int TList::Size() const
{
    return iSize;
}

int TList::Push(const char* psz)
{
    Node* newNode = new Node(psz);

    if (!nHead)
    {
        nHead = newNode;
    }
    else
    {
        Node* temp = nHead;
        while (temp->nNext)
        {
            temp = temp->nNext;
        }
        temp->nNext = newNode;
    }

    iSize++;
    return iSize;
}

const char* TList::First()
{
    nCurrent = nHead;
    if (nCurrent)
    {
        return nCurrent->sData;
    }
    return nullptr;
}

const char* TList::Next()
{
    if (nCurrent && nCurrent->nNext)
    {
        nCurrent = nCurrent->nNext;
        return nCurrent->sData;
    }
    return nullptr;
}

const char* TList::Pop()
{
    if (!nHead)
    {
        return nullptr;
    }

    Node* temp = nHead;

    size_t len = strlen(temp->sData) + 1;
    char* dataCopy = new char[len];
    strcpy_s(dataCopy, len, temp->sData);

    nHead = nHead->nNext;
    delete temp;

    iSize--;

    return dataCopy;
}

void TList::Reset()
{
    while (nHead)
    {
        Pop();
    }
    nCurrent = nullptr;
}
