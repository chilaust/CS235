#pragma once
#include<iostream>

struct Node {
    Node* left;
    Node* right;
    int value;

    Node(int v) : left(nullptr), right(nullptr), value(v) {}
};

bool find(Node* root, int item) {
    if (root == nullptr) {
//        std::cout << "I made it here" << std::endl;
        return false;
    }
    if (root->value == item) {
//        std::cout << "I made it there" << std::endl;
        return true;
    }
    if (find(root->right, item) || find(root->left,  item)) {
//        std::cout << "I made it everywhere" << std::endl;
        return true;
    }
    else {
//        std::cout << "I made it where??" << std::endl;
        return false;
    }
}
