#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
using ll = long long;
using tu = tuple<int, int, char>;

int main(void){
  int h, w, q; cin >> h >> w >> q;
  vector<string> ans(h, string(w, '?'));
  vector<tu> query;
  for(int i=0; i<q; i++){
    int r, c; char x; cin >> r >> c >> x; r--, c--;
    query.emplace_back(r, c, x);
  }
  reverse(query.begin(), query.end());
  for(int t=0; t<q; t++){
    auto [r, c, x]=query[t];
    int last=0;
    for(int i=r; i>=0; i--){
      for(int j=c; j>=last; j--){
        if(ans[i][j]!='?'){
          last=max(last, j+1);
          break;
        }
        ans[i][j]=x;
      }
      if(last>c) break;
    }
  }
  for(int i=0; i<h; i++)for(int j=0; j<w; j++)if(ans[i][j]=='?') ans[i][j]='A';
  for(int i=0; i<h; i++) cout << ans[i] << endl;
  return 0; 
}