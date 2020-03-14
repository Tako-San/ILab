#include "mystring.h"

using namespace F;

int main()
{
    //test 1
    printf("\ntest1\n");
    String a("Hello");
    String b(a);

    //test2
    printf("\ntest2\n");
    a.print();
    printf("\n");
    b.print();
    printf("\n");

    //test3
    printf("\ntest3\n");
    printf("b length is %ld\n", b.length());
    printf("a capacity is %ld\n", a.capacity());

    //test4
    printf("\ntest4\n");
    if(!a.empty())
        printf("a is not empty\n");

    String k;

    if(k.empty())
        printf("k is empty\n");

    //test5
    printf("\ntest5\n");
    a.clear();
    if(a.empty())
        printf("a is empty\n");

    //test6
    printf("\ntest6\n");
    b.push_back('!');
    b.print();
    printf("\n");

    //test7
    printf("\ntest7\n");
    b.pop_back();
    b.print();
    printf("\n");

    //test8
    printf("\ntest8\n");
    a.push_back('$');
    a += b;
    a.print();
    printf("\n");

    //test9
    printf("\ntest9\n");
    k.push_back('9');
    a += (b += k);
    a.print();
    printf("\n");

    //test10
    printf("\ntest10\n");
    a += "sh";
    a.print();
    printf("\n");

    //test11
    printf("\ntest11\n");
    k = a;
    k.print();
    printf("\n");

    //test12
    printf("\ntest12\n");
    String c = b;
    c.print();
    printf("\n");

    //test 13
    printf("\ntest13\n");
    c = "Shit";
    c.print();
    printf("\n");

    //test14
    printf("\ntest14\n");
    String d = "ACAB";
    d.print();
    printf("\n");

    //test15
    printf("\ntest15\n");
    a.print();
    printf("\n");
    b.print();
    printf("\n");
    String e;
    e = a + b + "Too much functions..." + "I'm tired";
    e.print();
    printf("\n");

    //test16
    printf("\ntest16\n");
    printf("%c\n", d[1]);

    //test17
    printf("\ntest17\n");
    d[1] = 'R';
    d.print();
    printf("\n");

    //test18
    printf("\ntest18\n");
    if(a < b)
        printf("nice\n");
    else if (b < a)
        printf("nice too\n");

    //test19
    printf("\ntest19\n");
    d.erase(1);
    d.print();

    printf("\n");
    return 0;
}
