#include<iostream>
#include<vector>
using namespace std;

//Tags: 文字列, 前計算

int main(void){
  int q; cin >> q;
  string s, t; cin >> s >> t;
  int n=s.size(), m=t.size();
  vector<int> sum(n+1);
  for(int i=0; i<n; i++){
    int x=(s.substr(i, m)==t);
    sum[i+1]=sum[i]+x;
  }
  while(q--){
    int l, r; cin >> l >> r; 
    if(l+m-1>r){
      cout << "No" << '\n'; continue;
    }
    int nr=r-m+1, now=sum[nr]-sum[l-1];
    cout << (now?"Yes":"No") << '\n';
  }
  return 0; 
}