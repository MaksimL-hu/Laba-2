#include <iostream>
#include <stdexcept>

template <class T> class ArraySequence;
template <class T> class ListSequence;

template <class T>
class Sequence {
public:
    virtual T GetFirst() = 0;
    virtual T GetLast() = 0;
    virtual T Get(int index) = 0;
    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) = 0;
    virtual int GetLength() = 0;
    virtual Sequence<T>* Append(T item) = 0;
    virtual Sequence<T>* Prepend(T item) = 0;
    virtual Sequence<T>* InsertAt(T item, int index) = 0;
    virtual Sequence<T>* Concat(Sequence<T>* list) = 0;
    virtual ~Sequence() {}
};

template <class T>
class ArraySequence : public Sequence<T> 
{
private:
    DynamicArray<T> array;

public:
    ArraySequence(T* items, int count) : array(items, count) {}
    ArraySequence() : array(0) {}
    ArraySequence(const DynamicArray<T>& dynamicArray) : array(dynamicArray) {}

    T GetFirst() override 
    {
        if (array.GetSize() == 0) 
        {
            throw std::out_of_range("IndexOutOfRange");
        }

        return array.Get(0);
    }

    T GetLast() override 
    {
        if (array.GetSize() == 0) 
        {
            throw std::out_of_range("IndexOutOfRange");
        }

        return array.Get(array.GetSize() - 1);
    }

    T Get(int index) override 
    {
        return array.Get(index);
    }

    ArraySequence<T>* GetSubsequence(int startIndex, int endIndex) override 
    {
        if (startIndex < 0 || endIndex >= array.GetSize() || startIndex > endIndex) 
        {
            throw std::out_of_range("IndexOutOfRange");
        }

        int newLength = endIndex - startIndex + 1;
        T* newItems = new T[newLength];

        for (int i = 0; i < newLength; ++i) 
        {
            newItems[i] = array.Get(startIndex + i);
        }

        return new ArraySequence<T>(newItems, newLength);
    }

    int GetLength() override 
    {
        return array.GetSize();
    }

    ArraySequence<T>* Append(T item) override 
    {
        array.Resize(array.GetSize() + 1);
        array.Set(array.GetSize() - 1, item);

        return this;
    }

    ArraySequence<T>* Prepend(T item) override 
    {
        array.Resize(array.GetSize() + 1);

        for (int i = array.GetSize() - 1; i > 0; --i) 
        {
            array.Set(i, array.Get(i - 1));
        }

        array.Set(0, item);

        return this;
    }

    ArraySequence<T>* InsertAt(T item, int index) override 
    {
        if (index < 0 || index > array.GetSize()) 
        {
            throw std::out_of_range("IndexOutOfRange");
        }

        array.Resize(array.GetSize() + 1);

        for (int i = array.GetSize() - 1; i > index; --i) 
        {
            array.Set(i, array.Get(i - 1));
        }

        array.Set(index, item);

        return this;
    }

    ArraySequence<T>* Concat(Sequence<T>* list) override 
    {
        ArraySequence<T>* newSequence = new ArraySequence<T>();

        for (int i = 0; i < this->GetLength(); ++i) 
        {
            newSequence->Append(this->Get(i));
        }

        for (int i = 0; i < list->GetLength(); ++i) 
        {
            newSequence->Append(list->Get(i));
        }

        return newSequence;
    }
};

template <class T>
class ListSequence : public Sequence<T> 
{
private:
    LinkedList<T> list;

public:
    ListSequence(T* items, int count) : list(items, count) {}
    ListSequence() : list() {}
    ListSequence(const LinkedList<T>& linkedList) : list(linkedList) {}

    T GetFirst() override 
    {
        if (list.GetLength() == 0) 
        {
            throw std::out_of_range("IndexOutOfRange");
        }

        return list.GetFirst();
    }

    T GetLast() override 
    {
        if (list.GetLength() == 0) 
        {
            throw std::out_of_range("IndexOutOfRange");
        }

        return list.GetLast();
    }

    T Get(int index) override 
    {
        return list.Get(index);
    }

    ListSequence<T>* GetSubsequence(int startIndex, int endIndex) override 
    {
        LinkedList<T>* sublist = list.GetSubList(startIndex, endIndex);
        return new ListSequence<T>(*sublist);
    }

    int GetLength() override 
    {
        return list.GetLength();
    }

    ListSequence<T>* Append(T item) override 
    {
        list.Append(item);

        return this;
    }

    ListSequence<T>* Prepend(T item) override 
    {
        list.Prepend(item);

        return this;
    }

    ListSequence<T>* InsertAt(T item, int index) override 
    {
        list.InsertAt(item, index);

        return this;
    }

    ListSequence<T>* Concat(Sequence<T>* sequence) override
    {
        ListSequence<T>* newList = new ListSequence<T>(list);

        for (int i = 0; i < sequence->GetLength(); ++i) 
        {
            newList->Append(sequence->Get(i));
        }

        return newList;
    }
};