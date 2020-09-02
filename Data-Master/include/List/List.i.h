///@author Daniele Vencato
///@file List.i.h
#pragma once

namespace List {
    template<class T>
    int List<T>::count = 0;

    template<class T>
    int List<T>::countinstances() {
        return count;
    }

    template<class T>
    typename List<T>::Node *List<T>::pushBack(T key) {
        if (this->head == NULL) {
            this->head = new List<T>::Node(key);
            this->head = this->head;
            List<T>::current = this->head;
            this->listSize++;
            return this->head;
        } else {
            List<T>::current->next = new List<T>::Node(key);
            List<T>::current = List<T>::current->next;
            this->listSize++;
            return this->head;
        }
    }

    template<class T>
    void List<T>::erase(T index) {
        if (this->head != NULL) {
            List<T>::Node *currentNode = this->head;
            List<T>::Node *tempOne = NULL;
            if (index > 0) {
                for (int i = 0; i <= index; i++) {
                    if (i == index - 1) {
                        tempOne = currentNode;
                    } else if (i == index) {
                        if (currentNode->next != NULL) {
                            List<T>::Node *tempTwo = currentNode->next;
                            tempOne->next = tempTwo;
                        } else {
                            tempOne->next = NULL;
                        }
                    }
                    currentNode = currentNode->next;
                }
            } else if (index == 0) {
                this->head = this->head->next;
            }
        } else {
            cout << "List is already empty";
        }
    }

    template<class T>
    void List<T>::insert(T key, int index) {
        if (this->head == NULL && index == 0) {
            head = new List<T>::Node(key);
            List<T>::current = this->head;
            this->listSize++;
        } else if (this->head != NULL) {
            List<T>::Node *currentNode = this->head;
            for (int i = 0; i <= index - 1; i++) {
                if (i == index - 1) {
                    auto *node = new List<T>::Node(key);
                    List<T>::Node *temp = currentNode->next;
                    currentNode->next = node;
                    node->next = temp;
                }
                currentNode = currentNode->next;
            }
        } else {
            cout << "can't insert at your specified location";
        }
    }

    template<class T>
    int List<T>::size() {
        return listSize;
    }

    template<class T>
    void List<T>::printList() {
        if (this->head != NULL) {
            List<T>::Node *node;
            node = this->head;
            while (node != NULL) {
                cout << node->key << " ";
                node = node->next;
            }
        }
    }

    template<class T>
    List <T> List<T>::operator+(List <T> *list) const {
        List<T>::Node *cNode = this->head;
        int size = list->listSize;
        for (int i = 0; i < size; i++) {
            list->pushBack(cNode->key);
            cNode = cNode->next;
        }
        return *list;
    }

    template<class T>
    int List<T>::operator[](int index) {
        if (this->head != NULL) {
            if (index >= 0) {
                List<T>::Node *cNode = this->head;
                for (int i = 0; i < this->size(); i++) {
                    if (i == index) {
                        return cNode->key;
                    }
                    cNode = cNode->next;
                }
            }
        } else {
            cout << "List is empty";
            return -1;
        }
        return -1;
    }

    template<class T>
    int List<T>::square(int x) {
        return x * x;
    }

    template<class T>
    void List<T>::transformHelper() {
        int arr[1000];
        List<T>::Node *ptr = this->head;
        for (int i = 0; i < this->listSize; i++) {
            arr[i] = ptr->key;
            ptr = ptr->next;
        }
        int res[1000];
        transform(arr, arr + this->listSize, res, square);
        ptr = this->head;
        for (int i = 0; i < this->listSize; i++) {
            ptr->key = res[i];
            ptr = ptr->next;
        }
    }
}// namespace List