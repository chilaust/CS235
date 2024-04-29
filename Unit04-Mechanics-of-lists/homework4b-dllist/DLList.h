#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

template<class T>
class DLList {
public:
    struct Node {
        Node* prev;
        Node* next;
        T value;

        Node(T v, Node * next = nullptr, Node * prev = nullptr) : prev(prev), next(next), value(v) {}
    };

    DLList() :m_head(nullptr), m_tail(nullptr), m_size(0) {}

    ~DLList() {
        clear();
    }

    const Node* get_head() const {
        // implement get_head here
        return m_head;
    }

    void push_front(T item) {
        m_head = new Node(item, m_head);
        if (m_size != 0){
            m_head->next->prev = m_head;
        }
        else {
            m_tail = m_head;
        }
        m_size++;


    }
    void push_back(T item) {
        m_tail = new Node(item, nullptr, m_tail);
        if (m_size != 0) {
            m_tail->prev->next = m_tail;
        }
        else {
            m_head = m_tail;
        }
        m_size++;
    }
    void insert(T item, int position) {
        // implement insert here
        if (position < 0 or position > m_size){
            throw std::out_of_range("Invalid index");
        }
        if (position == m_size) {
            push_back(item);
        }
        else if (position == 0){
            push_front(item);
        }
        else {
            Node * ptr = m_head;
            for (int i = 0; i < position; i++) {
                ptr = ptr->next;
            }
            Node * newItem = new Node(item, ptr, ptr->prev);
            ptr->prev->next = newItem;
            ptr->prev = newItem;
            m_size++;
        }
    }

    void pop_front() {
        if(m_size == 0) {
            throw std::length_error("No items in list");
        }

        if (m_head == nullptr) {
            return;
        }
        if (m_head->next == nullptr) {
            delete m_head;
            delete m_tail;
            m_head = nullptr;
            m_tail = nullptr;
            m_size--;
        }
        else {
            m_head->next->prev = nullptr;
            m_head = m_head->next;
            m_size--;
        }


    }
    void pop_back() {
        // implement pop_back here
        if(m_size == 0) {
            throw std::length_error("No items in list");
        }
        if(m_head == nullptr) {
            return;
        }
        if (m_head->next ==nullptr) {
            delete m_head;
            m_head = nullptr;
            m_size--;
        }
        else{
            Node * current = m_head;
            while (current->next->next != nullptr) {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
            m_size--;
        }

    }

    void remove(int position) {
        if (position < 0 or position >= m_size) {
            throw std::out_of_range("Invalid index");
        }
        if (position == m_size-1) {
            pop_back();

        }
        else if (position == 0) {
                pop_front();
        }
        else {
            Node * ptr = m_head;
            for (int i = 0; i < position; i++) {
                ptr = ptr->next;
            }

            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            m_size--;
            delete ptr;
        }
    }

    const T& front() const {
        if(m_size == 0) {
            throw std::length_error("No items in list");
        }
        return m_head->value;
        // implement front here
    }
    const T& back() const {
        if(m_size == 0) {
            throw std::length_error("No items in list");
        }
        return m_tail->value;
        // implement back here
    }
    const T& at(int index) const {
        // implement at here
        if(index < 0 or index >= m_size) {
            throw std::out_of_range("Invalid index");
        }
        if (index == 0) {
            return front();
        }
        else if (index == m_size-1) {
            return back();
        }
        else {
            Node * ptr = m_head;
            for (int i = 0; i < index; i++) {
                ptr = ptr->next;
            }
            return ptr->value;
        }
    }

    bool contains(const T& item) const {
        // implement contains here
        Node * ptr = m_head;
        for (int i = 0; i < m_size; i++) {
            if (ptr->value == item) {
                return true;
            }
            ptr = ptr->next;
        }
        return false;
    }

    int size() const {
        return m_size;
        // implement size here
    }

    void clear() {
        while (m_head != nullptr) {
            Node* temp = m_head;
            m_head = m_head->next;
            delete temp;
            temp = nullptr;
        }
        delete m_head;
        m_head = nullptr;
        m_size = 0;
        // implement clear here
    }
private:
    Node * m_head;
    Node * m_tail;
    size_t m_size;

};
