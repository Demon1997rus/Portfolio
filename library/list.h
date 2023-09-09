#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cassert>

using namespace std;

namespace Containers
{
template <class T>
class List
{
private:
    class Node
    {
    public:
        Node(const T& d, Node* n = nullptr, Node* p = nullptr) : data(d), next(n), prev(p) {}
        Node(T&& d = T(), Node* n = nullptr, Node* p = nullptr) : data(std::move(d)), next(n), prev(p) {}
        T data;
        Node* next;
        Node* prev;
    };
    int size;
    Node* head;
    Node* tail;

    Node* findNode(const int& index) const
    {
        Node* current = nullptr;
        int currentIndex;
        if (size / 2 > index)
        {
            current = head;
            currentIndex = 0;
            while (current)
            {
                if (index == currentIndex)
                {
                    return current;
                }
                current = current->next;
                ++currentIndex;
            }
        }
        else
        {
            current = tail;
            currentIndex = size - 1;
            while (current)
            {
                if (index == currentIndex)
                {
                    return current;
                }
                current = current->prev;
                --currentIndex;
            }
        }
        return current;
    }

public:
    List() : size(0), head(nullptr), tail(nullptr) {}

    int count() const { return size; }

    void push_back(const T& value)
    {
        if (size++)
        {
            tail->next = new Node(value, nullptr, tail);
            tail = tail->next;
        }
        else
        {
            tail = new Node(value);
            head = tail;
        }
    }

    void push_back(T&& value)
    {
        if (size++)
        {
            tail->next = new Node(std::move(value), nullptr, tail);
            tail = tail->next;
        }
        else
        {
            tail = new Node(std::move(value));
            head = tail;
        }
    }

    void push_front(const T& value)
    {
        if (size++)
        {
            head->prev = new Node(value, head);
            head = head->prev;
        }
        else
        {
            head = new Node(value);
            tail = head;
        }
    }

    void push_front(T&& value)
    {
        if (size++)
        {
            head->prev = new Node(std::move(value), head);
            head = head->prev;
        }
        else
        {
            head = new Node(std::move(value));
            tail = head;
        }
    }

    const T& at(const int& index) const
    {
        assert(index >= 0 && index < size && "List<T>::at" && "index out of range");
        return findNode(index)->data;
    }

    T& operator[](const int& index)
    {
        assert(index >= 0 && index < size && "List<T>::operator[]" && "index out of range");
        return findNode(index)->data;
    }

    const T& operator[](const int& index) const
    {
        assert(index >= 0 && index < size && "List<T>::operator[]" && "index out of range");
        return findNode(index)->data;
    }
};
}  // namespace Containers

#endif  // LIST_H
