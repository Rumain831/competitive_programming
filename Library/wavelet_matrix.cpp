#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/**
 * WaveletMatrix
 *   構築: O(N·logσ)
 *   メモリ: O(N·logσ) ビット + O(N·logσ) 整数 (prefix 和)
 * サポートする主な操作 (0-indexed, 区間は [l, r) で表現):
 *   kth(l, r, k)      : [l,r) の k-th smallest (0 ≤ k < r-l)
 *   countLE(l, r, x)  : [l,r) 内の要素 ≦ x の個数
 *   access(idx)       : 元の配列[idx]
 *   rank(x, l, r)     : [l,r) 内で要素 == x の個数
 */
struct WaveletMatrix{
  // int maxi = *max_element(a.begin(), a.end());
  // int LG = 0;
  // while((1<<LG)<=maxi) LG++;  呼び出す前にこれを書く
  int N, LG;
  vector<vector<bool>> bit;   // bit[d][i]：i番目要素の2^dの位 (0or1)
  vector<vector<int>> cnt0;   // cnt0[d][i]：bit[d]のi番目までの0の累積個数
  vector<int> pos1;           // pos1：bit[d]に0が何個あるか = sort後のbit[d]における最初の1の位置
  WaveletMatrix(vector<int>& a, int maxLG)
    : N(a.size()), LG(maxLG),
      bit(LG, vector<bool>(N)), cnt0(LG, vector<int>(N+1, 0)), pos1(LG)
  {
    vector<int> now=a, nxt(N);
    for(int d=LG-1; d>=0; d--){
      for(int i=0; i<N; i++){
        bool b=(now[i]>>d)&1;
        bit[d][i]=b;
        cnt0[d][i+1]=cnt0[d][i]+(b?0:1);
      }
      pos1[d]=cnt0[d][N];
      int idx0=0, idx1=pos1[d];
      for(int i=0; i<N; i++){
        if(bit[d][i]) nxt[idx1++]=now[i];
        else nxt[idx0++]=now[i];
      }
      swap(now, nxt);
    }
  }
  //[l, r)内のbit=0, bit=1の部分は次の層でそれぞれ区間をなす
  int kth(int l, int r, int k){
    int res=0;
    for(int d=LG-1; d>=0; d--){
      int cnt=cnt0[d][r]-cnt0[d][l];
      if(k<cnt){
        l=cnt0[d][l], r=cnt0[d][r];
      }
      else{
        res|=(1<<d); k-=cnt;
        l=pos1[d]+l-cnt0[d][l];
        r=pos1[d]+r-cnt0[d][r];
      }
    }
    return res;
  }

  int countsmall(int l, int r, int x){
    int ans=0;
    for(int d=LG-1; d>=0; d--){
      bool b=(x>>d)&1;
      if(b){
        ans+=cnt0[d][r]-cnt0[d][l];
        l=pos1[d]+l-cnt0[d][l];
        r=pos1[d]+r-cnt0[d][r];
      }
      else{
        l=cnt0[d][l], r=cnt0[d][r];
      }
    }
    return ans;
  }

  int access(int idx){
    int ans=0;
    for(int d=LG-1; d>=0; d--){
      bool b=bit[d][idx];
      if(b){
        ans|=1<<d;
        idx=pos1[d]+idx-cnt0[d][idx];
      }
      else idx=cnt0[d][idx];
    }
    return ans;
  }
  
  int equal(int l, int r, int x){
    for(int d=LG-1; d>=0; d--){
      bool b=(x>>d)&1;
      if(b){
        l=pos1[d]+l-cnt0[d][l];
        r=pos1[d]+r-cnt0[d][r];
      }
      else l=cnt0[d][l], r=cnt0[d][r];
    }
    return r-l;
  }

};

int main(void){
  int n; cin >> n;
  vector<int> a(n);
  int maxi=-1;
  for(int i=0; i<n; i++) cin >> a[i], maxi=max(maxi, a[i]);
  int log=0;
  while((1ll<<log)<=maxi) log++;
  WaveletMatrix wm(a, log);
  return 0;
}