#include<iostream>
#include<vector>
using namespace std;

//Tags: 条件分岐, 実装
//Level: 1

bool judge(vector<int>& a){
  if(a[0]<a[1]&&a[1]>a[2]) return true;
  if(a[0]>a[1]&&a[1]<a[2]) return true;
  return false;
}

int main(void){
  vector<int> c(3);
  for(int i=0; i<3; i++){
    char x; cin >> x;
    if(x=='?') c[i]=-1;
    else c[i]=x-'0';
  }
  int ans=0;
  for(int i=0; i<3; i++)if(c[i]==-1){
    c[i]=1;
    if(judge(c)) ans=(ans*10+1);
    c[i]=4;
    if(judge(c)) ans=(ans*10+4);
  }
  cout << ans << endl;
  return 0; 
}