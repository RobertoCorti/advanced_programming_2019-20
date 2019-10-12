#include <iostream>
#include <cmath>

using namespace std;

int main(){

  int n;

  cout<<"Insert number: ";

  cin>>n;
  
  bool primes[n];

  primes[0] = false;
  primes[1] = false;

  //initializing boolean array
  for (int i = 2; i<n; i++){

    primes[i] = true;
    
  }

  //Sieve of Eratosthenes 
  for (int k = 0; k<sqrt(n); k++){
    
    if (primes[k]==true){
      
     for(int j = pow(k,2); j<n; j += k){
	
	primes[j] = false;
	
      }

    }

  }

 

  // Print all prime numbers 
  for (int p=2; p<n; p++) {
    if (primes[p]){ 
          cout << p << "\n";
    }
  }
 
 
  return 0;

}
