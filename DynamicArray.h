#include <iostream>
#include <stdexcept>

template <class T>
class DynamicArray 
{
private:
    T* data;
    int size;

public:
    DynamicArray(T* items, int count) 
    {
        size = count;
        data = new T[size];

        for (int i = 0; i < size; ++i) 
        {
            data[i] = items[i];
        }
    }

    DynamicArray(int size) 
    {
        this->size = size;
        data = new T[size];
    }

    DynamicArray(const DynamicArray<T>& dynamicArray) 
    {
        size = dynamicArray.size;
        data = new T[size];

        for (int i = 0; i < size; ++i) 
        {
            data[i] = dynamicArray.data[i];
        }
    }

    T Get(int index) 
    {
        if (index < 0 || index >= size) 
        {
            throw std::out_of_range("IndexOutOfRange");
        }

        return data[index];
    }

    int GetSize() 
    {
        return size;
    }

    void Set(int index, T value) 
    {
        if (index < 0 || index >= size) 
        {
            throw std::out_of_range("IndexOutOfRange");
        }

        data[index] = value;
    }

    void Resize(int newSize) 
    {
        T* newData = new T[newSize];
        int minSize = (newSize < size) ? newSize : size;

        for (int i = 0; i < minSize; ++i) 
        {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        size = newSize;
    }
};