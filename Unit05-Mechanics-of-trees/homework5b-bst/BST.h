#pragma once

template<class T>
class BST {
public:
    struct Node {
        Node* left;
        Node* right;
        T value;

        Node(T value) : left(nullptr), right(nullptr), value(value) {}
    };

    BST() :m_root(nullptr), m_size(0) {}

    ~BST() {
        clear();
        // implement the destructor here
    }

    const Node* getRootNode() const {
        return m_root;
        // implement getRootNode here
        // return a pointer to the tree's root node
    }

    bool insert(T item) { //Need Helper
        if (m_root == nullptr) {
            m_root = new Node(item);
            m_size++;
            return true;
        }
        else {
            return insert_helper(m_root, item);
        }
    }

    bool remove(T item) {
        if (m_size == 0) {
            return false;
        }

        if(remove_helper(m_root, item)) {
            if (m_size > 0) {
                m_size--;
            }
            return true;
        }
        else {
            return false;
        }

    }

    bool contains(T item) const {
        if(contains_helper(m_root, item)) {
            return true;
        }
        else {
            return false;
        }
    }


    void clear() {
        clear_helper(m_root);
        m_root = nullptr;
        m_size = 0;
    }

    int size() const {
        return m_size;
        // implement size here
        // return the number of nodes in the tree
    }
private:
    Node * m_root;
    size_t m_size;


    bool insert_helper(Node*& node, T item) {
        if (node == nullptr) {
            node = new Node(item);
            m_size++;
            return true;
        }
        else if (item < node->value) {
            return insert_helper(node->left, item);
        }
        else if (item > node->value) {
            return insert_helper(node->right,  item);
        }
        else {
            //equal... already there
            return false;
        }
    }


    bool remove_helper(Node*& node, T item) {
        if (node == nullptr) {
            return false;
        }

        if (node->value == item) {
            Node * temp = node;
            if (node->left == nullptr && node->right ==nullptr) {
                delete node;
                node = nullptr;
                return true;
            }
            if (node->left == nullptr) {
                node = node->right;
                delete temp;
                return true;
            }

            else if (node->right == nullptr) {
                node = node->left;
                delete temp;
                return true;
            }

            else {
                Node* iop = find_iop(node->left);
                node->value = iop->value;
                return remove_helper(node->left, iop->value);
            }

        }

        else if (item < node->value) {
            return remove_helper(node->left, item);
        }

        else {
            return remove_helper(node->right, item);
        }
    }


    Node* find_iop(Node* node) {
        while(node->right != nullptr) {
            node = node->right;
        }

        return node;
    }

    bool contains_helper(Node* node, T item) const {
        if (node == nullptr)  {
            return false;
        }

        // Check left
        else if (item < node->value) {
            return contains_helper(node->left, item);
        }
        // Check right
        else if (item >  node->value) {
            return contains_helper(node->right, item);
        }

        else {
            return true;
        }
    }


    void clear_helper(Node*& node) {
        if (node == nullptr) {
            return;
        }

        clear_helper(node->left);
        clear_helper(node->right);
        delete node;
        return;
    }


};



//        if (node == nullptr) {
//            return nullptr;
//        }
//        else if (item < node->value) {
//            //rebuild left side of node because it might contain item we are removing
//            node->left = remove_helper(node->left, item);
//        }
//        else if (item > node->value) {
//            //rebuild right side of node because it might contain the ttem we are removing
//            node->right = remove_helper(node->right, item);
//        }
//        else {
//            //remove this node... must deal with where to put children
//            if (node->left == nullptr && node->right == nullptr) {
//                //this is the base case... optimal haha, this is if we are removing a bottom node
//                delete node;
//                return nullptr;
//            }
//            //new node is right
//            else if (node->left == nullptr) {
//                Node* temp = node;
//                node = node->right;
//                delete temp;
//
//            }
//            // new node is left
//            else if (node->right == nullptr) {
//                Node* temp = node;
//                node = node->left;
//                delete temp;
//            }
//            //have to find the new node...
//            else {
//                Node* new_root = find_iop(node->left);
//                node->value = new_root->value;
//                return remove_helper(node->left, new_root->value);
//            }
//        }
