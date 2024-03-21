//
// Copyright Caiden Sanders - All Rights Reserved
//
// Unauthorized copying of this file, via any medium is strictly prohibited.
// Proprietary and confidential.
//
// Written by Caiden Sanders <work.caidensanders@gmail.com>, March 19, 2024.
//

#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <functional>
#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data);  // Constructor signature.
};

class BinarySearchTree {
   private:
    Node* root;
    Node* insert(Node* node, int data);
    Node* remove(Node* node, int data);
    Node* min_value_node(Node* node);
    Node* search(Node* node, int data);
    void print_in_order(Node* node);
    void print_pre_order(Node* node);
    void print_post_order(Node* node);

   public:
    BinarySearchTree();
    explicit BinarySearchTree(int data);
    ~BinarySearchTree();
    void insert(int data);
    void remove(int data);
    Node* search(int data);
    void print_in_order();
    void print_pre_order();
    void print_post_order();
};

#endif  // BINARY_SEARCH_TREE_HPP