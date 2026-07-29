#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: 整数, 素数
//答えがNOになるのは、n=1 or nが素数 or n=pq(p, qは相異なる素数) のとき
int main(void){
  ll n; cin >> n;
  if(n==1){
    cout << "NO" << endl; return 0;
  }
  int nn=1e7+1;
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
  auto judge=[&](ll x){
    for(auto p:prime){
      if((ll)p*p>x) break;
      if(x%p==0) return false;
    }
    return true;
  };
  if(judge(n)){
    cout << "NO" << endl; return 0;
  }
  for(auto p:prime){
    if(p>n) break;
    if(n%p) continue;
    cout << (judge(n/p)?"NO":"YES") << endl;
    return 0;
  }
  return 0; 
}