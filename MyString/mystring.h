#ifndef MY_STRING
#define MY_STRING

#include <cstdio>
#include <cstring>
//#include <string>

#define CAP 50

namespace F
{
    class String
    {
    public:

        char str[CAP];
        size_t cap;
        size_t size;

    public:

        String();
        String(String &a);
        String(const char str[]);

        void print();
        size_t length();
        size_t capacity();
        bool empty();

        

    };

    size_t my_strcpy(char *dst, const char *src);
}

#endif /* MY_STRING */
