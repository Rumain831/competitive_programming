#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

template<class T=ll>
struct Cartesian{
  int n, root;
  vector<int> l, r, p;
  Cartesian(){}
  Cartesian(const vector<T>& a, bool maxi=true){
    n=a.size();
    l=r=p=vector<int>(n, -1);
    vector<int> st;
    for(int i=0; i<n; i++){
      int par=-1;
      if(maxi){
        while(st.size()&&a[st.back()]<a[i]){
          par=st.back();
          st.pop_back();
        }
      }
      else{
        while(st.size()&&a[st.back()]>a[i]){
          par=st.back();
          st.pop_back();
        }
      }
      if(st.size()) r[st.back()]=i, p[i]=st.back();
      if(par!=-1){
        l[i]=par; p[par]=i;
      }
      st.push_back(i);
    }
    root=0;
    while(p[root]!=-1) root=p[root];
  }
};