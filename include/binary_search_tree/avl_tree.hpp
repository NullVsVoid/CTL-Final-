//
// Copyright Caiden Sanders - All Rights Reserved
//
// Unauthorized copying of this file, via any medium is strictly prohibited.
// Proprietary and confidential.
//
// Written by Caiden Sanders <work.caidensanders@gmail.com>, March 19, 2024.
//

#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include <algorithm>  // For std::max

struct AVLNode {
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int d) : data(d), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
   private:
    AVLNode* root;

    AVLNode* insert(AVLNode* node, int data);
    AVLNode* remove(AVLNode* node, int data);
    int height(AVLNode* node);
    int getBalance(AVLNode* node);
    AVLNode* rightRotate(AVLNode* y);
    AVLNode* leftRotate(AVLNode* x);
    AVLNode* minNodeValue(AVLNode* node);
    void print_in_order(AVLNode* node);
    void print_pre_order(AVLNode* node);
    void print_post_order(AVLNode* node);

   public:
    AVLTree() : root(nullptr) {}
    void insert(int data);
    void remove(int data);
    void print_in_order();
    void print_pre_order();
    void print_post_order();
};

#endif  // AVL_TREE_HPP