#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

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


int main(void){
  int n, q; cin >> n >> q;
  BIT to_white(q+3), to_black(q+3);
  to_white.add(2, n);
  to_white.add(1, n);
  ll ans=0;
  vector<int> last_white(n, 2), last_black(n, 1);
  for(int i=3; i<q+3; i++){
    int t; cin >> t;
    if(t==1){
      int r; cin >> r; r--;
      int last=last_black[r];
      ans+=to_white.range(last+1, i);
      to_black.add(last, -1);
      last_black[r]=i;
      to_black.add(last_black[r], 1);
    }
    else{
      int c; cin >> c; c--;
      int last=last_white[c];
      ans-=to_black.range(last+1, i);
      to_white.add(last, -1);
      last_white[c]=i;
      to_white.add(last_white[c], 1);
    }
    cout << ans << '\n';
  } 
  return 0;
}