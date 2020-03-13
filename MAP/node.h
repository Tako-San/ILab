#ifndef MAP_NODE_H
#define MAP_NODE_H

#include <cstdio>
#include <iostream>

#define Data int

class Node
{
public:
    size_t key;
    Data val;

    Node * parent;
    Node * left;
    Node * right;

public:

    Node();
    Node(size_t new_key);
    Node(size_t new_key, Data new_val);

    //size_t get_key();
    Node * add(size_t new_key, Data new_val);

    void set_key(size_t new_key);
    void set_val(Data new_val);
    void set_parent(Node * new_parent);
    /*void set_left(Node * new_left);
    void set_right(Node * new_right);*/
    void set(size_t new_key, Data new_val, Node * new_parent = nullptr);

    void print();

    Node* find(size_t fkey);
};

#endif //MAP_NODE_H
