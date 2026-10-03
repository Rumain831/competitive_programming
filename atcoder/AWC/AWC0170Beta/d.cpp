#include<iostream>
#include<vector>
#include<map>
#include<tuple>
#include<algorithm>
using namespace std;
using ll = long long;
using tu = tuple<ll, ll, ll>;

//Tags: 幾何

ll gcd(ll a, ll b){
  if(b==0) return a;
  else return gcd(b, a%b);
}

tu f(ll a, ll b, ll c){
  ll g=gcd(gcd(abs(a), abs(b)), abs(c));
  a/=g, b/=g, c/=g;
  if(a<0) a*=-1, b*=-1, c*=-1;
  else if(a==0){
    if(b==0) c=1;
    else if(b<0) b*=-1, c*=-1;
  }
  return tu(a, b, c);
}

int main(void){
  ll n; cin >> n;
  vector<ll> x(n), y(n);
  for(int i=0; i<n; i++) cin >> x[i] >> y[i];
  ll ans=0;
  vector cnt(n+1, vector(2, vector<ll>(2)));
  for(int i=0; i<n; i++){
    for(int j=0; j<2; j++)for(int k=0; k<2; k++){
      cnt[i+1][j][k]+=cnt[i][j][k];
    }
    cnt[i+1][abs(x[i])%2][abs(y[i])%2]++;
  }
  for(int i=1; i<n-1; i++)for(int j=i+1; j<n; j++){
    ll a=abs(x[i]-x[j])%2, b=abs(y[i]-y[j])%2;
    for(ll p=0; p<2; p++)for(ll q=0; q<2; q++){
      ll c=abs(p-x[i])%2, d=abs(q-y[i])%2;
      ll cross=abs(a*d-b*c);
      if(cross%2==0) ans+=cnt[i][p][q];
    }
  }
  
  for(int i=0; i<n-2; i++){
    map<tu, ll> line;
    for(int j=i+1; j<n; j++){
      ll dx=x[j]-x[i], dy=y[j]-y[i];
      ll a=dy, b=dx, c=dy*x[i]-dx*y[i];
      line[f(a, b, c)]++;
    }
    for(auto&[_, x]:line){
      ans-=x*(x-1)/2;
    }
  }
  cout << ans << endl;
  return 0; 
}