
#ifndef FINDPUBLICANCESTOR_H
#define FINDPUBLICANCESTOR_H

#include <stack>

template<typename T>
class BinTreeNode
{
    using ValueType = T;
public:
    using NodeType = BinTreeNode<ValueType>;

    //! Default constructor
    BinTreeNode(ValueType val) : _left(nullptr), _right(nullptr), _data(val) {
    }

    //! Copy constructor
    BinTreeNode(const BinTreeNode<T> &other) = delete;

    //! Move constructor
    BinTreeNode(BinTreeNode<T> &&other) = delete;

    //! Destructor
    virtual ~BinTreeNode() noexcept {
    }

    //! Copy assignment operator
    BinTreeNode<T>& operator=(const BinTreeNode<T> &other) = delete;

    //! Move assignment operator
    BinTreeNode<T>& operator=(BinTreeNode<T> &&other) = delete;

    BinTreeNode<T> *CreateLeft(ValueType val) {
        _left = new NodeType(val);
        return _left;
    }


    BinTreeNode<T> *CreateRight(ValueType val) {
        _right = new NodeType(val);
        return _right;
    }

    BinTreeNode<T> *GetPublicAncestor(BinTreeNode<T> *nodeA, BinTreeNode<T> *nodeB) {
        //TODO: implement it
        return nullptr;
    }

protected:
private:
    BinTreeNode<T> *_left;
    BinTreeNode<T> *_right;
    ValueType _data;

    std::stack<BinTreeNode<T> *> &&getPath(BinTreeNode<T> *node) {
        //TODO: implement it
        return nullptr;
    }
};


template<typename T>
using BinTree = BinTreeNode<T>;


#endif /* FINDPUBLICANCESTOR_H */
