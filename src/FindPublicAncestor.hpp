
#ifndef FINDPUBLICANCESTOR_H
#define FINDPUBLICANCESTOR_H

#include <stack>

template <typename T>
class BinTreeNode
{
    using ValueType = T;

   public:
    using NodeType = BinTreeNode<ValueType>;

    //! Default constructor
    BinTreeNode(ValueType val) : _left(nullptr), _right(nullptr), _data(val) {}
    //! Copy constructor
    BinTreeNode(const BinTreeNode<T> &other) = delete;

    //! Move constructor
    BinTreeNode(BinTreeNode<T> &&other) = delete;

    //! Destructor
    virtual ~BinTreeNode() noexcept {}
    //! Copy assignment operator
    BinTreeNode<T> &operator=(const BinTreeNode<T> &other) = delete;

    //! Move assignment operator
    BinTreeNode<T> &operator=(BinTreeNode<T> &&other) = delete;

    BinTreeNode<T> *CreateLeft(ValueType val)
    {
        _left = new NodeType(val);
        return _left;
    }

    BinTreeNode<T> *CreateRight(ValueType val)
    {
        _right = new NodeType(val);
        return _right;
    }

    void GetPath(BinTreeNode<T> *node, ValueType v,
                 std::stack<NodeType *> &tstack)
    {
        while (node || !tstack.empty())
        {
            if (node->_value == v)
            {
                return;
            }
            if (node)
            {
                tstack.push(node);
                node = node->_left;
            }
            else
            {
                node = tstack.top();
                tstack.pop();
                node = node->_right;
            }
        }
    }

    BinTreeNode<T> *GetPublicAncestor(BinTreeNode<T> *nodeA,
                                      BinTreeNode<T> *nodeB)
    {
        if (nodeA == nullptr || nodeB == nullptr) return nullptr;

        // TODO: implement it
        return nullptr;
    }

   protected:
   private:
    BinTreeNode<T> *_left;
    BinTreeNode<T> *_right;
    ValueType _data;
};

template <typename T>
using BinTree = BinTreeNode<T>;

#endif /* FINDPUBLICANCESTOR_H */
