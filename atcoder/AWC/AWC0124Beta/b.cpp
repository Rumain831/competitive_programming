#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using P = pair<int, int>;

//Tags: ソート

int main(void){
  int n, k; cin >> n >> k;
  vector<P> p;
  for(int i=0; i<n; i++){
    int a, b; cin >> a >> b;
    p.emplace_back(-a-b, i+1);
  }
  sort(begin(p), end(p));
  vector<int> ans;
  for(int i=0; i<k; i++) ans.push_back(p[i].second);
  sort(begin(ans), end(ans));
  for(auto x:ans) cout << x << '\n';
  return 0; 
}