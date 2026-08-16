#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//Tags: 構築

int main(void){
  int n; cin >> n;
  vector<int> a(n), ans(n);
  for(auto&x:a) cin >> x;
  sort(rbegin(a), rend(a));
  set<int> ok;
  for(int i=1; i<=n; i++) ok.insert(i-1);
  for(int i=0; i<n; i++){
    int m=a[i];
    auto it=ok.lower_bound(m);
    if(it==ok.end()){
      cout << "No" << endl; return 0;
    }
    int id=*it;
    ans[id]=m;
    ok.erase(it);
  }
  cout << "Yes" << endl;
  for(auto p:ans) cout << p << ' '; cout << endl;
  return 0; 
}