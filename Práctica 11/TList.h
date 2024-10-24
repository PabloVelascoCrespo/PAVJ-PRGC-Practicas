#pragma once

class TList
{
private:
    struct Node
    {
        char* sData;
        Node* nNext;
        Node(const char* psz);
        ~Node();
    };

    Node* nHead;
    Node* nCurrent;
    int iSize;

public:
    TList();
    TList(TList &lOriginal);
    ~TList();

    int Size() const;
    int Push(const char* psz);
    const char* First();
    const char* Next();
    const char* Pop();
    void Reset();
    TList GetReversedList(TList &lOriginal);
};
#pragma once
