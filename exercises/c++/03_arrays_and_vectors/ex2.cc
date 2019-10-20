/*******************************************************

Author: Roberto Corti
Course: Advanced Programming
Modify the ex1.cc program such that the number of rows and columns are read from command line arguments.


********************************************************/

#include <iostream>
#include <array>
#include <utility>
#include <iomanip>
#include <sstream>
#include <cstddef>

#define usl unsigned long int

template <class T>
void print_ma(T mat, std::size_t row, std::size_t col);

template <class T>
void transpose(T& mat, std::size_t row, std::size_t col, T& mat_t);


int main(int argc, char* argv[]){
  
  std::size_t nrows;
  usl getrows;
  
  {
    std::istringstream is{argv[1]};
    is >> getrows;
    nrows = static_cast<std::size_t>(getrows);
  }

  const usl N = 25;
  std::size_t ncols = N/nrows;
  
  
  std::array<double,N> mat;
  
  for (std::size_t i = 0; i<(nrows*ncols); i++){

    mat[i] = i;

  }


  std::cout<<"Input Matrix: "<<std::endl;

  print_ma(mat, nrows, ncols);

  std::cout<<"\n";

  std::array<double,N> mat_t;

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
void print_ma(T mat, std::size_t row, std::size_t col){

  for(std::size_t i=0; i<row; i++){

    for(std::size_t j=0; j<col; j++){

      std::cout << std::setw(2) << mat[i * col + j] << " ";

    }

    std::cout<<"\n";

  }


}

template <class T>
void transpose(T& mat, std::size_t row, std::size_t col, T& mat_t){

  if(row==col){

    for(std::size_t i=0; i<row; i++){

      for(std::size_t j=i; j<col; j++){

	std::swap(mat[i*col+j], mat[j*col+i]);

      } 
      
    }

  }

  else{

    for (std::size_t i=0; i < col; ++i){
     
     for (std::size_t j=0; j < row; ++j) {

       mat_t[i * row + j] = mat[j * col + i];
     }

   }

  }


}
