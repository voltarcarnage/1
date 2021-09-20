#include "line.h"

int main()
{
  line::Line *matrix = line::input();

  if (!matrix){
  std::cout << "incorrect data" << std::endl;
  return 1;
  }

  line::output(matrix);

  line::Line *tempMatrix = line::swap(matrix);


  if(tempMatrix){
  line::output(tempMatrix);
  line::deallocate(tempMatrix);
  }
  else
    line::output(matrix);

  line::deallocate(matrix);
  return 0;
}
