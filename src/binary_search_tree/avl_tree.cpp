//
// Copyright Caiden Sanders - All Rights Reserved
//
// Unauthorized copying of this file, via any medium is strictly prohibited.
// Proprietary and confidential.
//
// Written by Caiden Sanders <work.caidensanders@gmail.com>, March 19, 2024.
//

#include "../../include/binary_search_tree/avl_tree.hpp"

#include <iostream>

int AVLTree::height(AVLNode* N) {
    if (N == nullptr) return 0;
    return N->height;
}

int AVLTree::getBalance(AVLNode* N) {
    if (N == nullptr) return 0;
    return height(N->left) - height(N->right);
}

AVLNode* AVLTree::rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    return x;
}

AVLNode* AVLTree::leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    return y;
}

AVLNode* AVLTree::minNodeValue(AVLNode* node) {
    AVLNode* current = node;
    while (current->left != nullptr) current = current->left;
    return current;
}

AVLNode* AVLTree::insert(AVLNode* node, int data) {
    if (node == nullptr) return new AVLNode(data);

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    } else {
        return node;
    }

    node->height = 1 + std::max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && data < node->left->data) {
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && data > node->right->data) {
        return leftRotate(node);
    }

    // Left Right Case
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void AVLTree::insert(int data) { root = insert(root, data); }

AVLNode* AVLTree::remove(AVLNode* node, int data) {
    if (node == nullptr) return node;

    if (data < node->data) {
        node->left = remove(node->left, data);
    } else if (data > node->data) {
        node->right = remove(node->right, data);
    } else {
        if ((node->left == nullptr) || (node->right == nullptr)) {
            AVLNode* temp = node->left ? node->left : node->right;

            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            } else {
                *node = *temp;  // Copy the contents of the non-empty child
            }
            delete temp;
        } else {
            AVLNode* temp = minNodeValue(node->right);

            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
    }

    if (node == nullptr) return node;

    node->height = 1 + std::max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && getBalance(node->left) >= 0) {
        return rightRotate(node);
    }

    // Left Right Case
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && getBalance(node->right) <= 0) {
        return leftRotate(node);
    }

    // Right Left Case
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void AVLTree::remove(int data) { root = remove(root, data); }

void AVLTree::print_in_order(AVLNode* node) {
    if (node != nullptr) {
        print_in_order(node->left);
        std::cout << node->data << " ";
        print_in_order(node->right);
    }
}

void AVLTree::print_in_order() {
    print_in_order(root);
    std::cout << std::endl;
}

void AVLTree::print_pre_order(AVLNode* node) {
    if (node != nullptr) {
        std::cout << node->data << " ";
        print_pre_order(node->left);
        print_pre_order(node->right);
    }
}

void AVLTree::print_pre_order() {
    print_pre_order(root);
    std::cout << std::endl;
}

void AVLTree::print_post_order(AVLNode* node) {
    if (node != nullptr) {
        print_post_order(node->left);
        print_post_order(node->right);
        std::cout << node->data << " ";
    }
}

void AVLTree::print_post_order() {
    print_post_order(root);
    std::cout << std::endl;
}