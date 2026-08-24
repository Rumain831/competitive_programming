#include<iostream>
#include<vector>
using namespace std;

//Tags: 構築, 順列

vector<int> test(vector<int>& p){
  int n=p.size();
  vector<int> ans(n);
  for(int i=0; i<n; i++){
    for(int d=-1; d<=1; d++){
      int ni=(i+d+n)%n;
      ans[i]+=(p[i]>p[ni]);
    }
  }
  return ans;
}

int main(void){
  int n; cin >> n;
  vector<int> a(n), ans(n, -1);
  for(auto&x:a) cin >> x;
  int vl=1, vr=n, zero=-1;
  for(int i=0; i<n; i++){
    if(a[i]==0) ans[i]=vl++, zero=i;
    else if(a[i]==2) ans[i]=vr--;
  }
  if(zero==-1){
    cout << -1 << endl; return 0;
  }
  int pre=0, st=zero;
  for(int i=0; i<n; i++){
    int id=(zero+i)%n;
    if(ans[id]!=-1){
      pre=a[id]; continue; 
    }
    while(a[id]==1){
      if(pre==0) ans[id]=vl++;
      else ans[id]=vr--;
      id=(id+1)%n;
    }
  }
  vector<int> ts=test(ans);
  if(ts==a){
    for(auto p:ans) cout << p << ' '; cout << endl;
  }
  else cout << -1 << endl;
  return 0; 
}