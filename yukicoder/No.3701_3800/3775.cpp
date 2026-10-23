#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using P = pair<int, int>;

//Tags: バブルソート
//Level: 2

int main(void){
  int n, k; cin >> n >> k;
  vector<int> p(n), q(n);
  for(auto&x:p) cin >> x;
  vector<P> ans;
  for(int i=0; i<k; i++){
    vector<int> id, val;
    for(int j=i; j<n; j+=k) id.push_back(j);
    int m=id.size();
    bool esc=true;
    while(esc){
      esc=false;
      for(int j=0; j<m-1; j++){
        if(p[id[j]]>p[id[j+1]]){
          ans.emplace_back(id[j]+1, id[j+1]+1);
          swap(p[id[j]], p[id[j+1]]);
          esc=true; break;
        }
      }
    }
  }
  q=p;
  sort(begin(q), end(q));
  if(p!=q) cout << -1 << endl;
  else{
    cout << ans.size() << endl;
    for(auto [x, y]:ans) cout << x << ' ' << y << '\n';
  }
  return 0; 
}