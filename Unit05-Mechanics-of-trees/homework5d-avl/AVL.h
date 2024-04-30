#pragma once

template<class T>
class AVL {
public:
    struct Node {
        Node* left;
        Node* right;
        T value;
        int height;

        Node(T v) : left(nullptr), right(nullptr), value(v), height(1) {}
    };

    AVL() : m_root(nullptr), m_size(0) {
        // implement the contructor here
    }

    ~AVL() {
        // implement the destructor here
        clear(m_root);
    }

    const Node* getRootNode() const {
        return m_root;
        // implement getRootNode here
        // return a pointer to the tree's root node
    }

    bool insert(T item) {
        bool result = add(m_root, item);
        if (result) {
            m_size++;
        }
        return result;

        // implement insert here
        // return true if item was inserted, false if item was already in the tree
    }

    bool remove(T item) {
        if (m_size == 0) {
            return false;
        }

        if (remove_helper(m_root, item)) {
            if (m_size > 0) {
                m_size--;
            }
            return true;
        }
        else {
            return false;
        }
        // implement remove here
        // return true if item was removed, false if item wasn't in the tree
    }

    bool contains(T item) const {
        return contain(m_root, item);
        // implement contains here
        // return true if item is in the tree, false otherwise
    }

    void clear() {
        clear(m_root);
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

    int getHeight(const Node * node) {
        return (node == nullptr)? 0 : node->height;
    }


    void updateHeight(Node*& node) {
        node->height = std::max(getHeight(node->left),getHeight(node->right)) + 1;
    }

    void promote_left_child(Node*& node) {
        auto new_root = node->left;
        node->left = node->left->right;
        new_root->right = node;
        node = new_root;
        updateHeight(node->right);
        updateHeight(node);
        // implement promote_left here
    }

    void promote_right_child(Node*& node) {
        auto new_root = node->right;
        node->right = node->right->left;
        new_root->left = node;
        node = new_root;
        updateHeight(node->left);
        updateHeight(node);
        // implement promote_right here
    }

    void rebalance_negative (Node*& node) {
        int left_balance = getHeight(node->left->right) - getHeight(node->left->left);
        if (left_balance > 0) {
            promote_right_child(node->left);
        }
        promote_left_child(node);
    }

    void rebalance_positive (Node*& node) {
        int right_balance = getHeight(node->right->right) - getHeight(node->right->left);
        if (right_balance < 0) {
            promote_left_child(node->left);
        }
        promote_right_child(node);
    }


    void rebalance(Node * & node) {
        int balance = getHeight(node->right) - getHeight(node->left);
        if (balance > 1) {
            rebalance_positive(node);
        }
        if (balance < -1) {
            rebalance_negative(node);
        }
    }

    void clear(Node* & node) {

        if (node == nullptr) {
            return;
        }
        clear(node->left);
        clear(node->right);
        delete node;
        // implement clear here
        // remove all nodes from the tree
    }

    bool contain(Node * node, T item) const {
        if (node == nullptr) {
            return false;
        }
        if (node->value == item) {
            return true;
        }
        if (item < node->value) {
            return contain(node->left, item);
        }
        else {
            return contain(node->right, item);
        }
    }

    bool add(Node * & node, T item) {
        if(node == nullptr) {
            node = new Node(item);
            return true;
        }
        if (node->value == item) {
            return false;
        }
        bool changed = false;

        if (item < node->value) {
            changed = add(node->left, item);
        }
        else {
            changed = add(node->right, item);
        }
        if (changed) {
            updateHeight(node);
            rebalance(node);
        }
        return changed;
    }

    bool remove_helper(Node * node, T item) {
        bool removed = false;
        if (node == nullptr) {
            removed = false;
        }

        if (node->value == item) {
            Node * temp = node;
            if (node->left == nullptr && node->right ==nullptr) {
                delete node;
                node = nullptr;
                removed = true;
            }
            if (node->left == nullptr) {
                node = node->right;
                delete temp;
                removed = true;
            }

            else if (node->right == nullptr) {
                node = node->left;
                delete temp;
                removed = true;
            }

            else {
                Node* iop = find_iop(node->left);
                node->value = iop->value;
                removed =  remove_helper(node->left, iop->value);
            }

        }

        else if (item < node->value) {
            removed =  remove_helper(node->left, item);
        }

        else {
            removed = remove_helper(node->right, item);
        }

        if (removed) {
            updateHeight(node);
            rebalance(node);
        }
        return removed;

    }

    Node* find_iop(Node* node) {
        while(node->right != nullptr) {
            node = node->right;
        }
        return node;
    }
};
