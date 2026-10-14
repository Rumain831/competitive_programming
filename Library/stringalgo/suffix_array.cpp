#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

struct SuffixArray{ //logつくver.
  string s;
  vector<int> sa;   //i番目に小さい接尾辞の開始index
  vector<int> rank; //接尾辞iの辞書順順位
  vector<int> lcp;  //LCP(s[sa[i-1]:], s[sa[i]:]), lcp[0]=0

  SuffixArray(){}
  SuffixArray(const string& s_){build(s_);}

  void build(const string& s_){
    s=s_;
    int n=s.size();
    sa.resize(n), rank.resize(n);

    struct info{
      int prerank, nowrank, idx;
    };
    vector<int> oldrank(n), newrank(n);
    int log=0;
    while((1<<log)<n) log++;
    for(int i=0; i<n; i++) oldrank[i]=s[i]-'a';
    for(int k=1; k<=log; k++){
      int len=1<<(k-1);
      vector<info> a(n);
      for(int i=0; i<n; i++){
        a[i].prerank=oldrank[i];
        a[i].nowrank=(i+len<n?oldrank[i+len]:-1);
        a[i].idx=i;
      }
      //カウントソート
      int maxr=0;
      for(int i=0; i<n; i++) maxr=max(maxr, oldrank[i]);
      int m=maxr+2;  //-1, 0, 1, ..., maxr
      vector<int> cnt(m);
      vector<info> tmp(n);
      for(int i=0; i<n; i++) cnt[a[i].nowrank+1]++;
      for(int i=1; i<m; i++) cnt[i]+=cnt[i-1];
      for(int i=n-1; i>=0; i--){
        tmp[--cnt[a[i].nowrank+1]]=a[i];
      }
      fill(cnt.begin(), cnt.end(), 0);
      for(int i=0; i<n; i++) cnt[tmp[i].prerank]++;
      for(int i=1; i<m; i++) cnt[i]+=cnt[i-1];
      for(int i=n-1; i>=0; i--){
        a[--cnt[tmp[i].prerank]]=tmp[i];
      }
      newrank[a[0].idx]=0;
      for(int i=1; i<n; i++){
        if(a[i].prerank==a[i-1].prerank&&a[i].nowrank==a[i-1].nowrank){
          newrank[a[i].idx]=newrank[a[i-1].idx];
        }
        else{
          newrank[a[i].idx]=newrank[a[i-1].idx]+1;
        }
      }
      swap(oldrank, newrank);
      if(oldrank[a[n-1].idx]==n-1){
        log=k; break;
      }
    }
    for(int i=0; i<n; i++) sa[oldrank[i]]=i;
    rank=oldrank;
    build_lcp();
  }

  void build_lcp(){
    int n=s.size();
    lcp.assign(n, 0);
    int h=0;
    for(int i=0; i<n; i++){
      int r=rank[i];
      if(r==0){
        h=0; continue;
      }
      int j=sa[r-1];
      while(i+h<n&&j+h<n&&s[i+h]==s[j+h]) h++;
      lcp[r]=h;
      if(h) h--;
    }
  }

  ll distinct(){
    ll ans=0, n=s.size();
    for(int i=0; i<n; i++) ans+=n-sa[i]-lcp[i];
    return ans;
  }

  string kth(ll k)const{
    ll sum=0, n=s.size();
    for(int i=0; i<n; i++){
      ll ad=n-sa[i]-lcp[i];
      if(k>ad) k-=ad;
      else{
        int len=lcp[i]+k;
        return s.substr(sa[i], len);
      }
    }
    return "";
  }
};

int main(void){
  string s="banana";
  SuffixArray p(s);
  for(auto q:p.sa) cout << q << ' '; cout << endl;
  //cout << p.distinct() << endl;
  //for(int i=1; i<=16; i++) cout << p.kth(i) << endl;
  return 0;
}