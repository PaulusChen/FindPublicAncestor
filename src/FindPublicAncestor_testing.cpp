
#include <gtest/gtest.h>
#include <iostream>

using namespace std;

#include "FindPublicAncestor.hpp"


TEST(basic,BTGetPath) {

    /*
            5
          /   \
        1        2
      /   \    /   \
     7     3  4     6
    / \
   9   8
    \
     0
    */



    using NT = BinTree<int>::NodeType;

    BinTree<int> n5(5);
    NT *n1 = n5.CreateLeft(1);
    NT *n3 = n1->CreateRight(3);
    NT *n7 = n1->CreateLeft(7);

    NT *n9 = n7->CreateLeft(9);
    NT *n0 = n9->CreateRight(0);

    NT *n8 = n7->CreateRight(8);

    NT *n2 = n5.CreateRight(2);
    NT *n4 = n2->CreateLeft(4);
    NT *n6 = n2->CreateRight(6);

    std::stack<NT *> n3Path;
    n5.GetPath(3,n3Path);

    while(n3Path.size() != 0) {
        cout<<n3Path.top()->GetVal()<<endl;
        n3Path.pop();
    }

    std::stack<NT *> n9Path;
    n5.GetPath(9,n9Path);

    while(n9Path.size() != 0) {
        cout<<n9Path.top()->GetVal()<<endl;
        n9Path.pop();
    }


    // ASSERT_EQ(n3Path.top()->GetVal(), 1);
    // n3Path.pop();

    // ASSERT_EQ(n3Path.top()->GetVal(), 5);
    // n3Path.pop();

}

TEST(basic,GetPublicAncestor) {

    /*
                   5
                 /   \
              1        2
            /   \    /   \
           7     3  4     6
          / \
         9   8
          \
          0
     */

    using NT = BinTree<int>::NodeType;

    NT n5(5);
    NT *n1 = n5.CreateLeft(1);
    NT *n3 = n1->CreateRight(3);
    NT *n7 = n1->CreateLeft(7);

    NT *n9 = n7->CreateLeft(9);
    NT *n0 = n9->CreateRight(0);

    NT *n8 = n7->CreateRight(8);

    NT *n2 = n5.CreateRight(2);
    NT *n4 = n2->CreateLeft(4);
    NT *n6 = n2->CreateRight(6);

    BinTree<int>::NodeType *ancestor = n5.GetPublicAncestor(9, 3);
    ASSERT_EQ(ancestor,n1);

    ancestor = n5.GetPublicAncestor(3, 4);
    ASSERT_EQ(ancestor, &n5);

    ancestor = n5.GetPublicAncestor(0, 3);
    ASSERT_EQ(ancestor,n1);
}
