///@author Daniele Vencato
///@file bst.i.h
#pragma once
#include <stddef.h>
#include <iostream>

namespace BST {
    template<class T>
    typename BST<T>::Node *BST<T>::insert(T key) {
        return insert(key, this->root, nullptr);
    }

    template<class T>
    typename BST<T>::Node *BST<T>::deleteNode(T key) {
        return deleteNode(key, this->root);
    }

    template<class T>
    typename BST<T>::Node *BST<T>::insert(T key, Node *node, Node *parent) {
        if (node == NULL) {
            Node *nNode = new BST<T>::Node(key, parent);
            if (this->root == NULL) {
                this->root = nNode;
            }
            return nNode;
        } else {
            Node *pNode;
            if (key < node->data) {
                pNode = node;
                node->left = insert(key, node->left, pNode);
            } else if (key > node->data) {
                pNode = node;
                node->right = insert(key, node->right, pNode);
            } else if (key == node->data) {
                return node;
            }
        }
        return node;
    }

    template<class T>
    typename BST<T>::Node *BST<T>::deleteNode(T key, Node *node) {

        if (node != NULL) {
            if (key < node->data) {
                node->left = deleteNode(key, node->left);
            } else if (key > node->data) {
                node->right = deleteNode(key, node->right);
            } else {
                if (node->left != NULL && node->right != NULL) { //node has both children
                    Node *smallNode = findMinimum(node->right);

                    node->data = smallNode->data;
                    if (smallNode == smallNode->parent->left) {
                        smallNode->parent->left = deleteNode(smallNode->data, smallNode);
                    } else if (smallNode == smallNode->parent->right) {
                        smallNode->parent->right = deleteNode(smallNode->data, smallNode);
                    }
                    return node;
                }
                if (node->left == NULL && node->right == NULL) { //leaf
                    return NULL;
                }
                if (node->left == NULL || node->right == NULL) {
                    if (node->left != NULL) { //node has left child
                        node->data = node->left->data;
                        node->left = deleteNode(node->left->data, node->left);
                    } else if (node->right != NULL) { //node has right child
                        node->data = node->right->data;
                        node->right = deleteNode(node->right->data, node->right);
                    }
                    return node;
                }
            }
        }
        return node;
    }

    template<class T>
    typename BST<T>::Node *BST<T>::findMinimum(Node *node) {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }

    template<class T>
    void BST<T>::print(Node *node) {
        if (node != NULL) {
            cout << node->data << " ";
            print(node->left);
            print(node->right);
        }
    }
}