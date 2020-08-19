#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int key;
    struct TreeNode *left, *right, *parent;
};

struct TreeNode *newNode(int item)
{
    struct TreeNode *temp = new TreeNode;
    temp->key = item;
    temp->left = temp->right = NULL;
    temp->parent = NULL;
    return temp;
}

void printTree(struct TreeNode *node)
{
    if (node != NULL)
    {
        printTree(node->left);
        cout << "Node: " << node->key << " ";
        if (node->parent == NULL)
            cout << "Parent Node : NULL \n";
        else {
            cout << "Parent Node : " << node->parent->key << endl;

        }
        printTree(node->right);
    }
}

struct TreeNode* insert(struct TreeNode* node, int key)
{
    if (node == NULL) return newNode(key);

    if (key < node->key)
    {
        TreeNode *lchild = insert(node->left, key);
        node->left = lchild;

        lchild->parent = node;
    }
    else if (key > node->key)
    {
        TreeNode *rchild = insert(node->right, key);
        node->right = rchild;

        rchild->parent = node;
    }

    return node;
}

//--------------------------------------------------- Tree


class List {

public:
    class ListNode {
    public:
        int key;
        ListNode *next;
        ListNode() = default;
        explicit ListNode(int key) {
            this->key = key;
            this->next = NULL;
        }
    };

    int listSize = 0;
    inline static int count;
    ListNode *head = NULL, *current = NULL;
public:
//--------------------------------- Constructors
    List() {
        count++;
    }

    explicit List(int count) {
        List::count++;
        for(int i = 0; i < count; i++) {
            if (head == NULL) {
                head = new ListNode();
                current = head;
                this->listSize++;
            }
            else {
                auto *node = new ListNode();
                current->next = node;
                current = node;
                this->listSize++;
            }
        }
    }
    List(initializer_list<int> l) {
        List::count++;
        std::initializer_list<int>::iterator it = l.begin();
        for(int i = 0; i < l.size(); i++) {
            if (head == NULL) {
                head = new ListNode(*it);
                current = head;
                this->listSize++;
            }
            else {
                auto *node = new ListNode(*it);
                current->next = node;
                current = node;
                this->listSize++;
            }
            *it++;
        }
    }
    List(List &list) {
        List::count++;
        this->head = list.head;
        this->current = list.current;
        this->listSize = list.listSize;
    }

//------------------------Methods
   static int countinstances() {
        return List::count;
    }

    void insert(int key, int index) {
    if (head == NULL) {
        head = new ListNode(key);
        current = head;
        this->listSize++;
    } else {
        ListNode *currentNode = head;
        for(int i = 0; i <= index - 1; i++) {
            if (i == index - 1) {
                auto *node = new ListNode(key);
                ListNode *temp = currentNode->next;
                currentNode->next = node;
                node->next = temp;
            }
            currentNode = currentNode->next;
        }
    }

}
    void pushBack(int key) {
        if (head == NULL) {
            head = new ListNode(key);
            current = head;
            this->listSize++;
        }
        else {
            auto *node = new ListNode(key);
            current->next = node;
            current = node;
            this->listSize++;
        }
    }
    void erase(int index) {
    ListNode *currentNode = this->head;
    ListNode *tempOne = NULL;
    if (index > 0) {
        for(int i = 0; i <= index; i++) {
            if (i == index - 1) {
                tempOne = currentNode;
            }
            else if (i == index) {
                if (currentNode->next != NULL) {
                    ListNode *tempTwo = currentNode->next;
                    tempOne->next = tempTwo;
                }
                else {
                    tempOne->next = NULL;
                }
            }
            currentNode = currentNode->next;
        }
    }
    else if (index == 0) {
        this->head = this->head->next;
    }

    }

    int size() {
        return this->listSize;
    }

    void printList() {
        if (head != NULL) {
            ListNode *node;
            node = head;
            while (node != nullptr) {
                cout << node->key << " ";
                node = node->next;
            }
        }
    }
    List operator + (List *list) const  {
    ListNode *cNode = this->head;
    int size = list->listSize;
        for (int i = 0; i < size; i++) {
            list->pushBack(cNode->key);
            cNode = cNode->next;
        }
        return *list;
    }

    int operator [] (int index)  {
        ListNode *cNode = this->head;
        for (int i = 0; i < this->size(); i++) {
            if (i == index) {
                return cNode->key;
            }
            cNode = cNode->next;
        }
        return -1;
    }

    static int square(int x) {
        //define square function
        return x*x;
    }

  void transformTest() {
       int arr[this->listSize];
       ListNode *ptr = this->head;
       for (int i = 0; i < this->listSize; i++) {
           arr[i] = ptr->key;
           ptr = ptr->next;
       }
       int res[this->listSize];
       std::transform(arr, arr+this->listSize, res, square);
       ptr = this->head;
       for(int i = 0; i<this->listSize; i++) {
           ptr->key = res[i];
           ptr = ptr->next;
       }
}
};
int main()
{
    cout << "-------------Binary Search Tree part --------------\n";
    int num, key;
    struct TreeNode *root = NULL;
    cout<<"------ Number of nodes you want to insert in binary search tree --------\n";
    cin>>num;
    for (int i = 0; i < num; i++) {
        cout<<"Add key for node " << i+1 << endl;
        cin>>key;
        if (root == NULL)
            root = insert(root, key);
        else {
            insert(root, key);
        }
    }
    cout << "-------------------------------------" << endl;
    cout << "Printing binary search tree (printTree)" << endl;
    printTree(root);

    cout << "-------------- Turning to List part ----------------\n";
    List *list, *listTwo;
    cout << "------- Default constructor call ---------\n";
    list = new List();
    cout << "------- List(count) constructor call ---------\n";
    listTwo = new List(4);
    cout << "------- List constructor with initializer list with values 1, 2, 3 ---------\n";
    List *listThree = new List({1,2,3}); //for initializer list
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
    cout << List::countinstances() << endl;
    cout << "-------- size of list one is three, calling from function to check it\n";
    cout << list->size() << endl;

    cout << "---- Testing + operator.. applaying on two lists with values (1,2,3) (1,2,3)\n";
    list->operator+(listThree);
    listThree->printList();
    cout << endl;

    cout << "---- Testing [] operator.. on list with values (1,2,3) -- accessing 0th index\n";
    cout << listThree->operator[](0);

    cout << "---testing transform method---\n";
    listThree->transformTest();
    listThree->printList();

    cout << "---testing for insertion at specific index in list---\n";
        int index, keyTwo;
    cout << "Enter index you want to insert node at:";
    cin>>index;
    if (index <= list->size()) {
        cout << "Enter key:";
        cin>>keyTwo;
        list->insert(keyTwo, index);
    } else {
        cout << "Invalid index" << endl;
    }
    return 0;
}