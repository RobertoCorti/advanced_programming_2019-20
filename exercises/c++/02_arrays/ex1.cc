/* Write a program that reads from stdin the length of an array and then store in it the numbers given from stdin. The program should then prints the numbers in reverse order. Remember to properly free the used memory. You should divide the problem in two parts:

Write one template function that allocates on the heap one array of a given size, initialize its elements and returns the pointer to the first element.

Write a template function that prints the elements of an array in the reverse order.

Test with integers and doubles.

Use std::size_t.

 */

#include <iostream>

template <typename T>
T * allocate_vector(T n);
template <typename T>
void print_reverse(T * v, unsigned int n);

int main(){

  unsigned int n;

  std::cout<<"Insert the dimension of the vector."<<std::endl;
  std::cin>>n;

  int * v = allocate_vector<int>(n);

  print_reverse(v, n);

  delete [] v;
  
  return 0;

}

template <typename T>
T * allocate_vector(T n){

  T * v = new T [n];

  for(int i=0; i<n; i++){
    
    std::cout<<"v["<<i<<"]: ";
    std::cin>>v[i];
    
  }

  std::cout<<"\n";
  std::cout<<"\n";

  return v;

}

template <typename T>
void print_reverse(T * v, unsigned int n) {

  for(int i = n-1; i>-1; i--){

    std::cout<<"v["<<i<<"]: "<<v[i]<<std::endl;

  }


}

