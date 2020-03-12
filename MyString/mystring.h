#ifndef MY_STRING
#define MY_STRING

#include <cstdio>
#include <cstring>
#include <cassert>
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

        ~String();

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
        String& operator=(const char * to_eq);

        String& operator+(const String& term2) const;
        //String& operator+(const String& term2) const;

        char& operator[](size_t pos);


    };

    size_t my_strcpy(char *dst, const char *src);
}

#endif /* MY_STRING */
