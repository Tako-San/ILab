#include "mystring.h"

using namespace F;

int main()
{
    //test 1
    String a("Hello");
    String b(a);

    //test2
    a.print();
    printf("\n");
    b.print();
    printf("\n");

    //test3
    printf("b length is %ld\n", b.length());
    printf("a capacity is %ld\n", a.capacity());

    //test4
    if(!a.empty())
        printf("a is not empty\n");

    String k;

    if(k.empty())
        printf("k is empty\n");

    //test5

    a.clear();
    if(a.empty())
        printf("a is empty\n");

    //test6

    b.push_back('!');
    b.print();
    printf("\n");

    //test7

    b.pop_back();
    b.print();
    printf("\n");

    //test8

    a.push_back('$');
    a += b;
    a.print();
    printf("\n");

    //test9

    k.push_back('9');
    a += (b += k);
    a.print();
    printf("\n");

    //test10

    a += "sh";
    a.print();
    printf("\n");

    //test11

    k = a;
    k.print();
    printf("\n");

    //test12

    String c = b;
    c.print();
    printf("\n");

    //test 13

    c = "Shit";
    c.print();
    printf("\n");

    //test14

    String d = "ACAB";
    d.print();
    printf("\n");
    return 0;

    //test15

    printf("%c\n", d[1]);

    return 0;
}
