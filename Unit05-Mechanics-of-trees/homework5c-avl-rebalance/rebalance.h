#pragma once

struct Node {
    Node* left;
    Node* right;
    int value;
    int height;

    Node(int v) : left(nullptr), right(nullptr), value(v), height(1) {}
};

// Hint: you might find it helpful to write an update_height function that takes
// a Node* and updates its height field based on the heights of its children
int getHeight(const Node* node) {
    return (node == nullptr)? 0 : node->height;
}


void updateHeight(Node*& node) {
    node->height = std::max(getHeight(node->left),getHeight(node->right)) + 1;
}

void promote_left(Node*& node) {
    auto new_root = node->left;
    node->left = node->left->right;
    new_root->right = node;
    node = new_root;
    updateHeight(node->right);
    updateHeight(node);
    // implement promote_left here
}

void promote_right(Node*& node) {
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
        promote_right(node->left);
    }
    promote_left(node);
}

void rebalance_positive (Node*& node) {
    int right_balance = getHeight(node->right->right) - getHeight(node->right->left);
    if (right_balance < 0) {
        promote_left(node->left);
    }
    promote_right(node);
}


void rebalance(Node*& node) {
    int balance = getHeight(node->right) - getHeight(node->left);
    if (balance > 1) {
        rebalance_positive(node);
    }
    if (balance < -1) {
        rebalance_negative(node);
    }
}
//#pragma once
//
//struct Node {
//    Node* left;
//    Node* right;
//    int value;
//    int height;
//
//    Node(int v) : left(nullptr), right(nullptr), value(v), height(1) {}
//};
//
//// Hint: you might find it helpful to write an update_height function that takes
//// a Node* and updates its height field based on the heights of its children
//int getHeight(const Node* node) {
//    return (node == nullptr)? 0 : node->height;
//}
//
//
//void updateHeight(Node*& node) {
//    node->height = std::max(getHeight(node->left),getHeight(node->right)) + 1;
//}
//
//Node* promote_left(Node*& node) {
//    auto new_root = node->left;
//    node->left = node->left->right;
//    new_root->right = node;
//    node = new_root;
//    updateHeight(node->right);
//    updateHeight(node);
//    return node;
//    // implement promote_left here
//}
//
//Node* promote_right(Node*& node) {
//    auto new_root = node->right;
//    node->right = node->right->left;
//    new_root->left = node;
//    node = new_root;
//    updateHeight(node->left);
//    updateHeight(node);
//    return node;
//    // implement promote_right here
//}
//
//Node* rebalance_negative (Node*& node) {
//    int left_balance = getHeight(node->left->right) - getHeight(node->left->left);
//    if (left_balance > 0) {
//        promote_right(node->left);
//    }
//    node = promote_left(node);
//    return node;
//}
//
//Node* rebalance_positive (Node*& node) {
//    int right_balance = getHeight(node->right->right) - getHeight(node->right->left);
//    if (right_balance < 0) {
//        promote_left(node->left);
//    }
//    node = promote_right(node);
//    return node;
//}
//
//
//void rebalance(Node*& node) {
//    int balance = getHeight(node->right) - getHeight(node->left);
//    if (balance > 1) {
//        node = rebalance_positive(node);
//    }
//    if (balance < -1) {
//        node = rebalance_negative(node);
//    }
//    // implement rebalance here
//}
