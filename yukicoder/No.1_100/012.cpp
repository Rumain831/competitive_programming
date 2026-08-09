#include<iostream>
#include<vector>
using namespace std;

//Tags: 尺取り法, 素数

int main(void){
  int n; cin >> n;
  int tar=0;
  for(int i=0; i<n; i++){
    int a; cin >> a;
    tar|=(1<<a);
  }
  int nn=5e6;
  vector<int> yakusu(nn+1, -1), prime;
  for(int i=2; i<=nn; i++){
    if(yakusu[i]!=-1) continue;
    int copy=i;
    prime.push_back(i);
    while(copy<=nn){
      if(yakusu[copy]==-1) yakusu[copy]=i;
      copy+=i;
    }
  }
  vector<int> cnt(10);
  int l=1, r=-1, now=0, ans=-1;
  while(l<=nn){
    if(r<l) r=l;
    bool over=false;
    while(r<=nn){
      if(yakusu[r]!=r){
        r++; continue;
      }
      int p=r;
      int use[10]={}, b=0;
      while(p){
        int x=p%10;
        use[x]++, b|=(1<<x);
        p/=10;
      }
      if((b&tar)!=b){
        over=true; break;
      }
      for(int i=0; i<10; i++) cnt[i]+=use[i];
      now|=b;
      r++;
    }
    if(over||r>nn){
      if(now==tar){
        ans=max(ans, r-1-l);
      }
      for(int i=0; i<10; i++) cnt[i]=0;
      now=0;
      l=r+1;
    }
  }
  cout << ans << endl;
  return 0; 
}