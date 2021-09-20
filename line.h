#include <iostream>
#include <limits.h>

#pragma once

namespace line{

  struct Line{
    int rows,colomns, size;
    int *row_indexes;
    int *colomn_indexes;
    float *value;
  };

  template <class T>

  T getNum(const char *msg, T &a)
  {
    std::cout << msg;
    std::cin >> a;
    while(!std::cin.good())
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      std::cout << "\nInvalid value\n" << std::endl;
      std::cout << msg;
      std::cin >> a;
    }

    return a;
  }

  Line *allocate(int amount);
  Line *input();
  Line *swap(Line *matrix);
  void output(Line *matrix);
  void deallocate(Line *matrix);

}
