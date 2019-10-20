/*******************************************************

Author: Roberto Corti
Course: Advanced Programming
Write a function that computes the transpose of a matrix.
The matrix is represented by a simple std::array<double,N> where N is the total size of the matrix.
The original array must be modified inside the function transpose.


********************************************************/

#include <iostream>
#include <array>
#include <utility>
#include <iomanip>


template <class T>
void print_ma(T mat, int row, int col);

template <class T>
void transpose(T& mat, int row, int col, T& mat_t);


int main(){

  const int nrows = 5;
  const int ncols = 4;


  std::array<double,(nrows*ncols)> mat;

  for (int i = 0; i<(nrows*ncols); i++){

    mat[i] = i;

  }


  std::cout<<"Input Matrix: "<<std::endl;

  print_ma(mat, nrows, ncols);

  std::cout<<"\n";

  std::array<double,(nrows*ncols)> mat_t;

  transpose(mat, nrows, ncols, mat_t);

  std::cout<<"Transpose Matrix: "<<std::endl;

  if(nrows==ncols){

    print_ma(mat, nrows, ncols);

  }

  else{

    print_ma(mat_t, ncols, nrows);

  }

  return 0;

}


template <class T>
void print_ma(T mat, int row, int col){

  for(int i=0; i<row; i++){

    for(int j=0; j<col; j++){

      std::cout << std::setw(2) << mat[i * col + j] << " ";

    }

    std::cout<<"\n";

  }


}

template <class T>
void transpose(T& mat, int row, int col, T& mat_t){

  if(row==col){

    for(int i=0; i<row; i++){

      for(int j=i; j<col; j++){

	std::swap(mat[i*col+j], mat[j*col+i]);

      } 
      
    }

  }

  else{

   for (int i=0; i < col; ++i){
     
     for (int j=0; j < row; ++j) {

       mat_t[i * row + j] = mat[j * col + i];
     }

   }

  }



}
