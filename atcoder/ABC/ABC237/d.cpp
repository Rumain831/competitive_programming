#include<iostream>
#include<map>
using namespace std;

//Tags: 連結リスト

int main(void){
  int n; cin >> n;
  map<int, int> aft, pre;
  aft[0]=n+1, pre[0]=-1;
  aft[-1]=0, pre[n+1]=0;
  string s; cin >> s;
  for(int i=0; i<n; i++){
    if(s[i]=='L'){
      //pre[i] i
      int p=pre[i];
      aft[p]=i+1, aft[i+1]=i;
      pre[i]=i+1, pre[i+1]=p;
    }
    else{
      //i aft[i]
      int a=aft[i];
      aft[i]=i+1, aft[i+1]=a;
      pre[a]=i+1, pre[i+1]=i;
    }
  }
  int now=-1;
  while(now!=n+1){
    if(now>=0) cout << now << ' ';
    now=aft[now];
  }
  return 0;
}