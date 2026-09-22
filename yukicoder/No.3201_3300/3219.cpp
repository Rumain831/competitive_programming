#include<iostream>
#include<vector>
using namespace std;

//Tags: bit全探索, bit演算
//Level: 2

int main(void){
  int n; cin >> n;
  vector<int> a(n);
  for(auto&x:a) cin >> x;
  int m=12, mx=(1<<m), all=mx-1;
  int ans=-1;
  string s;
  for(int i=0; i<mx; i++){
    int w=0, b=0, rem=all^i;
    string t;
    for(int j=0; j<n; j++){
      if((i|a[j])==i) w|=a[j], t+='W';
      else if((rem|a[j])==rem) b|=a[j], t+='B';
      else{w=-1; break;}
    }
    if(w!=-1){
      int now=w*b;
      if(now>ans){
        ans=now, s=t;
      }
    }
  }
  cout << ans << '\n' << s << endl;
  return 0; 
}