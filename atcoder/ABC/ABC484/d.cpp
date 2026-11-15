#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: ランレングス圧縮, 数え上げ

int main(void){
  int n; cin >> n;
  vector<int> a(n);
  int cnt[200001]={};
  for(auto&x:a) cin >> x;
  int pre=-1;
  ll ans=1, c=0;
  for(int i=0; i<n; i++){
    if(pre==a[i]){
      cnt[a[i]]++;
      continue;
    }
    if(pre!=a[i]){
      ll add=i-cnt[a[i]];
      ans+=add; c++;
      pre=a[i];
      cnt[a[i]]++;
    }
  }
  cout << ans << endl;
  return 0; 
}