#include <iostream>

bool is_prime(int i);
void print_array(int * v, int n);
void copy_array(int * a, int * v, int n);
int * new_array( int * v, int i, int n);
void print_array(int *v, int n);

int main(){

  int n = 0;  
  int * primes = new int[n];

  for(int i=2; i<101; i++){
      
    if (is_prime(i)){

      //std::cout<<i<<std::endl;
      
      primes = new_array(primes, i, n);
      n++;
      
    }
   
  }

   for (int i = 0; i<n; i++){

    std::cout<<"primes["<<i<<"]: "<<primes[i]<<std::endl;

   }
  
  delete [] primes;

  return 0;

}



bool is_prime(int i){

  int count = 0;
  
  for (int k = i-1; k>1; k--){
    
    if (i%k==0){
      
      count++;
      
    }
    

  }

  if (count == 0){

    return true;

  }

  else{

    return false;

  }
  

}


void copy_array(int * a, int * v,  int n){


  for(int j = 0; j<n; j++){

    a[j] = v[j];

  }


}

int * new_array(int * v, int i, int n){

  int * new_array = new int[n+1];

  for (int k = 0; k<n; k++){

    new_array[k] = v[k];

  }

  delete [] v;
  
  new_array[n] = i;

  return new_array;

}

void print_array(int *v, int n){

  for (int i = 0; i<n; i++){

    std::cout<<"primes["<<i<<"]: "<<v[i]<<std::endl;

  }
  



}

