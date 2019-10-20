#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

double mean(vector<double> v);

double median(vector<double> v);

int main(){

  vector<double> temp;
  
  ifstream inFile;

  inFile.open("temperatures.txt");

  double t;

  cout<<"Loading data...."<<endl;
  
  do{

    inFile>>t;
    temp.push_back(t);


  }while(!(inFile.eof()));

  inFile.close();

  cout<<"temperatures.txt"<<endl;
    
  for(auto x: temp){

    cout<<x<<" ";

  }

  cout<<"\n";
  cout<<"\n";

  cout<<"Mean Value: "<<mean(temp)<<"\n";
  
  cout<<"Median: "<<median(temp)<<"\n";

}


double mean(vector<double> v){

  unsigned int N = v.size();

  double sum = 0;

  for(auto x: v){

    sum += x;

  }

  return sum/N;


}

double median(vector<double> v){

  unsigned int n = v.size();

  sort(v.begin(), v.end());

  if(n%2 == 0){

    double sum = (v[n/2 - 1] + v[n/2]);

    return sum/2;
  }

  else {

    return v[(n+1)/2 - 1];

  }


}
