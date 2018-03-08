
#ifndef FINDPUBLICANCESTOR_H
#define FINDPUBLICANCESTOR_H

#include <functional>
#include <iostream>
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

    bool GetPath(const ValueType & v, ::std::stack<NodeType *> &path)
    {
        bool reval =  innerPreOrderTraverse(this, path, [v](NodeType *node) {
            if (node == nullptr) return false;
            return node->_data != v;
        });
    }

    BinTreeNode<T> *GetPublicAncestor(const ValueType &va, const ValueType &vb)
    {
        ::std::stack<NodeType *> nodeAPath;
        GetPath(va, nodeAPath);

        ::std::stack<NodeType *> nodeBPath;
        GetPath(vb, nodeBPath);

        size_t nAPL = nodeAPath.size();
        size_t nBPL = nodeBPath.size();

        if (nAPL > nBPL)
        {
            size_t rcount = nAPL - nBPL;
            for (size_t i = 0; i != rcount; ++i)
            {
                nodeAPath.pop();
            }
        }

        if (nAPL < nBPL)
        {
            size_t rcount = nBPL - nAPL;
            for (size_t i = 0; i != rcount; ++i)
            {
                nodeBPath.pop();
            }
        }

        while (!nodeAPath.empty())
        {
            NodeType *topA = nodeAPath.top();
            NodeType *topB = nodeBPath.top();
            if (topA == topB) return topA;

            nodeAPath.pop();
            nodeBPath.pop();
        }

        return nullptr;
    }

    ValueType GetVal() { return _data; }
   protected:
   private:
    BinTreeNode<T> *_left;
    BinTreeNode<T> *_right;
    ValueType _data;


    bool innerPreOrderTraverse(BinTreeNode<T> *node,
                               ::std::stack<NodeType *> &tstack,
                               const ::std::function<bool(NodeType *)> &tf)
    {
        if(!tf(node)) return true;

        tstack.push(node);

        if(innerPreOrderTraverse(node->_left, tstack, tf)) return true;
        if(innerPreOrderTraverse(node->_right, tstack, tf)) return true;

        tstack.pop();
        return false;
    }

    void innerPreOrderTraverse2(BinTreeNode<T> *node,
                               ::std::stack<NodeType *> &tstack,
                               ::std::function<bool(NodeType *)> &tf)
    {
        while (node || !tstack.empty())
        {
            if (node)
            {
                tstack.push(node);
                ::std::cout << "PushNode :" << node->GetVal() << ::std::endl;
                node = node->_left;
            }
            else
            {
                node = tstack.top();
                ::std::cout << "CheckNode :" << node->GetVal() << ::std::endl;

                if (!tf(node))
                {
                    return;
                }

                ::std::cout << "PopNode :" << node->GetVal() << ::std::endl;
                tstack.pop();
                node = node->_right;
            }
        }
    }
};

template <typename T>
using BinTree = BinTreeNode<T>;

#endif /* FINDPUBLICANCESTOR_H */
