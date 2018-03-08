
#include "FindPublicAncestor.hpp"

TEST(BTGetPath) {

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
    NT *n4 = n2->CreateRight(6);

    BinTree<int>::NodeType *acestor = testTree.GetPublicAcestor(n9, n3);
    ASSERT_EQ(accestor,n1);

}
