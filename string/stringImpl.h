#ifndef __STRINGIMPL__
#define __STRINGIMPL__

#include <iostream>
#include <cstring>
#include <fstream>


class myString
{
public:
  myString();
  myString(size_t,char);
  myString(const char*);
  myString(const myString&);
  myString& operator= (const myString&);
  myString& operator= (myString&&);
  myString(myString&&);
  ~myString();
public:
  size_t size() const;
  int find(char) const;
  char& at(int) const;
public:
  void pushBack(char);
  char popBack();
  void insert(int,const char*);
public:
  const char& operator[] (int) const;
  char& operator[] (int) noexcept;
  myString operator+ (const myString&) const;
  myString operator+ (char) const ;
  friend std::ostream& operator<<(std::ostream& write,const myString& str) noexcept
  {
      return write << str.s_buff ;
  }
private:
  size_t s_size{};
  char* s_buff{};
};

#endif //__STRINGIMPL__