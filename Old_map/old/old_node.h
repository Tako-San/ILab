#ifndef MAP_OLD_NODE_H
#define MAP_OLD_NODE_H

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

    Node * add(size_t new_key, Data new_val);

    void set_key(size_t new_key);
    void set_val(Data new_val);
    void set_parent(Node * new_parent);
    void set(size_t new_key, Data new_val, Node * new_parent = nullptr);

    void print();

    Node* find(size_t fkey);
};

/*class Node
{
public:
    Data_t data;

    Node * parent;
    Node * left;
    Node * right;

public:

    Node();
    Node(size_t new_key);
    Node(size_t new_key, Data new_val);

    Node * add(size_t new_key, Data new_val);

    void set_key(size_t new_key);
    void set_val(Data new_val);
    void set_parent(Node * new_parent);
    void set(size_t new_key, Data new_val, Node * new_parent = nullptr);

    void print();

    Node* find(size_t fkey);
};*/

#endif //MAP_OLD_NODE_H
