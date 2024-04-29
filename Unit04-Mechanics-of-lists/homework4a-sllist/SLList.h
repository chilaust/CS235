#pragma once

template <class T>
class SLList {
public:
    struct Node {
        Node* next;
        T value;

        Node(T v) : next(nullptr), value(v) {}
    };
    size_t _size;
    Node* head;

    SLList() : head(nullptr), _size(0){}

    ~SLList() {
        clear();
    }

    const Node* get_head() const {
        return head;
        // implement get_head here
    }

    void push_back(T item) {
        if (head == nullptr){
            head = new Node(item);
            head->next = nullptr;
            _size++;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new Node(item);
            current->next->next = nullptr;
            _size++;
        }
    }

    void pop_back() {
        if (_size == 0) {
            throw std::length_error("No items in list");
        }
        if(head == nullptr) {
            return;
        }
        if (head->next ==nullptr) {
            delete head;
            head = nullptr;
            _size--;
        }
        else {
            Node* current = head;
            while (current->next->next != nullptr) {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
            _size--;
        }


    }

    const T& front() const {
        if (_size == 0) {
            throw std::length_error("No items in list");
        }
        return head->value;
        // implement front here
    }

    int size() const {
        return _size;
        // implement size here
    }

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
            temp = nullptr;
        }
        delete head;
        head = nullptr;
        _size = 0;

    }
};


