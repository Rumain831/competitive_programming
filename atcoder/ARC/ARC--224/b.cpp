#include<iostream>
using namespace std;
using ll = long long;

//実験してOEISに聞いたら出てきた(A123663)
//2n-ceiling(2\sqrt(n))
//「4辺ともタイルと共有している」タイルを増やそうと思うと、正方形に近づけたくなる
//　かもしれない。。。
void solve(){
  ll n; cin >> n;
  ll left=0, right=2e9+1;
  while(right-left>1){
    ll mid=(left+right)/2;
    if(4*n<=mid*mid) right=mid;
    else left=mid;
  }
  cout << n*2-right << '\n';
}

int main(void){
  int t; cin >> t;
  while(t--){
    solve();
  }
  return 0; 
}
