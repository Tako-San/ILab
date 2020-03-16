#include "map.h"
#include "node.h"
#include "tree.h"

int main()
{
    //test1.1
    printf("\ntest1.1\n");

    Map_t m1(15, 5);
    Map_t m2(4, 4);
    Map_t m3(m2);

    std::cout<<m2<<"\n"<<m1<<"\n"<<m3<<"\n";

    //test1.2
    printf("\ntest1.2\n");

    int x = (m1>m2)? 1 : 0;
    std::cout<<x<<"\n";
    x = (m1>=m2)? 1 : 0;
    std::cout<<x<<"\n";
    x = (m1<m2)? 1 : 0;
    std::cout<<x<<"\n";
    x = (m1<=m2)? 1 : 0;
    std::cout<<x<<"\n";
    x = (m1==m2)? 1 : 0;
    std::cout<<x<<"\n";

    //test2.1
    printf("\ntest2.1\n");

    Node n1;
    Node n2(m1);
    Node n3(12, 5);

    std::cout<<n3<<n2<<n1<<"\n";

    //test2.2
    printf("\ntest2.2\n");

    n1.set(5);
    n1.right = &n2;
    n2.parent = &n1;
    n2.left = &n3;
    n3.parent = &n2;

    std::cout<<"\n";
    n1.print();
    std::cout<<"\n";

    //test2.3
    printf("\ntest2.3\n");

    Map_t m6(7, 2);

    n1.add(m6);
    std::cout<<"\n";
    n1.print();
    std::cout<<"\n";

    //test2.4
    printf("\ntest2.4\n");

    Map_t m4(78, 9);
    n1.add(m4);
    std::cout<<"\n";
    n1.print();
    std::cout<<"\n";

    //test2.4
    printf("\ntest2.4\n");

    Map_t m5(8, 5);

    Node * q = n1.find(m5);
    std::cout << q << "\n";

    std::cout<<"\n";
    n1.print();
    std::cout<<"\n";

    //test2.4
    printf("\ntest2.4\n");
    q = n1.find(111);
    std::cout << q << "\n";

    //test2.5
    printf("\ntest2.5\n");

    Map_t m0(10, 666);

    Node * n10 = new Node;
    n10->data = m0;


    for(int i = 3; i < 10; i++)
    {
        n10->add(4*i-25, i);
    }

    std::cout<<"\n";
    n10->print();
    std::cout<<"\n";

    //test2.6
    printf("\ntest2.6\n");

    std::cout<<"\n";
    n10->print_leafs();
    std::cout<<"\n";

    //test2.7
    printf("\ntest2.7\n");

    std::cout<<"\n";
    n10->print_lvl(3);
    std::cout<<"\n";
    std::cout << "tree depth is "<< n10->depth() << "\n";
    std::cout << "is tree balanced? " << n10->is_balanced() << "\n";

    //test2.8
    printf("\ntest2.8\n????????????\n");

    n10->del(3);

    std::cout<<"\n";
    n10->print();
    std::cout<<"\n";

    //Node * t = n10->find(3);
    //std::cout << *t << "\n";

    n10->clear();

    //test3.0
    /*printf("\ntest3.0\n");

    Tree tree(9, 5);
    tree.add(7,30);
    tree.add(17, 8);
    tree.add(1, 44);

    std::cout<<"\n";
    tree.print();
    std::cout<<"\n";

    tree[1] = 43;

    std::cout<<"\n";
    tree.print();
    std::cout<<"\n";

    tree.clear();*/

    return 0;
}
