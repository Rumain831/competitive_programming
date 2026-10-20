#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
using ll = long long;

//Tags: Simulation

int main(void){
  int n, q; cin >> n >> q;
  vector<ll> a(n);
  set<int> st;
  for(auto&x:a) cin >> x;
  for(int i=0; i<n; i++)if(a[i]) st.insert(i);
  while(q--){
    int l, r; cin >> l >> r; l--, r--;
    auto it=st.lower_bound(l);
    ll nl=0, nr=0, ans=0;
    while(1){
      if(it==end(st)) break;
      int id=*it;
      if(id>r) break;
      int d1=abs(id-l), d2=abs(r-id);
      if(d1<=d2) ans+=d1*a[id], nl+=a[id];
      else ans+=d2*a[id], nr+=a[id];
      a[id]=0;
      it=st.erase(it);
    }
    a[l]+=nl, a[r]+=nr;
    st.insert(l);
    st.insert(r);
    cout << ans << '\n';
  }
  return 0; 
}