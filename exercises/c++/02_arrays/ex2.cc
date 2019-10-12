#include <iostream>

//prototypes
bool is_prime(int i);
int * new_array( int * v, int i, int n);


int main(){

  int n = 0;  
  int * primes = new int[n];

  for(int i=2; i<101; i++){
      
    if (is_prime(i)){          //in case of i == prime number
      
      primes = new_array(primes, i, n); //create a new array with dim n+1, add old the old elements and put i in the nth position
      n++;
      
    }
   
  }

   for (int i = 0; i<n; i++){

    std::cout<<"primes["<<i<<"]: "<<primes[i]<<std::endl;

   }
  
   delete [] primes; //deallocate memory pointed by primes.

  return 0;

}



bool is_prime(int i){

  int count = 0;
  
  for (int k = i-1; k>1; k--){
    
    if (i%k==0){
      
      count++; //every time that I find a divisor k, I add one to the counter
      
    }
    
  }

  if (count == 0){

    return true; //if a number is prime the result of the foor outputs a count ==0

  }

  else{

    return false; // the number is not prime!

  }
  

}



int * new_array(int * v, int i, int n){

  int * new_array = new int[n+1];  //new array of dim n+1

  for (int k = 0; k<n; k++){

    new_array[k] = v[k];  // assign all the n previous position the values of v

  }

  delete [] v;   //deallocate memory pointed by v
  
  new_array[n] = i;  //i is the nth element of new_array

  return new_array;  //I return a pointer that points towards a memory where are listed the same n elements of v and in the n position i.

}


