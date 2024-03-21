//
// Copyright Caiden Sanders - All Rights Reserved
//
// Unauthorized copying of this file, via any medium is strictly prohibited.
// Proprietary and confidential.
//
// Written by Caiden Sanders <work.caidensanders@gmail.com>, March 19, 2024.
//

#include "../../include/binary_search_tree/binary_search_tree.hpp"

Node::Node(int data) : data(data), left(nullptr), right(nullptr) {}

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::BinarySearchTree(int data) : root(new Node(data)) {}

BinarySearchTree::~BinarySearchTree() {
    // Recursive helper function to delete the tree
    std::function<void(Node*)> deleteTree = [&](Node* node) {
        if (node) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    };

    deleteTree(root);
}

Node* BinarySearchTree::insert(Node* node, int data) {
    if (node == nullptr) {
        return new Node(data);
    }

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }

    return node;
}

void BinarySearchTree::insert(int data) { root = insert(root, data); }

Node* BinarySearchTree::remove(Node* node, int data) {
    if (node == nullptr) {
        return node;
    }

    if (data < node->data) {
        node->left = remove(node->left, data);
    } else if (data > node->data) {
        node->right = remove(node->right, data);
    } else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* temp = min_value_node(node->right);
        node->data = temp->data;
        node->right = remove(node->right, temp->data);
    }
    return node;
}

void BinarySearchTree::remove(int data) { root = remove(root, data); }

Node* BinarySearchTree::min_value_node(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

Node* BinarySearchTree::search(Node* node, int data) {
    if (node == nullptr || node->data == data) {
        return node;
    }

    if (data < node->data) {
        return search(node->left, data);
    } else {
        return search(node->right, data);
    }
}

Node* BinarySearchTree::search(int data) { return search(root, data); }

void BinarySearchTree::print_in_order(Node* node) {
    if (node != nullptr) {
        print_in_order(node->left);
        std::cout << node->data << " ";
        print_in_order(node->right);
    }
}

void BinarySearchTree::print_in_order() {
    print_in_order(root);
    std::cout << std::endl;
}

void BinarySearchTree::print_pre_order(Node* node) {
    if (node != nullptr) {
        std::cout << node->data << " ";
        print_pre_order(node->left);
        print_pre_order(node->right);
    }
}

void BinarySearchTree::print_pre_order() {
    print_pre_order(root);
    std::cout << std::endl;
}

void BinarySearchTree::print_post_order(Node* node) {
    if (node != nullptr) {
        print_post_order(node->left);
        print_post_order(node->right);
        std::cout << node->data << " ";
    }
}

void BinarySearchTree::print_post_order() {
    print_post_order(root);
    std::cout << std::endl;
}