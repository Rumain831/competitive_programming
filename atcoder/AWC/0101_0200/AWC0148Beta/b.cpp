#include<iostream>
#include<vector>
#include<map>
using namespace std;
using ll = long long;

//Tags: 差分更新

int main(void){
  int n; cin >> n;
  vector<int> x(n), y(n);
  ll cx=0, cy=0;
  map<int, int> cntx, cnty;
  auto put=[](map<int, int>& mp, ll& c, int tar){
    mp[tar]++;
    if(mp[tar]==1) c++;
  };
  auto erase=[](map<int, int>& mp, ll& c, int tar){
    mp[tar]--;
    if(mp[tar]==0) c--;
  };
  for(int i=0; i<n; i++){
    cin >> x[i] >> y[i];
    put(cntx, cx, x[i]);
    put(cnty, cy, y[i]);
  }
  for(int i=0; i<n; i++){
    erase(cntx, cx, x[i]);
    erase(cnty, cy, y[i]);
    cout << cx*cy-(n-1) << '\n';
    put(cntx, cx, x[i]);
    put(cnty, cy, y[i]);
  }
  return 0; 
}