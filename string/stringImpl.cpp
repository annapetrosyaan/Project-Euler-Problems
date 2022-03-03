#include "stringImpl.h"


myString::myString()
{
    s_size = 1;
    s_buff = new char[s_size];
}

myString::myString(size_t count, char sym)
{
    s_size = count;
    s_buff = new char[s_size];
    for(int i = 0;i<count; ++i)
    {
        s_buff[i] = sym;
    }
}

myString::myString(const myString& other)
{
    s_size = other.s_size;
    s_buff = new char [s_size];
    for(int i=0; i< s_size; ++i)
    {
        s_buff[i] = other[i];
    }
}

myString::myString(const char* str)
{
    s_size = std::strlen(str);
    s_buff = new char [s_size];
    for(int i = 0; i<s_size; ++i)
    {
        s_buff[i] = str[i];
    }
}

myString& myString::operator= (const myString& str)
{
    if(this == &str){ return *this;}
    delete[] this->s_buff;
    s_size = str.s_size;
    s_buff = new char[s_size];
    for(int i=0; i<s_size; ++i)
    {
        s_buff[i]=str[i];
    }
    return *this;
}

myString& myString::operator= (myString&& str)
{
   s_size = str.s_size ;
   s_buff = str.s_buff ;
   str.s_buff = nullptr;
   return *this;
}

myString::myString(myString&& other)
{
   s_size = other.s_size;
   s_buff = other.s_buff;
   other.s_buff = nullptr;
}

myString::~myString()
{
    delete [] s_buff;
}

size_t myString::size() const
{
    return s_size;
}

int myString::find(char ch) const
{
    for(int i = 0 ; i < s_size ; ++i) 
    {
        if(ch == s_buff[i]) 
        {
            return ch ;
            break;
        }
    }
    return -1 ;
}

char& myString::at(int index) const
{
    if(index >= s_size) 
    {
        std::cerr << "out of range" << std::endl ;
        exit(-1) ;
    }
    return s_buff[index] ;
}

void myString::pushBack(const char sym) 
{
    char* tmp = new char(sym);
    s_buff[s_size] = tmp[0];
    ++s_size;
    this->s_buff[s_size] = '\0';
}

char myString::popBack() 
{
    char ch = s_buff[s_size];
    char* temp = new char[s_size-1];
    for(int i=0; i<s_size-1; ++i)
    {
        temp[i] = s_buff[i];
    }
    delete [] s_buff;
    s_buff = temp;
    -- s_size;
    return ch;
}

void myString::insert(int index,const char* syms) 
{
    const int sbSize = std::strlen(syms) ;
    char* tmp = s_buff ;
    s_buff = new char[s_size += sbSize] ;
    int j{};
    for(int i = 0; i < index; ++i)
    {
        s_buff[i] = tmp[i] ;
    }
    for(int i = 0, j = index ; i < sbSize ;++i ,++j)
    {
        s_buff[j] = syms[i];
    }
    for(int i = index + sbSize,j = index ; i<s_size; ++i , ++j)
    {
        s_buff[i] = tmp[j] ;
    }
    delete [] tmp ;
    tmp = nullptr;
}

const char& myString::operator[] (int index) const 
{ return s_buff[index]; }

char& myString::operator[] (int index) noexcept
{ return s_buff[index] ; }

myString myString::operator+(const myString& str) const
{
    myString tmp ;
    char* temp = new char[s_size + str.s_size - 1];
    int j{0};
    for(; j < s_size ; ++j) 
    {
      temp[j] = this->s_buff[j];
    }
    for(int i = 0; i < str.s_size ; ++i , ++j) 
    {
      temp[j] = str.s_buff[i] ;
    }

    tmp.s_size = this->s_size + str.s_size  ;
    tmp.s_buff = temp;
    temp = nullptr ;
    return tmp ;
}

myString myString::operator+ (char sym) const
{
    myString temp = *this;
    temp.pushBack(sym);
    return temp;
}