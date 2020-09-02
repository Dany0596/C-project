///@author Daniele Vencato
///@file List.h
#pragma once

#include <string>
#include <iostream>
#include <algorithm>


namespace List {
    using namespace std;
/*
    class Node {
    public:
        T key;
        Node *next;

        Node() = default;

        explicit Node(T key) {
            this->key = key;
            this->next = NULL;
        }
    };
*/
    template<class T>
    class List {
        class Node {
        public:
            T key;
            Node *next;

            Node() = default;

            explicit Node(T key) {
                this->key = key;
                this->next = NULL;
            }
        };
    public:

        int listSize = 0;
        static int count;
        Node *current = NULL;

    public:
        Node *head = NULL;

        List() {
            count++;
        }

        explicit List(int count) {
            List::count++;
            for (int i = 0; i < count; i++) {
                if (head == NULL) {
                    head = new Node();
                    current = head;
                    this->listSize++;
                } else {
                    auto *node = new Node();
                    current->next = node;
                    current = node;
                    this->listSize++;
                }
            }
        }

        List(initializer_list<T> l) {
            List::count++;
            initializer_list<int>::iterator it = l.begin();
            for (int i = 0; i < l.size(); i++) {
                if (head == NULL) {
                    head = new Node(*it);
                    current = head;
                    this->listSize++;
                } else {
                    auto *node = new Node(*it);
                    current->next = node;
                    current = node;
                    this->listSize++;
                }
                (*it++);
            }
        }

        List(List &list) {
            List::count++;
            this->head = list.head;
            this->current = list.current;
            this->listSize = list.listSize;
        }

        static int countinstances();

        Node *pushBack(T key);

        void erase(T index);

        void insert(T key, int index);

        int size();

        void printList();

        List operator+(List *list) const;

        int operator[](int index);

        static int square(int x);

        void transformHelper();
    };

}// namespace List

#include "List.i.h"