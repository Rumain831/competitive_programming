#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 最大公約数, 構築
//https://codeforces.com/contest/2218/problem/D

int main(void){
  int nn=1e6;
  vector<ll> yakusu(nn+1, -1), prime;
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
    int n; cin >> n;
    for(int i=0; i<n; i++) cout << prime[i]*prime[i+1] << ' ';
    cout << '\n';
  }
  return 0; 
}