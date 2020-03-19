#include "old_node.h"

Node::Node() : key(0),
               val{0},
               parent(nullptr),
               left(nullptr),
               right(nullptr)
{
}

Node::Node(size_t new_key) : key(new_key),
                             val{0},
                             parent(nullptr),
                             left(nullptr),
                             right(nullptr)
{
}

Node::Node(size_t new_key, Data new_val) : key(new_key),
                                           val(new_val),
                                           parent(nullptr),
                                           left(nullptr),
                                           right(nullptr)
{
}

Node * Node::add(size_t new_key, Data new_val)
{
#define DIRTY_JOB(side)                        \
    if(side != nullptr)                        \
        return side->add(new_key, new_val);    \
    else                                       \
    {                                          \
        side = new Node;                       \
        side->set(new_key, new_val, this);     \
        printf("\n%p %p\n", left, right);      \
        return side;                           \
    }                                          \

    if(new_key < key)
    {
        printf("%ld < %ld\n", new_key, key);
        DIRTY_JOB(left)
    }
    else if(new_key > key)
    {
        DIRTY_JOB(right)
    }

    return nullptr;

}

void Node::set_key(size_t new_key)
{
    key = new_key;
}

void Node::set_val(Data new_val)
{
    val = new_val;
}

/*void Node::set_left(Node * new_left)
{
    left = new_left;
}

void Node::set_right(Node * new_right)
{
    right = new_right;
}*/

void Node::set_parent(Node * new_parent)
{
    parent = new_parent;
}

void Node::set(size_t new_key, Data new_val, Node * new_parent)
{
    set_key(new_key);
    set_val(new_val);
    set_parent(new_parent);
}

void Node::print()
{
    if(left != nullptr)
        left->print();

    std::cout<<key<<": "<<val<<'\n';

    if(right != nullptr)
        right->print();
}


Node* Node::find(size_t fkey)
{
    if(fkey == key)
        return this;
    else if(fkey < key && left != nullptr)
        return left->find(fkey);
    else if(fkey > key && right != nullptr)
        return right->find(fkey);

    return nullptr;
}