#include<iostream>
#include<vector>
using namespace std;

//Tags: 連結リスト

int main(void){
  int n; cin >> n;
  vector<int> pre(n+1), aft(n+1);
  int now=0;
  for(int i=0; i<n; i++){
    cin >> pre[i+1] >> aft[i+1];
    if(pre[i+1]==0) now=i+1;
  }
  while(now!=0){
    cout << now << '\n';
    now=aft[now];
  }
  return 0; 
}