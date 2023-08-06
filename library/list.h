#ifndef LIST_H
#define LIST_H

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
        this->size = 0;
        head = tail = nullptr;
    }

    int count() const
    {
        return size;
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

    T& operator[](const int& index)
    {
        return findNode(index)->data;
    }

    T at(const int& index) const
    {
        return findNode(index)->data;
    }
};

}  // namespace Containers

#endif  // LIST_H
