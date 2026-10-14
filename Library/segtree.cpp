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
  int N;
  Tr iden;

  Tr op(Tr a, Tr b){
    return a+b;
  }

  struct Node{
    Tr val;
    Node* left;
    Node* right;
    Node(Tr val=Tr()): val(val), left(nullptr), right(nullptr){}
    Node(Tr val, Node* left, Node* right): val(val), left(left), right(right) {}
  };

  PerSegtree(int n){
    N=1;
    iden=0;
    while(N<n) N<<=1;
  }

  Node* new_leaf(Tr x){
    return new Node(x);
  }
  Node* new_parent(Node* left, Node* right){
    return new Node(op(left->val, right->val), left, right);
  }
  Node* build(vector<Tr>& a, int l, int r){ //[l, r)
    if(r-l==1){
      if(l<(int)a.size()) return new_leaf(a[l]);
      else return new_leaf(iden);
    }
    int mid=(l+r)/2;
    Node* left=build(a, l, mid);
    Node* right=build(a, mid, r);
    return new_parent(left, right);
  }
  Node* build(vector<Tr>& a){
    N=1;
    while(N<(int)a.size()) N<<=1;
    return build(a, 0, N);
  }

  Tr query(Node* node, int nl, int nr, int ql, int qr){
    //nodeが担う区間が[nl, nr), 所望の区間が[ql, qr)
    if(nr<=ql||qr<=nl) return iden;
    if(ql<=nl&&nr<=qr) return node->val;
    int mid=(nl+nr)/2;
    Tr le=query(node->left, nl, mid, ql, qr);
    Tr ri=query(node->right, mid, nr, ql, qr);
    return op(le, ri);
  }
  Tr query(Node* root, int l, int r){
    return query(root, 0, N, l, r);
  }

  Node* update(Node* node, int nl, int nr, int pos, Tr x){
    if(nr-nl==1){
      return new_leaf(x);
    }
    int mid=(nl+nr)/2;
    if(pos<mid){
      Node* newleft=update(node->left, nl, mid, pos, x);
      Node* newright=node->right;
      return new_parent(newleft, newright);
    }
    else{
      Node* newleft=node->left;
      Node* newright=update(node->right, mid, nr, pos, x);
      return new_parent(newleft, newright);
    }
  }
  Node* update(Node* root, int pos, Tr x){
    return update(root, 0, N, pos, x);
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
