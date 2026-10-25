#include<iostream>
using namespace std;

//Tags: 条件分岐

int main(void){
  int cnt[11]={};
  for(int i=0; i<3; i++){
    int x; cin >> x; 
    cnt[x]++;
  }
  for(int i=1; i<=10; i++)if(cnt[i]&1){
    cout << i << endl; return 0;
  }
  return 0; 
}