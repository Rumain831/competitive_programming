#include<iostream>
#include<vector>
using namespace std;

//Tags: Simulation
//Level: 3

template<class Tr=int>
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

int main(void){
  int n, k; cin >> n >> k;
  int mx=1e6;
  BIT bit(mx);
  while(n--){
    int w; cin >> w;
    if(w<0){
      w*=-1;
      if(bit.range(w, w)) bit.add(w, -1);
    } 
    else{
      int cnt=bit.range(w, mx);
      if(cnt<k){
        bit.add(w, 1);
      }
    }
  }
  cout << bit.range(1, mx) << endl;
  return 0; 
}