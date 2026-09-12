#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

//Tags: grid, 数え上げ

int main(void){
  int h, w; cin >> h >> w;
  vector<string> s(h);
  for(auto&x:s) cin >> x;
  if(h>w){
    vector<string> t(w, string(h, '.'));
    for(int i=0; i<h; i++)for(int j=0; j<w; j++) t[j][i]=s[i][j];
    s=t;
    swap(h, w);
  }
  vector sum(h+1, vector<ll>(w));
  for(int i=0; i<h; i++)for(int j=0; j<w; j++) sum[i+1][j]=(s[i][j]=='.');
  for(int j=0; j<w; j++)for(int i=1; i<=h; i++) sum[i][j]+=sum[i-1][j];
  ll ans=0;
  for(int i1=0; i1<h; i1++)for(int i2=i1; i2<h; i2++){
    vector<int> wh(w);
    ll c=0;
    for(int j=0; j<w; j++){
      wh[j]=sum[i2+1][j]-sum[i1][j];
      if(wh[j]) c++;
    }
    int ul=0, dl=0;
    ll cu=c, cd=c;
    for(int j=0; j<w; j++){
      if(ul<j) ul=j, cu=c;
      if(dl<j) dl=j, cd=c;
      if(wh[j]==0) continue;
      while(ul<w&&s[i1][ul]=='#'){
        if(wh[ul]) cu--;
        ul++;
      }
      while(dl<w&&s[i2][dl]=='#'){
        if(wh[dl]) cd--;
        dl++;
      }
      if(ul>=w||dl>=w) continue;
      ans+=min(cu, cd);
      if(wh[j]) c--;
    }
  }
  cout << ans+1 << endl;
  return 0; 
}