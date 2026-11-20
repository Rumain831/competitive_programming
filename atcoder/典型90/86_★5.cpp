#include<iostream>
#include<vector>
#include<tuple>
using namespace std;
using ll = long long;
using qu = tuple<int, int, int, ll>;

//Tags: bit全探索, OR, 数え上げ
//解説URL: https://twitter.com/e869120/status/1412904274900754441

int main(void){
  int n, q; cin >> n >> q;
  vector<qu> cond;
  for(int i=0; i<q; i++){
    int x, y, z; ll w; cin >> x >> y >> z >> w; x--, y--, z--;
    cond.emplace_back(x, y, z, w);
  }
  vector<ll> ans(60);
  for(int i=0; i<60; i++){
    for(int j=0; j<(1<<n); j++){
      bool ok=true;
      for(int k=0; k<q; k++){
        auto [x, y, z, w]=cond[k];
        int xx=(j>>x&1), yy=(j>>y&1), zz=(j>>z&1), ww=(w>>i&1);
        if((xx|yy|zz)!=ww){
          ok=false; break;
        }
      }
      if(ok) ans[i]++;
    }
  }
  ll answer=1, mod=1e9+7;
  for(int i=0; i<60; i++) answer*=ans[i], answer%=mod;
  cout << answer << endl;
  return 0;
}