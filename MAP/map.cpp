#include "map.h"

Map::Map() : root(nullptr)
{
}

Map::Map(size_t key, Data val)
{
    root = new Node;
    root->set(key, val);
}

Node * Map::add(size_t key, Data val)
{
    if(root == nullptr)
    {
        root = new Node;
        root->set(key, val);
        return root;
    }
    else
    {
        return root->add(key, val);
    }
    return nullptr;
}

void Map::print()
{
    if(root == nullptr)
        return;

    root->print();
}

Data& Map::operator[](size_t key)
{
    Node * tmp = find(key);
    if(tmp != nullptr)
        return tmp->val;
    /*else
    {
        Node * tmp = add(key, 0);
        return tmp->val;
    }*/

}

Node* Map::find(size_t key)
{
    return root->find(key);
}