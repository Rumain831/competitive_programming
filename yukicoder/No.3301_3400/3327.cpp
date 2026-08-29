#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: segtree, 二分探索
//Level: 3

template<class Tr=int>
struct segtree{
  int N;
  Tr iden;
  vector<Tr> tree;
 
  Tr op(Tr a, Tr b){return max(a, b);}
  
  int pow2(int n){
    int ans=1;
    while(ans<n) ans*=2;
    return ans;
  }

  //aの型に注意
  void build(vector<Tr> &a){
    int n=a.size();
    N=pow2(n);
    iden=-1;
    tree.resize(2*N, iden);
    for(int i=0; i<n; i++) tree[N+i]=a[i];
    for(int i=N-1; i>=1; i--) tree[i]=op(tree[2*i], tree[2*i+1]);
  }

  void update(int node, Tr x){  //0-indexed
    int i=node+N;
    tree[i]=x; i/=2;
    while(i>0){
      tree[i]=op(tree[2*i], tree[2*i+1]); i/=2;
    }
    return;
  }

  Tr query(int s, int t){  //0-indexed
    int left=s+N, right=t+N;
    Tr ansl=iden, ansr=iden;
    while(left<=right){
      if(left%2==1){
        ansl=op(ansl, tree[left]); left++;
      }
      if(right%2==0){
        ansr=op(tree[right], ansr); right--;
      }
      left/=2, right/=2;
    }
    return op(ansl, ansr);
  }
};


int main(void){
  int n, q; cin >> n >> q;
  vector<int> a(n);
  for(auto&x:a) cin >> x;
  segtree seg;
  seg.build(a);
  while(q--){
    int c, x; cin >> c >> x;
    int tar=-1;
    if(seg.query(0, n-1)<=x){
      cout << -1 << '\n';
      continue;
    }
    if(c==1){
      if(seg.query(0, 0)>x){
        cout << 1 << '\n';
        tar=0;
        seg.update(tar, -1);
        continue;
      }
      int left=0, right=n-1;
      while(right-left>1){
        int mid=(left+right)/2;
        if(seg.query(0, mid)<=x) left=mid;
        else right=mid;
      }
      tar=right;
    }
    else{
      if(seg.query(n-1, n-1)>x){
        cout << n << '\n';
        tar=n-1;
        seg.update(tar, -1);
        continue;
      }
      int left=0, right=n-1;
      while(right-left>1){
        int mid=(left+right)/2;
        if(seg.query(mid, n-1)<=x) right=mid;
        else left=mid;
      }
      tar=left;
    }
    cout << tar+1 << '\n';
    seg.update(tar, -1);
  }
  return 0;
}
