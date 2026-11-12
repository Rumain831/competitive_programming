#include<bits/stdc++.h>
using namespace std;
using ll = long long;

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
    tree[i]=op(tree[i], x); i/=2;
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

template<class Tr=int, class La=int>
struct lazytree{
  int N;
  Tr iden;     vector<Tr> tree;
  La lazyiden; vector<La> lazy;
   
  int pow2(int n){
    int ans=1;
    while(ans<n) ans*=2;
    return ans;
  }

  //単位元を忘れずに書き換えること
  Tr opt(Tr a, Tr b){
    return min(a, b);
  }
  void ltot(Tr& tr, La la, int l, int r){ //tr+=la*(r-l+1)
    tr=la;
  }
  void composition(La& la_old, La la_new){ //lac+=lap
    la_old=la_new;
  }
  
  //書き方次第ではaの型も気にすべし
  void build(vector<Tr>& a){
    int n=a.size();
    N=pow2(n);
    iden=INT_MAX, lazyiden=INT_MAX;
    tree.resize(2*N, iden), lazy.resize(2*N, lazyiden);
    for(int i=0; i<n; i++) tree[N+i]=a[i];
    for(int i=N-1; i>=1; i--) tree[i]=opt(tree[2*i], tree[2*i+1]);
  }

  void apply(int k, La x, int l, int r){
    ltot(tree[k], x, l, r);
    composition(lazy[k], x);
  }

  void push(int k, int l, int r){ //自分に溜まったlazyを子に伝える
    if(lazy[k]==lazyiden||l==r) return;
    int mid=(l+r)/2;
    apply(2*k, lazy[k], l, mid);
    apply(2*k+1, lazy[k], mid+1, r);
    lazy[k]=lazyiden;
  }

  void update(int s, int t, La x, int k=1, int l=1, int r=-1){ //s, tは1-indexed!
    if(r<0) r=N;
    if(t<l||r<s) return;
    if(s<=l&&r<=t){
      apply(k, x, l, r);
      return;
    }
    push(k, l, r);
    int mid=(l+r)/2;
    update(s, t, x, 2*k, l, mid);
    update(s, t, x, 2*k+1, mid+1, r);
    tree[k]=opt(tree[2*k], tree[2*k+1]);
    return;
  }

  Tr query(int s, int t, int k=1, int l=1, int r=-1){ //s, tは1-indexed!
    if(r<0) r=N;
    if(t<l||r<s) return iden;
    if(s<=l&&r<=t) return tree[k];
    push(k, l, r);
    int mid=(l+r)/2;
    Tr A=query(s, t, 2*k, l, mid);
    Tr B=query(s, t, 2*k+1, mid+1, r);
    return opt(A, B);
  }
};

template<class Tr=ll>
struct seg2Dtree{
  int H, W;
  Tr iden;
  vector<vector<Tr>> tree;
  
  int pow2(int n){
    int ans=1;
    while(ans<n) ans*=2;
    return ans;
  }

  Tr op(Tr a, Tr b){ //可換モノイドでないとダメ
    return max(a, b);
  }

  void build(vector<vector<Tr>> &a, int h, int w){
    H=pow2(h), W=pow2(w);
    iden=-1;
    tree.resize(2*H, vector<Tr>(2*W, iden));
    for(int i=0; i<h; i++){
      for(int j=0; j<w; j++) tree[i+H][j+W]=a[i][j];
      for(int j=W-1; j>=1; j--) tree[i+H][j]=op(tree[i+H][2*j], tree[i+H][2*j+1]);
    }
    for(int j=2*W-1; j>=1; j--)for(int i=H-1; i>=1; i--) tree[i][j]=op(tree[2*i][j], tree[2*i+1][j]);
  }

  void update(int nodeh, int nodew, Tr x){  //0-indexed
    int i=nodeh+H, j=nodew+W, jj=j/2;
    tree[i][j]=x;
    while(jj>0){
      tree[i][jj]=op(tree[i][2*jj], tree[i][2*jj+1]); jj/=2;
    }
    i/=2;
    while(i>0){
      jj=j;
      tree[i][jj]=op(tree[2*i][jj], tree[2*i+1][jj]);
      jj/=2;
      while(jj>0){
        tree[i][jj]=op(tree[i][2*jj], tree[i][2*jj+1]);
        jj/=2;
      }
      i/=2;
    }
    return;
  }

  Tr row_query(int node, int sw, int tw){
    int left=sw+W, right=tw+W;
    Tr ans=iden;
    while(left<=right){
      if(left%2==1){
        ans=op(ans, tree[node][left]); left++;
      }
      if(right%2==0){
        ans=op(tree[node][right], ans); right--;
      }
      left/=2, right/=2;
    }
    return ans;
  }

  Tr query(int sh, int th, int sw, int tw){  //0-indexed
    int left=sh+H, right=th+H;
    Tr ans=iden;
    while(left<=right){
      if(left%2==1){
        ans=op(ans, row_query(left, sw, tw)); left++;
      }
      if(right%2==0){
        ans=op(row_query(right, sw, tw), ans); right--;
      }
      left/=2, right/=2;
    }
    return ans;
  }
};

template<class Tr=ll>
struct PerSegtree{
  struct Node{
    int l, r;
    Tr val;
    Node(int l, int r, Tr val):l(l), r(r), val(val){}
  };
  int N;
  Tr iden;
  vector<Node> tree;
  vector<int> root_id;

  Tr op(Tr a, Tr b){
    return a+b;
  }

  int build(int l, int r, const vector<Tr>& a){ //[l, r)
    int id=tree.size();
    tree.emplace_back(-1, -1, iden);
    if(r-l==1){
      tree[id].val=a[l];
      return id;
    }
    int mid=(l+r)/2;
    int left=build(l, mid, a);
    int right=build(mid, r, a);
    tree[id].l=left, tree[id].r=right;
    tree[id].val=op(tree[left].val, tree[right].val);
    return id;
  }

  //[l, r)を担当するNode ti、a_pos=xにする
  int upd(int ti, int l, int r, int pos, Tr x){
    int nti=tree.size();
    tree.push_back(tree[ti]);
    if(r-l==1){
      tree[nti].val=x;
      return nti;
    }
    int mid=(l+r)/2;
    int left=tree[nti].l, right=tree[nti].r;
    if(pos<mid) left=upd(left, l, mid, pos, x);
    else right=upd(right, mid, r, pos, x);
    tree[nti].l=left, tree[nti].r=right;
    tree[nti].val=op(tree[left].val, tree[right].val);
    return nti;
  }

  //[l, r)を担当するNode ti, クエリが[ql, qr)
  Tr qu(int ti, int l, int r, int ql, int qr){
    if(r<=ql||qr<=l) return iden;
    if(ql<=l&&r<=qr) return tree[ti].val;
    int mid=(l+r)/2;
    Tr L=qu(tree[ti].l, l, mid, ql, qr);
    Tr R=qu(tree[ti].r, mid, r, ql, qr);
    return op(L, R);
  }

  PerSegtree(const vector<Tr>& a){
    N=a.size();
    iden=0;
    int ri=build(0, N, a);
    root_id.push_back(ri);
  }

  void update(int ver, int i, Tr x){ //0-indexed
    int nti=upd(root_id[ver], 0, N, i, x);
    root_id.push_back(nti);
  }
  
  Tr query(int ver, int l, int r){ //[l, r), 0-indexed
    return qu(root_id[ver], 0, N, l, r);
  }

};


int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11}; // 元の配列
    int n = arr.size();                    // 元の配列のサイズ

    segtree segTree;       // Segment Treeを作成
    segTree.build(arr); // Segment Treeを初期化（構築）

    //cout << "Segment Tree:" << endl;
    //segTree.printTree(); // Segment Treeを表示
    cout << segTree.query(2, 5) << endl;

    return 0;
}
