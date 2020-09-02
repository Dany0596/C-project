///@author Daniele Vencato
///@file example.cpp
#include "../include/data.h"
#include <iostream>

int main(){
    using namespace std;

    cout << "-------------Binary Search Tree part --------------\n";
    int num, key;
    auto *bst = new BST::BST<int>();
    cout<<"------ Number of nodes you want to insert in binary search tree --------\n";
    cin>>num;
    for (int i = 0; i < num; i++) {
        cout<<"Add key for node " << i+1 << endl;
        cin>>key;
        bst->insert(key);
    }
    cout << "-------------------------------------" << endl;
    cout << "Printing binary search tree (printTree)" << endl;
    bst->print(bst->root);

    cout << "\n-------------- Turning to List part ----------------\n";
    List::List<int> *list, *listTwo;
    cout << "------- Default constructor call ---------\n";
    list = new List::List<int>();
    cout << "------- List(count) constructor call ---------\n";
    listTwo = new List::List<int>(4);
    cout << "------- List constructor with initializer list with values 1, 2, 3 ---------\n";
    List::List<int> *listThree = new List::List<int>({1,2,3}); //for initializer list
    cout << "printing\n";
    listThree->printList();
    cout << endl;
    cout << "----------- three pushback method calls on List object with values 1, 2, 3\n";
    list->pushBack(1);
    list->pushBack(2);
    list->pushBack(3);
    cout << "printing\n";
    list->printList();
    cout << endl;

    cout << "---- List instances created are three, calling function to check it\n";
    cout << List::List<int>::countinstances() << endl;
    cout << "-------- size of list one is three, calling from function to check it\n";
    cout << list->size() << endl;

    cout << "---- Testing + operator.. applaying on two lists with values (1,2,3) (1,2,3)\n";
    list->operator+(listThree);
    listThree->printList();
    cout << endl;

    cout << "---- Testing [] operator.. on list with values (1,2,3) -- accessing 0th index\n";
    cout << listThree->operator[](0);
    return 0;
}