#ifndef MAP
#define MAP

#include <cstdio>
#include "node.h"
#define Data int


class Map
{
    Node * root;

public:

    Map();
    Map(size_t key, Data val);

    void print();

    Node * add(size_t key, Data val);
    Data& operator[](size_t usr_key);

    Node* find(size_t key);


};


#endif //MAP
