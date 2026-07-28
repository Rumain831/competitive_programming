#include<iostream>
#include<vector>
using namespace std;

//Tags: 尺取り法, 素数

int digit(int i){
  if(i<10) return i;
  int sum=0;
  while(i){
    sum+=i%10;
    i/=10;
  }
  return digit(sum);
}

int main(void){
  int k, n; cin >> k >> n;
  vector<bool> used(10);
  int nn=n;
  vector<int> yakusu(nn+1, -1), prime;
  for(int i=2; i<=nn; i++){
    if(yakusu[i]!=-1) continue;
    int copy=i;
    if(i>=k) prime.push_back(i);
    while(copy<=nn){
      if(yakusu[copy]==-1) yakusu[copy]=i;
      copy+=i;
    }
  }
  int mx=-1, l=0, r=-1, m=prime.size(), ans;
  while(l<m){
    if(r<l) r=l;
    while(r<m){
      int now=digit(prime[r]);
      if(used[now]) break;
      used[now]=true;
      r++;
    }
    int nl=r-l+1;
    if(mx<=nl) mx=nl, ans=prime[l];
    used[digit(prime[l])]=false;
    l++;
  }
  cout << ans << endl;
  return 0;
}