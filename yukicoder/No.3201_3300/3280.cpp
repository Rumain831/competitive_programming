#include<iostream>
#include<map>
using namespace std;

//Tags: 期待値
//Level: 1.5

int main(void){
  int n, x, q; cin >> n >> x >> q;
  double ans=0;
  while(q--){
    int m; cin >> m;
    map<int, int> cnt;
    while(m--){
      int f; cin >> f;
      cnt[f]++;
    }
    if(cnt[x]) ans++;
    else{
      for(auto [p, c]:cnt)if(p!=x&&c>=2){
        ans+=0.5; break;
      }
    }
  }
  printf("%.2f\n", ans);
  return 0; 
}