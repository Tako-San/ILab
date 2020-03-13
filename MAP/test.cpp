#include "map.h"

int main()
{
    //test1
    printf("\ntest1\n");
    Node a(0, 3);
    a.print();

    //test2
    printf("\ntest2\n");
    Map map(3, 4);
    map.print();

    //test3
    printf("\ntest3\n");
    map.add(5, 1);
    map.print();

    //test4
    printf("\ntest4\n");
    map.add(13, 43);
    map.add(34, 84123);
    map.add(4, 566);
    map.add(4, 45);
    map.add(790, 5345);
    map.add(143, 43);
    /*map.add(344, 84123);
    map.add(44, 566);
    map.add(42, 45);
    map.add(70, 5345);*/
    map.print();

    //test4
    printf("\ntest4\n");
    printf("Key = 4, val = %d\n", map[4]);
    map[4] = 666;
    printf("Key = 4, val = %d\n", map[4]);
    map.print();

    //test5
    /*printf("\ntest5\n");
    map[10] = 49;
    map.print();*/


    return 0;
}
