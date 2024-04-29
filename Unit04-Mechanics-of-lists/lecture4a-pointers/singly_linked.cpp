#pragma once

template <class T>
class SLList
{
    struct Node {
        Node* next;
        T value;
        Node(T const &item) : value(item), next(nullptr) {}
        //next - a pointer to the next Node in the list
        //value - an object of the data type to store the value of the node

        Node(T v) : next(nullptr), value(v) {}
    };
    Node* head;
    size_t _size;

    void _push_back(T item) {
        Node* newNode = new Node(item);
        if (head == nullptr) {
            head = newNode;
            _size++;
        }
        else {
            Node* current = head;
            while(current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
            _size++;
        }


        // implement push_back here
        //adds a new node with the given item to the end of the list
    }
    void _clear(Node* node){
        if (node == nullptr){
            return;
        }
        _clear(node->next);
        delete node;
        node = nullptr;
        _size--;
    }
public:


    SLList() : head(nullptr), _size(0) {}
    //SLList() - a default constructor that initializes an empty list

    ~SLList() {
        clear();
    }
    //~SLList() - a destructor that clears the list
    const Node* get_head() const {
        return head;
        //returns a pointer to the head node
    }
    void push_back(T const &item){
        _push_back(head, item);
    }

    void pop_back() {
        Node* current = head;
        if (current == nullptr){
            return;
        }
        while(current->next != nullptr) {
            current = current->next;
        }
        delete current;
        current = nullptr;
        _size--;


        //  removes the last node in the list
    }

    const T& front() const {
        return head->value;
        // returns a const reference to the value of the head node (assume list is not empty)
    }

    int size() const {
        return _size;
        // returns the current size of the list (i.e., the number of elements/nodes)
    }
    void clear(){
        _clear(head);
    }


};








#include <stddef.h>
#include <iostream>
using std::cout, std::endl;

template <class T>
class SLList
{
    public:
    struct Node {
        T value;
        Node* next;
        Node(T const& item) : value(item), next(nullptr) {}
    };
private:
    Node* _head;
    size_t _size;

    void _push_back(Node*& node, T const& item) {
        if (node == nullptr) {
            node = new Node(item);
            _size++;
        } else {
            _push_back(node->next, item);
        }
    }

    void _clear(Node*& node) {
        if (node != nullptr) {
            _clear(node->next);

            delete node;
            node = nullptr;
            _size--;        
        }
    }

public:
    SLList() : _head(nullptr), _size(0) {}

    ~SLList() {
        clear();
    }

    T first() const
    {
        /* don't call this unless you're sure there is a value here! */
        return _head->value;
    }

    size_t size() const {
        return _size;
    }

    void push_back(T const &item)
    {
        _push_back(_head, item);
    }

    void clear()
    {
        _clear(_head);
    }
};

void epic() {
    SLList<long long> list;
    for (int i = 0; i < 10; i++) {
        list.push_back(i);
    }
}

int main()
{
    for (int i = 0; i < 1000000000; i++) {
        epic();
    }

    SLList<int> list;
    cout << "Size should be 0: " << list.size() << endl;
    list.push_back(7);
    list.push_back(8);
    cout << "Size should be 2: " << list.size() << endl;
    list.clear();
    cout << "Size should be 0: " << list.size() << endl;
}