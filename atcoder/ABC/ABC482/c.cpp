#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: 二分探索

int main(void){
  int h, w, n, q; cin >> h >> w >> n >> q;
  vector<int> tate, yoko;
  for(int i=0; i<n; i++){
    int r, c; cin >> r >> c;
    tate.push_back(r);
    yoko.push_back(c);
  }
  sort(begin(tate), end(tate));
  sort(begin(yoko), end(yoko));
  while(q--){
    int t; cin >> t;
    int x, y, ans; cin >> x >> y;
    if(t==1){
      ans=upper_bound(begin(tate), end(tate), y)-lower_bound(begin(tate), end(tate), x);
    }
    else{
      ans=upper_bound(begin(yoko), end(yoko), y)-lower_bound(begin(yoko), end(yoko), x);
    }
    cout << ans << '\n';
  }
  return 0; 
}