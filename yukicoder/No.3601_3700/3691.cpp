#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: メビウス関数
//Level: 2

vector<int> mobius(int n){
  vector<int> prime, mu(n+1);
  vector<bool> pq(n+1, false);
  mu[1]=1;
  for(int i=2; i<=n; i++){
    if(!pq[i]){
      prime.push_back(i);
      mu[i]=-1;
    }
    for(auto p:prime){
      ll m=(ll)i*p;
      if(m>n) break;
      pq[m]=true;
      if(i%p) mu[m]=-mu[i];
      else{mu[m]=0; break;}
    }
  }
  return mu;
}

int main(void){
  int n; cin >> n;
  auto p=mobius(n);
  int ans=0;
  for(int i=1; i<=n; i++) ans+=p[i];
  cout << ans << endl;
  return 0; 
}