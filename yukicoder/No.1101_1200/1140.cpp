#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 整数, 素数
//Level: 2

int main(void){
  int nn=5e6+1;
  vector<int> yakusu(nn+1, -1), prime;
  for(int i=2; i<=nn; i++){
    if(yakusu[i]!=-1) continue;
    int copy=i;
    prime.push_back(i);
    while(copy<=nn){
      if(yakusu[copy]==-1) yakusu[copy]=i;
      copy+=i;
    }
  }
  int t; cin >> t;
  while(t--){
    ll a, p; cin >> a >> p;
    if(yakusu[p]!=p) cout << -1 << '\n';
    else cout << (a%p?1:0) << '\n';
  }
  return 0; 
}