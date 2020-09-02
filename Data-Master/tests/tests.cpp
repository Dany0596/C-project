///@author Daniele Vencato
///@file tests.cpp


#define CATCH_CONFIG_MAIN
#include "../deps/catch.hpp"
#include <string>
#include <assert.h>
#include <vector>
#include <cstring>
#include "../include/BST/BST.h"
#include "../include/List/List.h"


/*TEST
 * BST with integers
 * testing insertion and deletion*/
TEST_CASE("Correct bstint samples", "[bstint]") {
    using namespace std;
    string line;
    ifstream myfile(R"(C:\Users\danie\Desktop\Data-Master\tests\bstint.csv)");
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            const int len = line.length();
            char c[1000];
            strcpy(c, line.c_str());
            auto bst = new BST::BST<int>();

            for (int i = 0; i < line.length(); i++) {
                if (c[i] == 2) {
                    bst->insert(c[i] - 48);
                    assert(bst->root->data == 2);
                    assert(bst->root->left == nullptr);
                }
                if (c[i] == 1) {
                    bst->insert(c[i] - 48);
                    assert(bst->root->left->data == 1);
                }
                if (c[i] == 3) {
                    bst->insert(c[i] - 48);
                    assert(bst->root->right->data == 3);
                    bst->deleteNode(2);
                    assert(bst->root->data == 3);
                    bst->deleteNode(3);
                    assert(bst->root->data == 1);
                    bst->deleteNode(1);
                    assert(bst->root == nullptr);
                }
            }
        }
        myfile.close();
    } else REQUIRE_THROWS("Unable to open file");

}
/*TEST
 * BST with chars
 * testing insertion and deletion*/
TEST_CASE("Correct bstchars samples", "[bstchars]") {
    using namespace std;
    string line;
    ifstream myfile(R"(C:\Users\danie\Desktop\Data-Master\tests\bstchars.csv)");
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            const int len = line.length();

            char c[1000];
            strcpy(c, line.c_str());
            auto bst = new BST::BST<int>();

            for (int i = 0; i < line.length(); i++) {
                if (c[i] == 'b') {
                    bst->insert(c[i]);
                    assert(bst->root->data == 'b');
                    assert(bst->root->left == nullptr);
                }
                if (c[i] == 'a') {
                    bst->insert(c[i]);
                    assert(bst->root->left->data == 'a');
                }
                if (c[i] == 'c') {
                    bst->insert(c[i]);
                    assert(bst->root->right->data == 'c');
                    bst->deleteNode('b');
                    assert(bst->root->data == 'c');
                }
            }
        }
        myfile.close();
    } else REQUIRE_THROWS("Unable to open file");

}
/*TEST
 * BST duplicates
 * with integers*/
TEST_CASE("Correct bstint_dupplicates samples", "[bstint-dupp]") {
    using namespace std;
    string line;
    ifstream myfile(R"(C:\Users\danie\Desktop\Data-Master\tests\bstint.csv)");
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            char c[1000];
            strcpy(c, line.c_str());
            auto bst = new BST::BST<int>();

            for (int i = 0; i < line.length(); i++) {
                if (c[i] == 2) {
                    bst->insert(c[i] - 48);
                    assert(bst->root->data == 2);
                }
                if (c[i] == 1) {
                    bst->insert(2);
                    assert(bst->root->left == nullptr);
                }
            }
        }
        myfile.close();
    } else REQUIRE_THROWS("Unable to open file");

}
/*TEST
 * List Constructors
 * with integers*/

TEST_CASE("Correct List Constructor samples", "[ListInteger]") {
    using namespace std;
    string line;
    ifstream myfile(R"(C:\Users\danie\Desktop\Data-Master\tests\ListInteger.csv)");
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            char c[1000];
            strcpy(c, line.c_str());
            List::List<int> *list, *listTwo, *listThree, *listFour, *listFive;

            for (int i = 0; i < line.length(); i++) {
                if (i == 0) {
                    list = new List::List<int>();
                    assert(list != nullptr);
                }
                if (i == 1) {
                    listTwo = new List::List<int>(c[i] - 48);
                    assert(listTwo != nullptr);
                }
                if (i == 2) {
                    listThree = new List::List<int>({c[i - 2] - 48, c[i - 1] - 48, c[i] - 48});
                    assert(listThree->head->key == 1);
                    assert(listThree->head->next->key == 2);
                    assert(listThree->head->next->next->key == 3);
                }
                if (i == 3) {
                    listFour = new List::List<int>();
                    listFour->insert(1, 0);
                    assert(listFour->head != nullptr);
                    listFive = new List::List<int>(*listFour);
                    assert(listFive->head != nullptr);
                }
            }
        }
        myfile.close();
    } else REQUIRE_THROWS("Unable to open file");

}
/*TEST
 * List Size
 * with integers*/

TEST_CASE("Correct Size Test samples", "[Size]") {
    using namespace std;
    string line;
    auto *list = new List::List<int>({1, 2, 3, 4, 5});
    assert(list->size() == 5);

}
/*TEST
 * List Pushback and Insert at specific index
 * with Integers
 * */

TEST_CASE("Correct pushback samples", "[pushback]") {
    using namespace std;
    string line;
    ifstream myfile(R"(C:\Users\danie\Desktop\Data-Master\tests\ListInteger.csv)");
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            char c[1000];
            strcpy(c, line.c_str());
            auto *list = new List::List<int>();

            for (int i = 0; i < line.length(); i++) {
                if (i == 0) {
                    list->pushBack(c[i] - 48);
                    assert(list->head != nullptr);
                }
                if (i == 1) {
                    list->insert(c[i] - 48, 1);
                    assert(list->head->next != nullptr);
                }

            }
        }
        myfile.close();
    } else REQUIRE_THROWS("Unable to open file");
}
/*TEST
 * List erase
 * with Integers
 * */

TEST_CASE("Correct List Erase samples", "[listErase]") {
    using namespace std;
    string line;
    ifstream myfile(R"(C:\Users\danie\Desktop\Data-Master\tests\ListInteger.csv)");
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            char c[1000];
            strcpy(c, line.c_str());
            auto *list = new List::List<int>();

            for (int i = 0; i < 3; i++) {
                if (i == 0) {
                    list->pushBack(c[i] - 48);
                }
                if (i == 1) {
                    list->insert(c[i] - 48, 1);
                }
                if (i == 2) {
                    list->erase(1);
                    assert(list->head->next == nullptr);
                }

            }
        }
        myfile.close();
    } else REQUIRE_THROWS("Unable to open file");

}
/*TEST
 * List PlusOperator
 * with Integers
 * */

TEST_CASE("Correct List Operator samples", "[listPlus]") {
    using namespace std;
    string line;
    ifstream myfile (R"(C:\Users\danie\Desktop\Data-Master\tests\ListInteger.csv)");
    if (myfile.is_open())
    {
        while (getline (myfile,line))
        {
            char c[1000];
            strcpy(c, line.c_str());
            auto *list = new List::List<int>();
            auto *listTwo = new List::List<int>();

            for (int i= 0; i<line.length(); i++) {
                list->pushBack(c[i]-48);
            }

            for (int i= 0; i<line.length(); i++) {
                listTwo->pushBack(c[i]-48);
            }
            list->operator+(listTwo);
            assert(listTwo->size() == list->size()*2);
        }
        myfile.close();
    }
    else REQUIRE_THROWS("Unable to open file");
}

/*TEST
 * List BracketOperator
 * with Integers
 * */

TEST_CASE("Correct List Bracket Operator Erase samples", "[listBracket]") {
    using namespace std;
    string line;
    ifstream myfile (R"(C:\Users\danie\Desktop\Data-Master\tests\ListInteger.csv)");
    if (myfile.is_open())
    {
        while (getline (myfile,line))
        {
            char c[1000];
            strcpy(c, line.c_str());
            auto *list = new List::List<int>();

            for (int i= 0; i<line.length(); i++) {
                list->pushBack(c[i]-48);
            }
            int indexVal = list->operator[](0);
            assert(indexVal == 1);
            indexVal = list->operator[](1);
            assert(indexVal == 2);
            indexVal = list->operator[](2);
            assert(indexVal == 3);
            indexVal = list->operator[](3);
            assert(indexVal == 4);
        }
        myfile.close();
    }
    else REQUIRE_THROWS("Unable to open file");
}

/*TEST
 * List std::transform
 * with Integers
 * */

TEST_CASE("Correct List Transform samples", "[listTransform]") {
    using namespace std;
    string line;
    ifstream myfile (R"(C:\Users\danie\Desktop\Data-Master\tests\ListInteger.csv)");
    if (myfile.is_open())
    {
        while (getline (myfile,line))
        {
            char c[1000];
            strcpy(c, line.c_str());
            auto *list = new List::List<int>();

            for (int i= 0; i<line.length(); i++) {
                list->pushBack(c[i]-48);
            }
            list->transformHelper();
            assert(list->operator[](0) == (c[0]-48)*(c[0]-48));
            assert(list->operator[](1) == (c[1]-48)*(c[1]-48));
            assert(list->operator[](2) == (c[2]-48)*(c[2]-48));
            assert(list->operator[](3) == (c[3]-48)*(c[3]-48));
        }
        myfile.close();
    }
    else REQUIRE_THROWS("Unable to open file");
}
