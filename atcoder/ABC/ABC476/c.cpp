#include<iostream>
#include<vector>
#include<set>
using namespace std;

//Tags: Simulation

int main(void){
  int n; cin >> n;
  vector<int> a(n);
  for(auto&x:a) cin >> x;
  multiset<int> st;
  st.insert(a[0]);
  st.insert(a[1]);
  for(int i=2; i<n; i++){
    st.insert(a[i]);
    if(st.size()>3) st.erase(begin(st));
    cout << *begin(st) << '\n';
  }
  return 0; 
}