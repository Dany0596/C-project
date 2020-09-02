///@author Daniele Vencato
///@file bst.h
///@brief Declaration of BST
#pragma once

#include <stddef.h>
#include <iostream>
namespace BST {
    using namespace std;

    template<class T>
    class BST {
    public:
        class Node {
        public:
            T data;
            Node *left = nullptr, *right = nullptr, *parent = nullptr;

            Node(T data, Node *parent) {
                this->data = data;
                this->parent = parent;
            }
        };

        Node *root = nullptr;

        Node *insert(T key);

        Node *deleteNode(T key);

        Node *findMinimum(Node *node);

        void print(Node *node);

    private:
        Node *insert(T key, Node *node, Node *parent);

        Node *deleteNode(T key, Node *node);
    };
}
#include "BST.i.h"
