#include <iostream>
#include <stdexcept>

template <class T>
class LinkedList 
{
private:
    struct Node 
    {
        T data;
        Node* next;

        Node(T data, Node* next = nullptr) : data(data), next(next) {}
    };

    Node* head;
    Node* tail;
    int length;

public:
    LinkedList() : head(nullptr), tail(nullptr), length(0) {}

    LinkedList(T* items, int count) : head(nullptr), tail(nullptr), length(0) 
    {
        for (int i = 0; i < count; ++i) 
        {
            Append(items[i]);
        }
    }

    LinkedList(const LinkedList<T>& list) : head(nullptr), tail(nullptr), length(0) 
    {
        Node* current = list.head;

        while (current != nullptr) 
        {
            Append(current->data);
            current = current->next;
        }
    }

    T GetFirst() 
    {
        if (length == 0) 
        {
            throw std::out_of_range("IndexOutOfRange");
        }

        return head->data;
    }

    T GetLast() 
    {
        if (length == 0) 
        {
            throw std::out_of_range("IndexOutOfRange");
        }

        return tail->data;
    }

    T Get(int index) 
    {
        if (index < 0 || index >= length) 
        {
            throw std::out_of_range("IndexOutOfRange");
        }

        Node* current = head;

        for (int i = 0; i < index; ++i) 
        {
            current = current->next;
        }

        return current->data;
    }

    LinkedList<T>* GetSubList(int startIndex, int endIndex) 
    {
        if (startIndex < 0 || endIndex >= length || startIndex > endIndex) 
        {
            throw std::out_of_range("IndexOutOfRange");
        }

        LinkedList<T>* sublist = new LinkedList<T>();
        Node* current = head;

        for (int i = 0; i <= endIndex; ++i) 
        {
            if (i >= startIndex) 
            {
                sublist->Append(current->data);
            }

            current = current->next;
        }

        return sublist;
    }

    int GetLength() 
    {
        return length;
    }

    void Append(T item)
    {
        Node* newNode = new Node(item);

        if (length == 0) 
        {
            head = tail = newNode;
        }
        else 
        {
            tail->next = newNode;
            tail = newNode;
        }

        length++;
    }

    void Prepend(T item) 
    {
        Node* newNode = new Node(item, head);

        if (length == 0) 
        {
            head = tail = newNode;
        }
        else 
        {
            head = newNode;
        }

        length++;
    }

    void InsertAt(T item, int index) 
    {
        if (index < 0 || index > length) 
        {
            throw std::out_of_range("IndexOutOfRange");
        }

        if (index == 0) 
        {
            Prepend(item);
        }
        else if (index == length) 
        {
            Append(item);
        }
        else 
        {
            Node* current = head;

            for (int i = 0; i < index - 1; ++i) 
            {
                current = current->next;
            }

            Node* newNode = new Node(item, current->next);
            current->next = newNode;
            length++;
        }
    }

    LinkedList<T>* Concat(LinkedList<T>* list) 
    {
        LinkedList<T>* newList = new LinkedList<T>(*this);
        Node* current = list->head;

        while (current != nullptr) 
        {
            newList->Append(current->data);
            current = current->next;
        }

        return newList;
    }
};