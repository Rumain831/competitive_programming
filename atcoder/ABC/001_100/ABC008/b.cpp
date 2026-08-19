#include<iostream>
#include<map>
using namespace std;
using ll = long long;

int main(void){
  int n; cin >> n;
  map<string, int> ele;
  for(int i=0; i<n; i++){
    string s; cin >> s;
    ele[s]++;
  }
  int maxi=-1;
  string name;
  for(auto p:ele){
    if(maxi<p.second) name=p.first, maxi=p.second;
  }
  cout << name << endl;
  return 0; 
}