#ifndef MY_STRING
#define MY_STRING

#include <cstdio>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <cctype>
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
        /*String(const String &a, const String &b);
        Возвращать в + конструктор копирования, чтобы избежать лишних копирований
        Придумать конструкторы которые принимают 2 строки и делают новую без лишних копирований
        ключ -о2 оптимизация*/

        ~String();

        void print();
        size_t length();
        size_t capacity();
        bool empty();

        void clear();
        void push_back(char new_letter);
        char pop_back();
        void erase(size_t idx);
        void erase(size_t first, size_t last);

        String& operator+=(const String& to_add);
        String& operator+=(const char * to_add);

        String& operator=(const String& to_eq);
        String& operator=(const char * to_eq);

        char& operator[](size_t pos);

        //String& operator+(const String& term2) const;
        //String& operator+(const String& term2) const;

    };

    size_t my_strcpy(char *dst, const char *src);
    //int str_compare(const String& str1, const String& str2);

    String operator+(const String& lhs, const String& rhs);
    String operator+(const String& lhs, const char* rhs);
    String operator+(const char* lhs, const String& rhs);
    //String operator+(const char* lhs, const char* rhs);

    bool operator<(const String& lhs, const String& rhs);
    bool operator<(const String& lhs, const char* rhs);
    bool operator<(const char* lhs, const String& rhs);
    //bool operator<(const char* lhs, const char* rhs);

    bool operator>(const String& lhs, const String& rhs);
    bool operator>(const String& lhs, const char* rhs);
    bool operator>(const char* lhs, const String& rhs);
    //bool operator>(const char* lhs, const char* rhs);

    bool operator==(const String& lhs, const String& rhs);
    bool operator==(const String& lhs, const char* rhs);
    bool operator==(const char* lhs, const String& rhs);
    //bool operator==(const char* lhs, const char* rhs);

    bool operator!=(const String& lhs, const String& rhs);
    bool operator!=(const String& lhs, const char* rhs);
    bool operator!=(const char* lhs, const String& rhs);
    //bool operator!=(const char* lhs, const char* rhs);

    bool operator>=(const String& lhs, const String& rhs);
    bool operator>=(const String& lhs, const char* rhs);
    bool operator>=(const char* lhs, const String& rhs);
    //bool operator>=(const char* lhs, const char* rhs);

    bool operator<=(const String& lhs, const String& rhs);
    bool operator<=(const String& lhs, const char* rhs);
    bool operator<=(const char* lhs, const String& rhs);
    //bool operator<=(const char* lhs, const char* rhs);
}

#endif /* MY_STRING */
