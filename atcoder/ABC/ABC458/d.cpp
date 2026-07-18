#include<iostream>
#include<set>
using namespace std;

int main(void){
  int x, q; cin >> x >> q;
  int cnt=1, ans=0;
  multiset<int> pre={x}, aft;
  auto adjust=[&](){
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
  while(q--){
    int a, b; cin >> a >> b;
    if(pre.empty()) pre.insert(a), pre.insert(b);
    else{
      if(a<=*pre.rbegin()) pre.insert(a);
      else aft.insert(a);
      if(b<=*pre.rbegin()) pre.insert(b);
      else aft.insert(b);
    }
    cnt+=2;
    adjust();
    cout << *pre.rbegin() << '\n';
  }
  return 0;
}