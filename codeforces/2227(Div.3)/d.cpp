#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

//1つ目の0と2つ目の0をともに含む回文, 1つ目の0を中心に広がる回文, 2つ目の0を中心に広がる回文 を見る
void solve(){
  int n; cin >> n;
  vector<int> a(2*n), one(n, -1), two(n, -1);
  for(int i=0; i<2*n; i++){
    cin >> a[i];
    if(one[a[i]]==-1) one[a[i]]=i;
    else two[a[i]]=i;
  }
  
  auto Two=[&](int l, int r){
    vector<int> cnt(n+1);
    while(l<=r){
      cnt[a[l]]++;
      l++, r--;
      if(a[l]!=a[r]){
        return 0;
      }
    }
    l=one[0], r=two[0];
    while(l>=0&&r<2*n){
      if(a[l]!=a[r]) break;
      cnt[a[l]]++;
      l--, r++;
    }
    for(int i=0; i<=n; i++){
      if(cnt[i]==0){
        return i;
      }
    }
  };
  auto One=[&](int i){
    vector<int> cnt(n+1);
    int l=i, r=i;
    while(l>=0&&r<2*n){
      if(a[l]!=a[r]) break;
      cnt[a[l]]++;
      l--, r++;
    }
    for(int i=0; i<=n; i++)if(cnt[i]==0) return i;
  };
  cout << max({Two(one[0], two[0]), One(one[0]), One(two[0])}) << endl;
};

int main(void){
  int t; cin >> t;
  while(t--){
    solve();
  }
  return 0; 
}
