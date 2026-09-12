#include<iostream>
using namespace std;

//Tags: 素数
//Level: 1.5

int main(void){
  int m, d; cin >> m >> d;
  int now=m*100+d;
  for(int i=2; i<now; i++)if(now%i==0){
    cout << "No" << endl; return 0;
  }
  cout << "Yes" << endl;
  return 0; 
}