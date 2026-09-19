#include<iostream>
#include<vector>
using namespace std;
using ll = long long;
using P = pair<int, int>;

//Tags: チェビシェフ距離, 累積和, 差分更新

ll n;
P co(int i, int j){return P(i+j+1, n+j-i);}
//(i, j) -> (i+j+1, n+j-i)
int main(void){
  ll m; cin >> n >> m;
  vector<ll> a(n), b(n);
  for(auto&x:a) cin >> x; 
  for(auto&x:b) cin >> x; 
  int n2=2*n;
  vector sum(n2, vector<ll>(n2));
  for(int i=0; i<n; i++)for(int j=0; j<n; j++){
    int ni=i+j+1, nj=n+j-i;
    sum[ni][nj]=(a[i]*b[j])%m;
  }
  for(int i=1; i<n2; i++)for(int j=0; j<n2-1; j++) sum[i][j+1]+=sum[i][j];
  for(int j=1; j<n2; j++)for(int i=0; i<n2-1; i++) sum[i+1][j]+=sum[i][j];
  ll ans=0, now=0;
  for(int i=0; i<n; i++)for(int j=0; j<n; j++) now+=(a[i]*b[j])%m*max(i, j);
  auto area=[&](int ui, int di, int lj, int rj){
    return sum[di][rj]-sum[ui-1][rj]-sum[di][lj-1]+sum[ui-1][lj-1];
  };
  ans=now;
  for(int i=0; i<n; i++){
    int d=(i&1?-1:1), j=(i&1?n-1:0);
    while(j+d>=0&&j+d<n){
      auto [ni, nj]=co(i, j);
      auto [nni, nnj]=co(i, j+d);
      //右 d=1
      if(d==1) now+=area(1, ni, 1, nj)-area(nni, n2-1, nnj, n2-1);
      //左 d=-1
      if(d==-1) now+=area(ni, n2-1, nj, n2-1)-area(1, nni, 1, nnj);
      j+=d;
      ans^=(now+i*n+j);
    }
    if(i==n-1) break;
    //下
    auto [ni, nj]=co(i, j);
    auto [nni, nnj]=co(i+1, j);
    now+=area(1, ni, nj, n2-1)-area(nni, n2-1, 1, nnj);
    ans^=(now+(i+1)*n+j);
  }
  cout << ans << endl;
  return 0; 
}