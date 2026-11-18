#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: grid

int f(vector<int>& a, int x){
  auto it=lower_bound(begin(a), end(a), x);
  auto it0=prev(it);
  return (*it)-(*it0)-1;
}

int main(void){
  int h, w; cin >> h >> w;
  vector<string> s(h);
  vector<vector<int>> tate(h), yoko(w);
  for(int i=0; i<h; i++) tate[i]={-1, w};
  for(int i=0; i<w; i++) yoko[i]={-1, h};
  for(int i=0; i<h; i++){
    cin >> s[i];
    for(int j=0; j<w; j++)if(s[i][j]=='#'){
      tate[i].push_back(j);
      yoko[j].push_back(i);
    }
  }
  for(int i=0; i<h; i++) sort(begin(tate[i]), end(tate[i]));
  for(int i=0; i<w; i++) sort(begin(yoko[i]), end(yoko[i]));
  int ans=-1;
  for(int i=0; i<h; i++)for(int j=0; j<w; j++)if(s[i][j]=='.'){
    int now=f(tate[i], j)+f(yoko[j], i)-1;
    ans=max(ans, now);
  }
  cout << ans << endl;
  return 0; 
}