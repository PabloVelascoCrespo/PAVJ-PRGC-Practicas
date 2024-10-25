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

TList::TList(TList& lOriginal) : nHead(nullptr), nCurrent(nullptr), iSize(0)
{
    Node* nTemp = lOriginal.nHead;
    while (nTemp)
    {
        this->Push(nTemp->sData);
        nTemp = nTemp->nNext;
    }
}

TList& TList::operator=(const TList& lOriginal)
{
    if (this != &lOriginal) {
        this->Reset();

        Node* temp = lOriginal.nHead;
        while (temp) {
            this->Push(temp->sData);
            temp = temp->nNext;
        }
    }
    return *this;
}

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
    nCurrent = nHead;
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

TList TList::GetReversedList()
{
    TList lReversed;

    const char* sElem = this->First();
    while (sElem)
    {
        TList::Node* nNuevoNodo = new TList::Node(sElem);
        nNuevoNodo->nNext = lReversed.nHead;
        lReversed.nHead = nNuevoNodo;
        lReversed.iSize++;

        sElem = this->Next();
    }
    return lReversed;
}
