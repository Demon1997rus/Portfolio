#ifndef LIST_H
#define LIST_H

#include <cassert>

namespace Containers
{
template <class T>
class List
{
private:
    class Node
    {
    public:
        Node(T data = T(), Node* next = nullptr, Node* prev = nullptr)
        {
            this->data = data;
            this->next = next;
            this->prev = prev;
        }
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
            for (current = head, currentIndex = 0; current; current = current->next, ++currentIndex)
            {
                if (index == currentIndex)
                {
                    return current;
                }
            }
        }
        else
        {
            for (current = tail, currentIndex = size - 1; current; current = current->prev, --currentIndex)
            {
                if (index == currentIndex)
                {
                    return current;
                }
            }
        }
        return current;
    }

public:
    List()
    {
        size = 0;
        head = tail = nullptr;
    }

    List(int size) : List(size, T())
    {
    }

    List(int size, const T& value) : List()
    {
        for (int i = 0; i < size; ++i)
        {
            push_back(value);
        }
    }

    ~List()
    {
        clear();
    }

    int count() const
    {
        return size;
    }

    int count(const T& value) const
    {
        int count = 0;
        for (Node* current = head; current; current = current->next)
        {
            if (current->data == value)
            {
                ++count;
            }
        }
        return count;
    }

    void push_back(T value)
    {
        if (size++)
        {
            tail->next = new Node(value, nullptr, tail);
            tail = tail->next;
        }
        else
        {
            head = new Node(value);
            tail = head;
        }
    }

    void push_front(T value)
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

    T& operator[](int index)
    {
        assert(index >= 0 && index < size && "List<T>::operator[]" && "index out of range");
        return findNode(index)->data;
    }

    T at(int index) const
    {
        assert(index >= 0 && index < size && "List<T>::at" && "index out of range");
        return findNode(index)->data;
    }

    void pop_front()
    {
        if (!head)
            return;
        Node* temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
        --size;
    }

    void pop_back()
    {
        if (!tail)
            return;
        Node* temp = tail;
        tail = tail->prev;
        delete temp;
        temp = nullptr;
        --size;
    }

    void clear()
    {
        while (size)
            pop_front();
    }

    void insert(int index, const T& value)
    {
        if (index <= 0)
        {
            push_front(value);
        }
        else if (index >= size)
        {
            push_back(value);
        }
        else
        {
            Node* current = findNode(index);
            Node* prev = current->prev;
            Node* node = new Node(value, current, prev);
            current->prev = node;
            prev->next = node;
            ++size;
        }
    }

    bool contains(const T& value) const
    {
        for (Node* current = head; current; current = current->next)
        {
            if (current->data == value)
            {
                return true;
            }
        }
        return false;
    }

    bool empty() const
    {
        return size == 0;
    }

    void removeAt(int index)
    {
        assert(index >= 0 && index < size && "List<T>::removeAt" && "index out of range");
        if (index == 0)
        {
            pop_front();
        }
        else if (index + 1 == size)
        {
            pop_back();
        }
        else
        {
            Node* candidate = findNode(index);
            candidate->prev->next = candidate->next;
            candidate->next->prev = candidate->prev;
            delete candidate;
            candidate = nullptr;
            --size;
        }
    }
};

}  // namespace Containers

#endif  // LIST_H
