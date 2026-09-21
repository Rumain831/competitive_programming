#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//Tags: 尺取り法

int main(void){
  int n, k; cin >> n >> k;
  vector<int> t(n);
  for(auto&x:t) cin >> x;
  unordered_map<int, int> cnt;
  int l=0, r=-1, c=0, er=0, ans=-1;
  while(l<n){
    if(r<l){
      r=l, cnt.clear();
      c=0, er=0;
    }
    while(r<n){
      if(++cnt[t[r]]==1) c++;
      else er++;
      if(er>k){
        cnt[t[r]]--, er--;
        break;
      }
      r++;
    }
    ans=max(ans, c);
    if(--cnt[t[l]]==0) c--;
    else er--;
    l++;
  }
  cout << ans << endl;
  return 0; 
}