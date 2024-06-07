#include <iostream>
#include <stdexcept>
#include "DynamicArray.h"
#include "LinkedList.h"
#include "Sequence.h" 

using namespace std;

void TestDynamicArray() 
{
    cout << "Testing DynamicArray..." << endl;

    try 
    {
        int items[] = { 1, 2, 3, 4, 5 };
        DynamicArray<int> arr(items, 5);
        cout << "Initialization: ";

        for (int i = 0; i < 5; ++i) 
        {
            if (arr.Get(i) != items[i]) 
            { 
                throw logic_error("Initialization failed"); 
            }
        }
         
        cout << "Passed" << endl;
        cout << "Get/Set: ";

        for (int i = 0; i < 5; ++i)
        {
            arr.Set(i, i * 2);

            if (arr.Get(i) != i * 2)
            { 
                throw logic_error("Get/Set failed");
            }
        }

        cout << "Passed" << endl;
        cout << "Resize: ";

        arr.Resize(7);

        if (arr.GetSize() != 7) 
        {
            throw logic_error("Resize failed");
        }

        arr.Resize(3);

        if (arr.GetSize() != 3) 
        {
            throw logic_error("Resize failed");
        }

        cout << "Passed" << endl;

    }
    catch (const exception& e) 
    {
        cout << "Failed: " << e.what() << endl;
    }
}

void TestLinkedList() 
{
    cout << "Testing LinkedList..." << endl;

    try {
        int items[] = { 1, 2, 3, 4, 5 };
        LinkedList<int> list(items, 5);

        cout << "Initialization: ";

        for (int i = 0; i < 5; ++i) 
        {
            if (list.Get(i) != items[i]) 
            {
                throw logic_error("Initialization failed");
            }
        }

        cout << "Passed" << endl;
        cout << "Append/Prepend: ";

        list.Append(6);
        list.Prepend(0);

        if (list.Get(0) != 0 || list.Get(6) != 6) 
        {
            throw logic_error("Append/Prepend failed");
        }

        cout << "Passed" << endl;
        cout << "InsertAt: ";

        list.InsertAt(3, 1);

        if (list.Get(1) != 3) 
        {
            throw logic_error("InsertAt failed");
        }

        cout << "Passed" << endl;
        cout << "SubList: ";

        LinkedList<int>* sublist = list.GetSubList(1, 3);

        if (sublist->Get(0) != 3 || sublist->Get(1) != 1 || sublist->Get(2) != 2) 
        {
            throw logic_error("SubList failed");
        }

        delete sublist;

        cout << "Passed" << endl;

    }
    catch (const exception& e) 
    {
        cout << "Failed: " << e.what() << endl;
    }
}

void TestArraySequence() 
{
    cout << "Testing ArraySequence..." << endl;

    try {
        int items[] = { 1, 2, 3, 4, 5 };
        ArraySequence<int> seq(items, 5);

        cout << "Initialization: ";

        for (int i = 0; i < 5; ++i) 
        {
            if (seq.Get(i) != items[i]) 
            {
                throw logic_error("Initialization failed");
            }
        }

        cout << "Passed" << endl;
        cout << "Append/Prepend: ";

        seq.Append(6);
        seq.Prepend(0);

        if (seq.Get(0) != 0 || seq.Get(6) != 6) 
        {
            throw logic_error("Append/Prepend failed");
        }

        cout << "Passed" << endl;
        cout << "InsertAt: ";

        seq.InsertAt(3, 1);

        if (seq.Get(1) != 3) 
        {
            throw logic_error("InsertAt failed");
        }

        cout << "Passed" << endl;
        cout << "Subsequence: ";

        ArraySequence<int>* subseq = seq.GetSubsequence(1, 3);

        if (subseq->Get(0) != 3 || subseq->Get(1) != 1 || subseq->Get(2) != 2) 
        {
            throw logic_error("Subsequence failed");
        }

        delete subseq;

        cout << "Passed" << endl;

    }
    catch (const exception& e) 
    {
        cout << "Failed: " << e.what() << endl;
    }
}

void TestListSequence() 
{
    cout << "Testing ListSequence..." << endl;

    try {
        int items[] = { 1, 2, 3, 4, 5 };
        ListSequence<int> seq(items, 5);

        cout << "Initialization: ";

        for (int i = 0; i < 5; ++i) 
        {
            if (seq.Get(i) != items[i]) 
            {
                throw logic_error("Initialization failed");
            }
        }

        cout << "Passed" << endl;
        cout << "Append/Prepend: ";

        seq.Append(6);
        seq.Prepend(0);

        if (seq.Get(0) != 0 || seq.Get(6) != 6) 
        {
            throw logic_error("Append/Prepend failed");
        }

        cout << "Passed" << endl;
        cout << "InsertAt: ";

        seq.InsertAt(3, 1);

        if (seq.Get(1) != 3)
        {
            throw logic_error("Append/Prepend failed");
        }

        cout << "Passed" << endl;
        cout << "Subsequence: ";

        ListSequence<int>* subseq = seq.GetSubsequence(1, 3);

        if (subseq->Get(0) != 3 || subseq->Get(1) != 1 || subseq->Get(2) != 2) 
        {
            throw logic_error("Subsequence failed");
        }

        delete subseq;

        cout << "Passed" << endl;

    }
    catch (const exception& e) 
    {
        cout << "Failed: " << e.what() << endl;
    }
}

int StartTests() {
    TestDynamicArray();
    cout << "TestDynamicArray passed\n" << endl;

    TestLinkedList();
    cout << "TestLinkedList passed\n" << endl;

    TestArraySequence();
    cout << "TestArraySequence passed\n" << endl;

    TestListSequence();
    cout << "TestListSequence passed\n" << endl;

    return 0;
}