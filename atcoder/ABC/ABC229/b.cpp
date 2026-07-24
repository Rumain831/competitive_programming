#include<iostream>
#include<algorithm>
using namespace std;

//Tags: 整数, 繰り上がり

int main(void){
  string a, b; cin >> a >> b;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  int l=min(a.size(), b.size());
  for(int i=0; i<l; i++){
    int na=a[i]-'0', nb=b[i]-'0';
    if(na+nb>=10){
      cout << "Hard" << endl; return 0;
    } 
  }
  cout << "Easy" << endl;
  return 0;
}