#include<iostream>
using namespace std;
using ll = long long;

//Tags: ゲーム

int main(void){
  ll n; cin >> n;
  if(n==1){
    cout << "Aoki" << endl; return 0;
  }
  ll left=1, right=1;
  while(right<=n) right<<=1;
  left=right/2;
  ll mid=n+1;
  bool b=1;
  while(left!=1){
    if(mid==left) mid=left/2, b^=1;
    else if(mid==right) mid=right/2, b^=1;
    else{
      ll nxt=(mid-1)/2;
      if(b) mid=nxt+1, b^=1;
      else{
        if(mid&1) mid=nxt;
        else mid=nxt+1;
        if(left/2!=mid) b^=1;
      }
    }
    left/=2, right/=2;
  }
  cout << (b?"Aoki":"Takahashi") << endl;
  return 0; 
}