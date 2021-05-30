/*
* AUTHORS: <Tzion Beniaminov>
* Tests for Binatree
*/

#include "doctest.h"
#include "BinaryTree.hpp"
#include <string>
#include <algorithm>

using namespace std;
using namespace ariel;

const int NUM_OF_TESTS = 100;



TEST_CASE("Tests") {
    for(int i= 0 ; i< NUM_OF_TESTS ; i++){
        BinaryTree<int> tree_of_ints;
        tree_of_ints.add_root(i);
        auto it  = tree_of_ints.begin();
        if(it != nullptr){CHECK(*it == i);}
        else{CHECK(it == nullptr);}
    }

     for(int i= 0 ; i< NUM_OF_TESTS ; i++){
        BinaryTree<int> tree_of_ints;
        tree_of_ints.add_right(i, i+3);
        auto it  = tree_of_ints.begin();
        if(it != nullptr){CHECK(*it == i);}
        else{CHECK(it == nullptr);}
    }

     for(int i= 0 ; i< NUM_OF_TESTS ; i++){
        BinaryTree<int> tree_of_ints;
        tree_of_ints.add_left(i, i+3);
        auto it  = tree_of_ints.begin();
        if(it != nullptr){CHECK(*it == i);}
        else{CHECK(it == nullptr);}
    }

}
