#include<bits/stdc++.h>
using namespace std;
using ll=long long;

template<class Tr=ll>
struct BIT{
  int n;
  vector<Tr> bit;
  BIT(int size): n(size), bit(size+1, 0) {};

  void add(int i, Tr x){ //1-indexed
    while(i<=n){
      bit[i]+=x;
      i+=i&-i;
    }
  }

  Tr sum(int i){ //1-indexed
    Tr ans=0;
    while(i>0){
      ans+=bit[i];
      i-=i&-i;
    }
    return ans;
  }

  Tr range(int l, int r){ //1-indexed
    return sum(r)-sum(l-1);
  }
};
