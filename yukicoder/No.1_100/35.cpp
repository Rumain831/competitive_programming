#include<iostream>
using namespace std;

//Tags: 四則演算

int main(void){
  int n; cin >> n;
  int right=0, miss=0;
  while(n--){
    int t; string s; cin >> t >> s;
    int p=12*t/1000, m=s.size();
    if(p>=m) right+=m;
    else{
      right+=p, miss+=m-p;
    }
  }
  cout << right << ' ' << miss << endl; 
  return 0; 
}