#include "mystring.h"

using namespace F;

/**
 * Sting class default costructor.
 */
String::String() : str{0},
                   cap(CAP),
                   size(0)
{
    printf("Hello, I'm constructor!\n");
}

/**
 * Sting class copy costructor.
 */
String::String(const String &a) : str{0},
                                  cap(a.cap),
                                  size(a.size)
{
    printf("Hello, I'm constructor!\n");
    strcpy(str, a.str);
}

/**
 * Sting class costructor.
 */
String::String(const char str[]) : str{0},
                                   cap(CAP),
                                   size(my_strcpy(this->str, str))
{
    printf("Hello, I'm constructor!\n");
}

/*String::String(const String &a, const String &b)
{

}*/

String::~String()
{
    printf("Hello, I'm destructor!\n");
    clear();
}

/**
 * Strcpy, but returning strlen.
 */
size_t F::my_strcpy(char *dst, const char *src)
{
    size_t str_len = 0;

    do
    {
         dst[str_len] = src[str_len];
         str_len++;
    } while(src[str_len] != '\0');

    return str_len;
}

/**
 * Printing string.
 */
void String::print()
{
    printf("%s", str);
}

/**
 * Returning string size.
 */
size_t String::length()
{
    return size;
}


/**
 * Returning string capacity.
 */
size_t String::capacity()
{
    return cap;
}

/**
 * Returning true if string is epmty.
 */
bool String::empty()
{
    return (size == 0);
}

/**
 * Cleaning string.
 */
void String::clear()
{
    for(size_t i = 0; i < size; i++)
        str[i] = '\0';
    size = 0;
}

/**
 * Pushing back new element.
 */
void String::push_back(char new_letter)
{
    assert(size <= cap);
    str[size++] = new_letter;
}

/**
 * Popping last elem.
 */
char String::pop_back()
{
    if(size == 0)
        return '\0';

    char res = str[--size];
    str[size] = '\0';
    return res;
}

void String::erase(size_t idx)
{
    assert(idx < size);

    for(size_t i = idx; str[i] != '\0'; i++)
        str[i] = str[i+1];

    size--;
}

void String::erase(size_t first, size_t last)
{
    assert(first < last);
    assert(last < size);

    for(size_t i = 0; (str[first + i]  != '\0') && (last + i < cap); i++)
        str[first + i] = str[last + i];

    size -= (last - first);
}

/**
 * Add new str to our.
 */
String& String::operator+=(const String& to_add)
{
    /*strncpy(str + size, to_add.str, cap - size - to_add.size);
    size += to_add.size;
    if(size > cap)
        size = cap;*/
    for(size_t i = 0; (size < cap) && (i < to_add.size); i++)
        push_back(to_add.str[i]);

    return *this;
}

/**
 * Add c string to our.
 */
String& String::operator+=(const char * to_add)
{
    /*for(size_t i = 0; size < cap; size++, i++)
        str[size] = to_add[i];*/
    for(size_t i = 0; (size < cap) && (to_add[i] != '\0'); i++)
        push_back(to_add[i]);

    return *this;
}

/**
 * a = b.
 */
String& String::operator=(const String& to_eq)
{
    if(this == &to_eq)
        return *this;
    clear();
    /*strcpy(str, to_eq.str);
    cap = to_eq.cap;
    size = to_eq.size;*/
    for(int i = 0; size < cap; i++)
        push_back(to_eq.str[i]);

    return *this;
}

/**
 * a = const char*.
 */
String& String::operator=(const char* to_eq)
{
    clear();
    for(int i = 0; size < cap; i++)
        push_back(to_eq[i]);
    return *this;
}

char& String::operator[](size_t pos)
{
    assert(pos < size);
    return str[pos];
}

/**
 * a + b.
 */
String F::operator+(const String& lhs, const String& rhs)
{
    String tmp(lhs);
    tmp += rhs;
    return tmp;
}


String F::operator+(const String& lhs, const char* rhs)
{
    String tmp(lhs);
    tmp += rhs;
    return tmp;
}


String F::operator+(const char* lhs, const String& rhs)
{
    String tmp(lhs);
    tmp += rhs;
    return tmp;
}



/**
 * strings compare
 * @param str1
 * @param str2
 * @return
 */
/*int F::str_compare(const String& str1, const String& str2)
{
    size_t p = 0, q = 0;
    while((str1.str[p] != '\0') && (str2.str[q] != '\0') && (str1.str[p] == str2.str[q]))
    {
        p++;
        q++;
    }

    return (tolower(str1.str[p]) - tolower(str2.str[q]));
}bool F::operator<(const String& lhs, const String& rhs)
{
    return str_compare(lhs, rhs) < 0;
}*/



/**
 *
 * @param lhs
 * @param rhs
 * @return
 */
bool F::operator<(const String& lhs, const String& rhs)
{
    return strcmp(lhs.str, rhs.str) < 0;
}

bool F::operator<(const String& lhs, const char* rhs)
{
    return strcmp(lhs.str, rhs) < 0;
}

bool F::operator<(const char* lhs, const String& rhs)
{
    return strcmp(lhs, rhs.str) < 0;
}

/**
 *
 * @param lhs
 * @param rhs
 * @return
 */
bool F::operator>(const String& lhs, const String& rhs)
{
    return strcmp(lhs.str, rhs.str) > 0;
}

bool F::operator>(const String& lhs, const char* rhs)
{
    return strcmp(lhs.str, rhs) > 0;
}

bool F::operator>(const char* lhs, const String& rhs)
{
    return strcmp(lhs, rhs.str) > 0;
}

/**
 *
 * @param lhs
 * @param rhs
 * @return
 */
bool F::operator==(const String& lhs, const String& rhs)
{
    return strcmp(lhs.str, rhs.str) == 0;
}

bool F::operator==(const String& lhs, const char* rhs)
{
    return strcmp(lhs.str, rhs) == 0;
}

bool F::operator==(const char* lhs, const String& rhs)
{
    return strcmp(lhs, rhs.str) == 0;
}

/**
 *
 * @param lhs
 * @param rhs
 * @return
 */
bool F::operator>=(const String& lhs, const String& rhs)
{
    return strcmp(lhs.str, rhs.str) >= 0;
}

bool F::operator>=(const String& lhs, const char* rhs)
{
    return strcmp(lhs.str, rhs) >= 0;
}

bool F::operator>=(const char* lhs, const String& rhs)
{
    return strcmp(lhs, rhs.str) >= 0;
}

/**
 *
 * @param lhs
 * @param rhs
 * @return
 */
bool F::operator<=(const String& lhs, const String& rhs)
{
    return strcmp(lhs.str, rhs.str) <= 0;
}

bool F::operator<=(const String& lhs, const char* rhs)
{
    return strcmp(lhs.str, rhs) <= 0;
}

bool F::operator<=(const char* lhs, const String& rhs)
{
    return strcmp(lhs, rhs.str) <= 0;
}

/**
 *
 * @param lhs
 * @param rhs
 * @return
 */
bool F::operator!=(const String& lhs, const String& rhs)
{
    return strcmp(lhs.str, rhs.str) != 0;
}

bool F::operator!=(const String& lhs, const char* rhs)
{
    return strcmp(lhs.str, rhs) != 0;
}

bool F::operator!=(const char* lhs, const String& rhs)
{
    return strcmp(lhs, rhs.str) != 0;
}
