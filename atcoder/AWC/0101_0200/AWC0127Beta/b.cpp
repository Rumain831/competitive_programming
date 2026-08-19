#include<iostream>
using namespace std;

//Tags: 文字列, 条件を満たすものの個数

int main(void){
  int n, q; cin >> n >> q;
  string s, t; cin >> s;
  t='*'+s+'*';
  int m=t.size();
  int ans=0;
  for(int i=0; i<m-1; i++) ans+=(t[i]==t[i+1]); 
  auto f=[&](int i, int add){
    for(int d=-1; d<=1; d++){
      if(d==0) continue;
      int ni=i+d;
      if(ni<0||ni>=m) continue;
      if(t[i]==t[ni]) ans+=add;
    }
  };
  while(q--){
    int i; char c; cin >> i >> c;
    f(i, -1);
    t[i]=c;
    f(i, 1);
    cout << ans << '\n';
  }
  return 0; 
}