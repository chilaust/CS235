#pragma once

template <class T>
class SLList {

private:
    Node* head;
public:
    struct Node {
        Node* next;
        T value;
        Node(T const &item) : value(item), next(nullptr) {}
        //next - a pointer to the next Node in the list
        //value - an object of the data type to store the value of the node

        Node(T v) : next(nullptr), value(v) {}
    };

    SLList() {}
    //SLList() - a default constructor that initializes an empty list

    ~SLList() {}
    //~SLList() - a destructor that clears the list

    const Node* get_head() const {
        return head;
        //returns a pointer to the head node
    }

    void push_back(T item) {
        Node* newNode = new Node(item);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while(current->next != nullptr) {
                current = current->next
            }
            current->next = newNode;
        }


        // implement push_back here
        //adds a new node with the given item to the end of the list
    }

    void pop_back() {
        //  removes the last node in the list
    }

    const T& front() const {
        // returns a const reference to the value of the head node (assume list is not empty)
    }

    int size() const {
        // returns the current size of the list (i.e., the number of elements/nodes)
    }

    void clear() {
        //  removes all nodes from the list
    }
};
