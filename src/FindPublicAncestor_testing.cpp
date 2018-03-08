
#include "FindPublicAncestor.hpp"

TEST() {

    BinTree<int> testTree(5);
    BinTree<int>::NodeType *tmpNode = nullptr;
    BinTree<int>::NodeType *nodeA = testTree.CreateLeft(1);
    BinTree<int>::NodeType *nodeB = testTree.CreateRight(2);

    BinTree<int>::NodeType *acestor = testTree.GetPublicAcestor(nodeA, nodeB);

}
