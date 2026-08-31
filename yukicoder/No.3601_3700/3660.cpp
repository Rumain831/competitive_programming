#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, int>;

//Tags: 木, 単調増加
//Level: 2.5

int main(void){
  int n; cin >> n;
  vector<ll> s(n);
  vector<P> val;
  for(int i=0; i<n; i++){
    cin >> s[i];
    val.emplace_back(s[i], i);
  }
  sort(begin(val), end(val));
  vector<vector<int>> to(n);
  for(int i=0; i<n-1; i++){
    int a, b; cin >> a >> b; a--, b--;
    if(s[a]>s[b]) swap(a, b);
    if(s[a]<s[b]) to[a].push_back(b);
  }
  vector<ll> sum(n);
  for(int i=0; i<n; i++){
    auto [x, id]=val[i];
    sum[id]+=x;
    for(auto v:to[id]) sum[v]=max(sum[v], sum[id]);
  }
  cout << *max_element(begin(sum), end(sum)) << endl;
  return 0; 
}