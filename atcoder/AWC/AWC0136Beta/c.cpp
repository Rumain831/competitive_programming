#include<iostream>
#include<vector>
using namespace std;
using P = pair<int, int>;

//Tags: Simulation

int main(void){
  int n; cin >> n;
  vector<int> h(n);
  for(auto&x:h) cin >> x;
  vector<P> p(n+1, P(-1, 0));
  {
    int pre=-1, c=0;
    for(int i=0; i<n; i++){
      int now=h[i];
      if(pre<now) pre=now, c++;
      p[i+1]=P(pre, c);
    }
  }
  vector<P> aft;
  int ans=0, id=0;
  for(int i=n-1; i>=0; i--){
    auto [mh, nc]=p[i];
    while(id<aft.size()){
      auto [H, ni]=aft[id];
      if(H<=mh) break;
      else id++;
    }
    ans=max(ans, nc+id);
    int bi=aft.size();
    int now=h[i];
    while(aft.size()){
      auto [H, ni]=aft.back();
      if(H<=now){
        aft.pop_back(), bi--;
      }
      else break;
    }
    aft.emplace_back(now, i);
    id=min(id, bi);
  }
  cout << ans << endl;
  return 0; 
}