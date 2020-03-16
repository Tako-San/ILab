#include "node.h"

Node::Node() : data(),
               parent(nullptr),
               left(nullptr),
               right(nullptr)
{
    std::cout<<"Node constructor without arguments. "<<this<<"\n\n";
}

Node::Node(Data_t &n_data) : data(n_data),
                             parent(nullptr),
                             left(nullptr),
                             right(nullptr)
{
    std::cout<<"Node constructor with n_data. "<<this<<"\n\n";
}

Node::Node(key_t key, val_t val) : data(key, val),
                                   parent(nullptr),
                                   left(nullptr),
                                   right(nullptr)
{
    std::cout<<"Node constructor with key, val. "<<this<<"\n\n";
}



std::ostream& operator<< (std::ostream &out, const Node &node)
{
    out<<"Data: ("<<node.data<<"), this: "<<&node<<", parent: "<<node.parent<<", left: "<<node.left<<", right: "<<node.right<<"\n";

    return out;
}



void Node::set(key_t key, val_t val, Node * n_parent)
{
    data = Map_t(key, val);
    parent = n_parent;
}

void Node::set(Data_t &n_data, Node * n_parent)
{
    data = n_data;
    parent = n_parent;
}



void Node::print()
{
    if(left != nullptr)
        left->print();

    std::cout<<*this;

    if(right != nullptr)
        right->print();
}

void Node::print_leafs()
{
    if(this == nullptr)
        return;

    if(left == nullptr && right == nullptr)
        std::cout << data <<"\n";
    else
    {
        left->print_leafs();
        right->print_leafs();
    }
}

void Node::print_lvl(int lvl)
{
    if(this == nullptr)
        return;
    else if(lvl == 0)
        std::cout << *this;
    else if(lvl > 0)
    {
        left->print_lvl(lvl - 1);
        right->print_lvl(lvl - 1);
    }
    else
        return;
}

void Node::clear()
{
    if(this == nullptr)
        return;

    if(left != nullptr)
        left->clear();
    if(right != nullptr)
        right->clear();
    delete this;
    std::cout << "\nDYNAMYC MEMORY: DELETE\n";
}


Node * Node::add(Data_t &n_data)
{
#define DIRTY_JOB(side)                        \
    if(side != nullptr)                        \
        return side->add(n_data);              \
    else                                       \
    {                                          \
        side = new Node;                       \
        side->set(n_data, this);               \
        return side;                           \
    }                                          \

    std::cout<<"\nADD FUNC\n";

    if(n_data < data)
    {
        DIRTY_JOB(left)
    }
    else if(n_data > data)
    {
        DIRTY_JOB(right)
    }

    return nullptr;

#undef DIRTY_JOB
}

Node * Node::add(key_t key, val_t val)
{
#define DIRTY_JOB(side)                        \
    if(side != nullptr)                        \
        return side->add(key, val);            \
    else                                       \
    {                                          \
        std::cout << "\nDYNAMYC MEMORY: NEW\n";\
        side = new Node;                       \
        side->set(key, val, this);             \
        return side;                           \
    }                                          \

    //std::cout<<"\nADD FUNC\n";

    if(key < data)
    {
        DIRTY_JOB(left)
    }
    else if(key > data)
    {
        DIRTY_JOB(right)
    }

    return nullptr;

#undef DIRTY_JOB
}



Node * Node::find(Data_t &n_data)
{
    if((n_data > data) && (right != nullptr))
        return right->find(n_data);
    else if((n_data < data) && (left != nullptr))
        return left->find(n_data);
    else if(n_data == data)
        return this;
    return nullptr;
}

Node * Node::find(key_t key)
{
    printf("\n\nQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ\n\n");
    if((key > data) && (right != nullptr))
        return right->find(key);
    else if((key < data) && (left != nullptr))
        return left->find(key);
    else if(key == data)
    {
        printf("!FOUND IT!\n\n");
        return this;
    }
    return nullptr;
}


int Node::depth()
{
    if(this == nullptr)
        return 0;

    int depth = 1;

    int depth_l = left->depth();
    int depth_r = right->depth();

    int subtr_max = (depth_l > depth_r)? depth_l : depth_r;

    depth += subtr_max;

    return depth;
}

bool Node::is_balanced()
{
    int res = abs(left->depth() - right->depth()) <= 1 ? 1 : 0;
    return res;
}

/*void Node::del(Data_t &to_del)
{
    Node * del_n = find(to_del);

    printf("here we go\n");

    Node * del_rt = del_n->right;
    Node * del_lt = del_n->left;
    Node * del_pa = del_n->parent;


#define FORGIVE_AND_FORGET()           \
    tmp->parent = del_pa;              \
    tmp->left = del_lt;                \
    tmp->right = del_rt;               \
                                       \
    del_lt->parent = tmp;              \
    del_rt->parent = tmp;              \
    if(del_pa == nullptr)              \
        printf("parent - nullptr\n");  \
    else if(del_pa->left == del_n)     \
        del_pa->left = tmp;            \
    else                               \
        del_pa->right = tmp;           \


    if(del_lt->depth() > del_rt->depth())
    {
        Node * tmp;
        for(tmp = del_lt; tmp->right != nullptr; tmp = tmp->right);

        tmp->parent->right = nullptr; //Родитель крайнего эл-та о нем забывает
        FORGIVE_AND_FORGET()
    }
    else
    {
        Node * tmp;
        for(tmp = del_rt; tmp->left != nullptr; tmp = tmp->left);

        tmp->parent->left = nullptr; //Родитель крайнего эл-та о нем забывает
        FORGIVE_AND_FORGET()
    }

    //delete del_n;

#undef FORGIVE_AND_FORGET
}*/

/*void Node::del(key_t key)
{
    Node * del_n = find(key);
    if(del_n == nullptr)
        return;

    Node * del_rt = del_n->right;
    Node * del_lt = del_n->left;
    Node * del_pa = del_n->parent;

#define FORGIVE_AND_FORGET()           \
    tmp->parent = del_pa;              \
    tmp->left = del_lt;                \
    tmp->right = del_rt;               \
                                       \
    del_lt->parent = tmp;              \
    del_rt->parent = tmp;              \
    if(del_pa == nullptr)              \
        printf("parent - nullptr\n");  \
    else if(del_pa->left == del_n)     \
        del_pa->left = tmp;            \
    else                               \
        del_pa->right = tmp;           \


    if(del_lt->depth() > del_rt->depth())
    {
        Node * tmp = del_lt;
        for(; tmp->right != nullptr; tmp = tmp->right);

        if(tmp->left != nullptr)
        {
            tmp->left->parent = tmp->parent;
            tmp->parent->right = tmp->left;
        }
        else
            tmp->parent->left = nullptr;


        //tmp->parent->right = nullptr;
        // Родитель крайнего эл-та о нем забывает
        FORGIVE_AND_FORGET()
    }
    else
    {
        Node * tmp = del_rt;
        for(; tmp->left != nullptr; tmp = tmp->left);

        if(tmp->right != nullptr)
        {
            tmp->right->parent = tmp->parent;
            tmp->parent->left = tmp->right;
        }
        else
            tmp->parent->right = nullptr;

        //FORGIVE_AND_FORGET()

        tmp->parent = del_pa;
        tmp->left = del_lt;
        tmp->right = del_rt;

        del_lt->parent = tmp;
        del_rt->parent = tmp;

        if(del_pa == nullptr)
            printf("parent - nullptr\n");
        else if(del_pa->left == del_n)
            del_pa->left = tmp;
        else
            del_pa->right = tmp;

    }

    //delete del_n;

#undef FORGIVE_AND_FORGET

}*/

void Node::del(key_t key)
{
    Node * del_n = find(key);
    if(del_n == nullptr)
        return;

    Node * del_rt = del_n->right;
    Node * del_lt = del_n->left;
    Node * del_pa = del_n->parent;

    if(del_rt == del_lt && del_lt == nullptr)
    {
        if(del_n->parent->left == del_n)
            del_n->parent->left = nullptr;
        else
            del_n->parent->right = nullptr;
        delete del_n;
    }

    if(del_rt->depth() > del_lt->depth())
    {
        printf("hiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii\n");
        Node * new_n;

        for(new_n = del_rt; new_n->left != nullptr; new_n = new_n->left)
            ;

        if(new_n->right != nullptr)
        {
            new_n->right->parent = new_n->parent;

            if(new_n->parent->left == new_n)
                new_n->parent->left = new_n->right;
            else
                new_n->parent->right = new_n->right;
        }
        else
            new_n->parent = nullptr;

        new_n->parent = del_pa;
        new_n->right = del_rt;
        new_n->left = del_lt;

        if(del_pa->left == del_n)
            del_pa->left = new_n;
        else
            del_pa->right = new_n;

        del_rt->parent = new_n;
        if(del_lt != nullptr)
            del_lt->parent = new_n;

        delete del_n;
    }
    else
    {
        printf("byeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee\n");
    }
}