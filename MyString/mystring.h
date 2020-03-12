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

        char str[CAP + 1];
        size_t cap;
        size_t size;

    public:

        String();
        String(const String &a);
        String(const char str[]);

        void print();
        size_t length();
        size_t capacity();
        bool empty();

        void clear();
        void push_back(char new_letter);
        char pop_back();
        String& operator+=(const String& to_add);
        String& operator+=(const char * to_add);

        String& operator=(const String& to_eq);

    };

    size_t my_strcpy(char *dst, const char *src);
}

#endif /* MY_STRING */
