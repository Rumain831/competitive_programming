#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
using ll = long long;

struct Median{
  int cnt=0;
  multiset<ll> pre, aft;
  Median(){}
  void adjust(){
    int p=(cnt+1)/2;
    while((int)pre.size()>p){
      auto it=pre.end(); it--;
      aft.insert(*it);
      pre.erase(it);
    }
    while((int)pre.size()<p){
      pre.insert(*aft.begin());
      aft.erase(aft.begin());
    }
  };
  void insert(ll x){
    if(pre.empty()){
      cnt++;
      pre.insert(x); return;
    }
    if(x<=*pre.rbegin()) pre.insert(x);
    else aft.insert(x);
    cnt++;
    adjust();
  }
  ll val(){
    return *pre.rbegin();
  }
};

int main(void){
  
}