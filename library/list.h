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

    List(const List& other) : List()
    {
        for (Node* current = other.head; current; current = current->next)
        {
            push_back(current->data);
        }
    }

    List(List&& other) : size(other.size), head(other.head), tail(other.tail)
    {
        other.size = 0;
        other.head = nullptr;
        other.tail = nullptr;
    }

    List(std::initializer_list<T> args) : List()
    {
        for (typename std::initializer_list<T>::const_iterator it = args.begin(); it != args.end(); ++it)
        {
            push_back(*it);
        }
    }

    ~List() { clear(); }

    void append(const T& value) { push_back(value); }

    void append(T&& value) { push_back(std::move(value)); }

    void append(const List<T>& value)
    {
        for (Node* current = value.head; current; current = current->next)
        {
            push_back(current->data);
        }
    }

    const T& at(const int& index) const
    {
        assert(index >= 0 && index < size && "List<T>::at" && "index out of range");
        return findNode(index)->data;
    }

    T& back() { return tail->data; }

    const T& back() const { return tail->data; }

    void clear()
    {
        while (size)
        {
            pop_front();
        }
    }

    const T& constFirst() const { return head->data; }

    const T& constLast() const { return tail->data; }

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

    int count() const { return size; }

    bool empty() const { return size == 0; }

    bool endsWith(const T& value) const { return size != 0 && tail->data == value; }

    T& first() { return head->data; }

    const T& first() const { return head->data; }

    T& front() { return head->data; }

    const T& front() const { return head->data; }

    int indexOf(const T& value, int from = 0) const
    {
        Node* current = findNode(from);
        while (current)
        {
            if (current->data == value)
            {
                return from;
            }
            current = current->next;
            ++from;
        }
        return -1;
    }

    void insert(const int& index, const T& value)
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
            Node* node = new Node(value, current, current->prev);
            current->prev->next = node;
            current->prev = node;
            ++size;
        }
    }

    void insert(const int& index, T&& value)
    {
        if (index <= 0)
        {
            push_front(std::move(value));
        }
        else if (index >= size)
        {
            push_back(std::move(value));
        }
        else
        {
            Node* current = findNode(index);
            Node* node = new Node(std::move(value), current, current->prev);
            current->prev->next = node;
            current->prev = node;
            ++size;
        }
    }

    bool isEmpty() const { return size == 0; }

    T& last() { return tail->data; }

    const T& last() const { return tail->data; }

    int lastIndexOf(const T& value, int from = -1) const
    {
        if (from == -1)
        {
            from = size - 1;
            for (Node* current = tail; current; current = current->prev, --from)
            {
                if (current->data == value)
                {
                    return from;
                }
            }
        }
        else
        {
            for (Node* current = findNode(from); current; current = current->prev, --from)
            {
                if (current->data == value)
                {
                    return from;
                }
            }
        }
        return -1;
    }

    int length() const { return size; }

    List<T> mid(int pos, int length = -1) const
    {
        Node* current = findNode(pos);
        if (!current)
            return {};

        List<T> temp;
        if (length == -1)
        {
            while (current)
            {
                temp.push_back(current->data);
                current = current->next;
            }
        }
        else
        {
            while (current && length > 0)
            {
                temp.push_back(current->data);
                current = current->next;
                --length;
            }
        }
        return temp;
    }

    void pop_back()
    {
        assert(!isEmpty() && "the list is empty");
        Node* temp = tail;
        tail = tail->prev;
        delete temp;
        temp = nullptr;
        --size;
    }

    void pop_front()
    {
        assert(!isEmpty() && "the list is empty");
        Node* temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
        --size;
    }

    void prepend(const T& value) { push_front(value); }

    void prepend(T&& value) { push_front(std::move(value)); }

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

    int removeAll(const T& value)
    {
        Node* current = head;
        int count = 0;
        bool isNoStep;
        while (current)
        {
            isNoStep = true;
            if (current->data == value)
            {
                if (current == head)
                {
                    current = current->next;
                    pop_front();
                }
                else if (current == tail)
                {
                    current = current->next;
                    pop_back();
                }
                else
                {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    Node* temp = current;
                    current = current->next;
                    delete temp;
                    temp = nullptr;
                    --size;
                }
                isNoStep = false;
                ++count;
            }
            if (isNoStep)
            {
                current = current->next;
            }
        }
        return count;
    }

    void removeAt(const int& index)
    {
        if (index < 0 || index >= size)
            return;

        Node* current = findNode(index);
        if (current == head)
        {
            pop_front();
        }
        else if (current == tail)
        {
            pop_back();
        }
        else
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            current = nullptr;
            --size;
        }
    }

    void removeFirst() { pop_front(); }

    void removeLast() { pop_back(); }

    bool removeOne(const T& value)
    {
        Node* current = head;
        while (current)
        {
            if (current->data == value)
            {
                if (current == head)
                {
                    pop_front();
                }
                else if (current == tail)
                {
                    pop_back();
                }
                else
                {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    delete current;
                    current = nullptr;
                    --size;
                }
                return true;
            }
            current = current->next;
        }
        return false;
    }

    //==================================

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
