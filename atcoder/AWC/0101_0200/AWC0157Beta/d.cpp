#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: 最適化, 貪欲法

int main(void){
  int n, m; cin >> n >> m;
  vector<ll> a(n), l(m);
  for(auto&x:a) cin >> x;
  for(auto&x:l) cin >> x;
  sort(begin(a), end(a));
  sort(begin(l), end(l));
  vector<ll> edge;
  for(int i=1; i<n; i++) edge.emplace_back(a[0]+a[i]);
  int ei=0, li=0;
  while(ei<n-1&&li<m){
    ll tar=edge[ei];
    while(li<m&&l[li]<tar) li++;
    if(li==m){
      cout << "No" << endl; return 0;
    }
    ei++, li++;
  }
  cout << (ei==n-1?"Yes":"No") << endl;
  return 0; 
}