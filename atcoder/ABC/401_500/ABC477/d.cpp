#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using P = pair<int, int>;

//Tags: 文字列, 逆から見る

int main(void){
  int n, q; cin >> n >> q;
  vector<int> st(n), off;
  vector<P> query={P(2, 0)};
  for(int i=0; i<q; i++){
    int t; cin >> t;
    if(t==1){
      int x; cin >> x; x--;
      st[x]^=1;
      query.emplace_back(t, x);
    }
    else{
      char c; cin >> c;
      query.emplace_back(t, c-'a');
    }
  }
  for(int i=0; i<n; i++)if(st[i]==0) off.push_back(i);
  string ans(n, '?');
  reverse(begin(query), end(query));
  for(auto [t, x]:query){
    if(t==1){
      if(st[x]==2) continue;
      if(st[x]) off.push_back(x);
      st[x]^=1;
    }
    else{
      while(off.size()){
        int p=off.back(); off.pop_back();
        if(st[p]==1) continue;
        ans[p]=(char)('a'+x), st[p]=2;
      }
    }
  }
  cout << ans << endl;
  return 0; 
}