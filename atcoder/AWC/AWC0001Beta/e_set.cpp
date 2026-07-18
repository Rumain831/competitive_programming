#include<iostream>
#include<vector>
#include<set>
using namespace std;

//各区間の変動幅をmultisetで求めていく方法
int main(void){
  int n, k; cin >> n >> k;
  multiset<int> all;
  vector<int> h(n);
  for(auto&x:h) cin >> x;
  for(int i=0; i<k-1; i++) all.insert(h[i]);
  int ans=-2e9;
  for(int i=k-1; i<n; i++){
    all.insert(h[i]);
    ans=max(ans, *all.rbegin()-*all.begin());
    all.erase(all.find(h[i-k+1]));
  }
  cout << ans << endl;
  return 0;
}