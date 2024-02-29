#pragma once

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

template <class T>
class DLList
{
    struct Node
    {
        Node *prev;
        Node *next;
        T value;

        Node(T v) : prev(nullptr), next(nullptr), value(v) {}
    };

    Node *head;
    Node *tail;
    size_t _size;

    void _clear(Node *&node)
    {
        if (node != nullptr)
        {
            _clear(node->next);
            delete node;
            node = nullptr;
        }
    }

public:
    DLList() : head(nullptr), tail(nullptr), _size(0) {}

    ~DLList()
    {
        clear();
    }

    size_t size() const
    {
        return _size;
    }

    void clear()
    {
        _clear(head);
        tail = nullptr;
        _size = 0;
    }

    const Node *get_head() const
    {
        return head;
    }

    const Node* get_tail() const {
        return tail;
    }

    void push_front(T item)
    {
        Node *new_node = new Node(item);
        new_node->next = head;
        if (head == nullptr)
        {
            tail = new_node;
        }
        else
        {
            head->prev = new_node;
        }
        head = new_node;
        _size++;
    }

    void push_back(T item)
    {
        Node *new_node = new Node(item);
        new_node->prev = tail;
        if (tail == nullptr)
        {
            head = new_node;
        }
        else
        {
            tail->next = new_node;
        }
        tail = new_node;
        _size++;
    }

    void insert(T item, int position)
    {
        if (position > len)
        {
            throw std::out_of_range("index is out of range");
        }

        if (position == 0)
        {
            push_front(item);
            return;
        }

        if (position == len)
        {
            push_back(item);
            return;
        }

        Node *to_insert_at = head;
        while (position != 0)
        {
            to_insert_at = to_insert_at->next;
            position--;
        }
        Node *before_to_insert_at = to_insert_at->prev;

        Node *new_node = new Node(item);
        new_node->prev = before_to_insert_at;
        new_node->next = to_insert_at;

        to_insert_at->prev = new_node;
        before_to_insert_at->next = new_node;

        len += 1;
    }

    void pop_front()
    {
        if (head == nullptr)
        {
            throw std::length_error("the list is empty");
        }

        Node *after_to_remove = head->next;

        if (after_to_remove == nullptr)
        {
            tail = nullptr;
        }
        else
        {
            after_to_remove->prev = nullptr;
        }

        delete head;
        head = after_to_remove;
        len -= 1;
    }
    void pop_back()
    {
        if (tail == nullptr)
        {
            throw std::length_error("the list is empty");
        }

        Node *before_to_remove = tail->prev;

        if (before_to_remove == nullptr)
        {
            head = nullptr;
        }
        else
        {
            before_to_remove->next = nullptr;
        }

        delete tail;
        tail = before_to_remove;
        len -= 1;
    }

    void remove(int position)
    {
        if (position >= len)
        {
            throw std::out_of_range("index is out of range");
        }

        Node *to_remove = head;
        while (position != 0)
        {
            to_remove = to_remove->next;
            position--;
        }

        Node *before_to_remove = to_remove->prev;
        Node *after_to_remove = to_remove->next;

        if (before_to_remove == nullptr)
        {
            head = after_to_remove;
        }
        else
        {
            before_to_remove->next = after_to_remove;
        }

        if (after_to_remove == nullptr)
        {
            tail = before_to_remove;
        }
        else
        {
            after_to_remove->prev = before_to_remove;
        }

        delete to_remove;
        len -= 1;
    }

    const T &front() const
    {
        if (head == nullptr)
        {
            throw std::length_error("the list is empty");
        }
        return head->value;
    }

    const T &back() const
    {
        if (tail == nullptr)
        {
            throw std::length_error("the list is empty");
        }
        return tail->value;
    }
    const T &at(int index) const
    {
        if (index >= len)
        {
            throw std::out_of_range("index is out of range");
        }

        Node *node = head;
        while (index != 0)
        {
            node = node->next;
            index--;
        }
        return node->value;
    }

    bool contains(const T &item) const
    {
        Node *node = head;
        while (node != nullptr)
        {
            if (node->value == item)
            {
                return true;
            }
            node = node->next;
        }
        return false;
    }

    int size() const
    {
        return len;
    }

    void clear()
    {
        Node *node = head;
        while (node != nullptr)
        {
            Node *next = node->next;
            delete node;
            node = next;
        }
        head = nullptr;
        tail = nullptr;
        len = 0;
    }
};
