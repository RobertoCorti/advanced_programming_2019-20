#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void repetition_check(vector<string>& v);

int main(){

  vector<string> words;

  cout<<"Enter words (press CTRL+D to stop): "<<endl;

  string a; 

  getline(std::cin, a);
		
  words.push_back(a);

  while(std::getline(cin, a)){
		
    words.push_back(a);		

  }

  cout<<endl;
 
  cout<<"Input Words: ";

  for (auto x: words){

    cout<<x<<" ";
		
  }

  cout<<endl;


 repetition_check(words);

 cout<<endl;
 
 cout<<"Output Words (withouth repetitions): ";
  
 for (auto x: words){

    cout<<x<<" ";
		
  }

 cout<<endl;
 cout<<endl;
  
  return 0;
}


void repetition_check(vector<string>& v){
  
  for(int i=0; i<v.size(); i++){

    for(int j=v.size(); j>i; j--)

    if(v[i] == v[j]){

      v.erase(v.begin()+(j));
    
    }


  }

}



