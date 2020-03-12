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
    printf("%ld\n", b.length());
    printf("%ld\n", a.capacity());

    //test4
    if(!a.empty())
        printf("sssssssss\n");

    String k;

    if(k.empty())
        printf("sddgssssssss\n");

    

    return 0;
}
