#include<iostream>
using namespace std;

//Tags: Simulation

int main(void){
  string s; cin >> s;
  while(!s.empty()){
    int n=s.size();
    bool ng=true;
    if(n>=2){
      if(s.substr(n-2, 2)=="ch") ng=false, s.pop_back(), s.pop_back();
    }
    if(n>=1){
      char p=s.back();
      if(p=='o'||p=='k'||p=='u') ng=false, s.pop_back();
    }
    if(s.size()&&ng){
      cout << "NO" << endl; return 0; 
    }
  }
  cout << "YES" << endl;
  return 0;
}