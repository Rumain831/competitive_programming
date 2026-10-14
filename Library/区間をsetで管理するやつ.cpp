#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
using ll = long long;

struct IntervalSet{
  using Pa=pair<ll, ll>;
  set<Pa> seg;
  ll len_sum=0;

  //区間追加
  void insert(ll l, ll r){ //[l, r)
    if(l>=r) return;
    ll addl=l, addr=r;
    auto it=seg.lower_bound(Pa(l, -1e18));
    //lが直前の区間に含まれる場合
    if(it!=seg.begin()){
      auto pre=prev(it);
      if(pre->second>=l) it=pre;
    }
    while(it!=seg.end()){
      if(addr<(it->first)) break;
      addl=min(addl, it->first);
      addr=max(addr, it->second);
      len_sum-=(it->second)-(it->first);
      it=seg.erase(it);
    }
    seg.insert(Pa(addl, addr));
    len_sum+=addr-addl;
  }

  void erase(ll l, ll r){
    if(l>=r) return;
    auto it=seg.lower_bound(Pa(l, -1e18));
    //lが直前の区間に含まれる場合
    if(it!=seg.begin()){
      auto pre=prev(it);
      if(pre->second>l) it=pre;
    }
    while(it!=seg.end()){
      if(r<=(it->first)) break;
      auto [a, b]=*it;
      len_sum-=b-a;
      it=seg.erase(it);
      if(a<l){
        seg.insert(Pa(a, l));
        len_sum+=l-a;
      }
      if(r<b){
        seg.insert(Pa(r, b));
        len_sum+=b-r;
        break;
      }
    }
  }
};

int main(void){
  
  return 0; 
}