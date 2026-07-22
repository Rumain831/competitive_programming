#include<iostream>
#include<set>
using namespace std;

//Tags: 全探索, 整数

int main(void){
  int n; cin >> n;
  set<int> ok;
  for(int a=1; a<=250; a++)for(int b=1; b<=250; b++) ok.insert(4*a*b+3*(a+b));
  int ans=0;
  for(int i=0; i<n; i++){
    int s; cin >> s;
    if(ok.count(s)==0) ans++;
  } 
  cout << ans << endl;
  return 0;
}