#include "line.h"

namespace line{

  Line *allocate(int amount)
  {
    try
    {
      Line *matrix = new Line;
      matrix->row_indexes = new int[amount];
      matrix->colomn_indexes = new int[amount];
      matrix->value = new float[amount];
      return matrix;
    }
    catch(std::bad_alloc &ba)
    {
      std::cout << " Error " << ba.what() << std::endl;
      return nullptr;
    }
  }


  Line *input()
  {
    const char *pr = "";
    int m,n;

    do{
      std::cout << pr << std::endl;
      //std::cout << "Enter number of lines: --> ";
      pr = "You are wrong; repeat please!";
      getNum("Enter number of lines: --> ",m);
    }while(m < 1);


    pr = "";

    do{
      std::cout << pr << std::endl;
      //std::cout << "Enter number of items in lines: --> ";
      pr = "You are wrong; repeat please!";
      getNum("Enter number of items in lines: --> ",n);
    }while (n < 1);

    float arr[n * m];
    int index = 0;

    std::cout << "Enter items for matrix: " << std::endl;

    for(int i = 0; i < m * n; i++)
    {
      getNum("",arr[i]);
      if(arr[i] != 0)
        index++;
    }
    if(index){
        Line *matrix = allocate(index);

      matrix->size = index;

      int amount = 0;

      for(int i = 0; i < m * n; i++)
      {
        if(arr[i] != 0)
        {
          matrix->value[amount] = arr[i];
          matrix->row_indexes[amount] = i / n;
          matrix->colomn_indexes[amount] = i % n;
          amount++;
        }
      }

      matrix->rows = m;
      matrix->colomns = n;
    return matrix;
    }
    else
      return nullptr;
  }

  Line *swap(Line *matrix)
  {
    Line *tempMatrix = allocate(matrix->size);
    tempMatrix->size = matrix->size;
    tempMatrix->colomns = matrix->colomns;
    tempMatrix->rows = matrix->rows;

    int rowsArray[matrix->rows];
    bool flag = false;

    for(int i = 0; i < matrix->rows; i++)
      rowsArray[i] = i;

    int valueArray[matrix->rows];

    for(int i = 0; i < matrix->rows; i++)
      valueArray[i] = 0;

    int k = 0;

    if(matrix)
    {
      if(matrix->row_indexes[0] == 0 && matrix->colomn_indexes[0] == 0)
        flag = true;

      if(flag && matrix->value[0] > 0){
        for(int i = 0; i < matrix->size && k < matrix->rows; i++)
        {
          if(matrix->colomn_indexes && matrix->row_indexes && matrix->colomn_indexes[i] == 0 && matrix->row_indexes[i] != k)
              k++;

          if(matrix->colomn_indexes && matrix->row_indexes && matrix->colomn_indexes[i] == 0 && matrix->row_indexes[i] == k)
          {
            valueArray[k] = matrix->value[i];
            k++;
            continue;
          }
          else if(matrix->colomn_indexes && matrix->row_indexes && matrix->colomn_indexes[i] != 0 && matrix->row_indexes[i] == k)
          {
            valueArray[k] = 0;
            k++;
            continue;
          }
        }

        for(int i = 0; i < matrix->rows - 1; i++)
        {
          for(int j = 0 ; j < matrix->rows - 1; j++)
          {
            if(valueArray[j] < valueArray[j+ 1])
            {
              std::swap(valueArray[j], valueArray[j+1]);
              std::swap(rowsArray[j], rowsArray[j+1]);
            }
          }
        }

        k = 0;

        for(int i = 0; i < matrix->rows; i++)
        {
          for(int j = 0; j < matrix->size; j++)
          {
            if(matrix->row_indexes && matrix->row_indexes[j] == rowsArray[i])
            {
              tempMatrix->row_indexes[k] = i;
              tempMatrix->colomn_indexes[k] = matrix->colomn_indexes[j];
              tempMatrix->value[k] = matrix->value[j];
              k++;
            }
          }
        }
    }
    else
    {
      for(int i = 0; i < matrix->size; i++)
        matrix->value[i] *= (-1);

      for(int i = 0; i < matrix->size && k < matrix->rows; i++)
        {
          if(matrix->colomn_indexes && matrix->row_indexes && matrix->colomn_indexes[i] == 0 && matrix->row_indexes[i] != k)
              k++;

          if(matrix->colomn_indexes && matrix->row_indexes && matrix->colomn_indexes[i] == 0 && matrix->row_indexes[i] == k)
          {
            valueArray[k] = matrix->value[i];
            k++;
            continue;
          }
          else if(matrix->colomn_indexes && matrix->row_indexes && matrix->colomn_indexes[i] != 0 && matrix->row_indexes[i] == k)
          {
            valueArray[k] = 0;
            k++;
            continue;
          }
        }

        for(int i = 0; i < matrix->rows - 1; i++)
        {
          for(int j = 0 ; j < matrix->rows - 1; j++)
          {
            if(valueArray[j] < valueArray[j+ 1])
            {
              std::swap(valueArray[j], valueArray[j+1]);
              std::swap(rowsArray[j], rowsArray[j+1]);
            }
          }
        }

        k = 0;

        for(int i = 0; i < matrix->rows; i++)
        {
          for(int j = 0; j < matrix->size; j++)
          {
            if(matrix->row_indexes && matrix->row_indexes[j] == rowsArray[i])
            {
              tempMatrix->row_indexes[k] = i;
              tempMatrix->colomn_indexes[k] = matrix->colomn_indexes[j];
              tempMatrix->value[k] = matrix->value[j];
              k++;
            }
          }
        }
      for(int i = 0; i < matrix->size; i++)
        tempMatrix->value[i] *= (-1);
    }
    std::cout << std::endl;
    return tempMatrix;
    }
    else
    {
      std::cout << "Error! Matrix is not allocate!";
      return nullptr;
    }
  }

  void output(Line *matrix)
  {
    int count = 0;
    for(int i = 0; i < matrix->rows * matrix->colomns; i++)
    {
      if(i % matrix->colomns == 0)
        std::cout << "\n";
      if(count < matrix->size && (matrix->colomn_indexes[count] + matrix->row_indexes[count] * matrix->colomns) == i)
      {
        std::cout << " " << matrix->value[count] << " ";
        count += 1;
      }
      else
        std::cout << " " << 0 << " ";
    }
  }

  void deallocate(Line *matrix)
  {
    delete []matrix->row_indexes;
    delete []matrix->colomn_indexes;
    delete []matrix->value;
    delete matrix;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Successful deletion" << std::endl;
  }
}
