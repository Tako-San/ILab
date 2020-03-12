#include "mystring.h"

using namespace F;

/**
 * Sting class default costructor.
 */
String::String() : str{0},
                   cap(CAP + 1),
                   size(0)
{
}

/**
 * Sting class copy costructor.
 */
String::String(String &a) : str{0},
                            cap(a.cap),
                            size(a.size)
{
    strncpy(str, a.str, a.size);
}

/**
 * Sting class costructor.
 */
String::String(const char str[]) : str{0},
                                   cap(CAP),
                                   size(my_strcpy(this->str, str))
{
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
    printf("%s", this->str);
}

/**
 * Returning string size.
 */
size_t String::length()
{
    return this->size;
}


/**
 * Returning string capacity.
 */
size_t String::capacity()
{
    return this->cap;
}

/**
 * Returning true if stack is epmty.
 */
bool String::empty()
{
    return (this->size == 0);
}
