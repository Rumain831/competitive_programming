#include<iostream>
#include<vector>
using namespace std;

//Tags: grid

vector<string> rot(vector<string> p){
  int h=p.size(), w=p[0].size();
  swap(h, w);
  vector<string> ans(h, string(w, '.'));
  for(int i=0; i<h; i++)for(int j=0; j<w; j++) ans[i][j]=p[w-1-j][i];
  return ans;
}

int main(void){
  int r, k, h, w; cin >> r >> k >> h >> w;
  vector<string> s(h);
  for(auto&x:s) cin >> x;
  int c=r/90;
  for(int i=0; i<c; i++){
    swap(h, w);
    s=rot(s);
  }
  vector ans(h*k, string(w*k, '.'));
  for(int i=0; i<h; i++)for(int j=0; j<w; j++){
    int si=k*i, sj=k*j;
    for(int p=0; p<k; p++)for(int q=0; q<k; q++) ans[si+p][sj+q]=s[i][j];
  }
  for(auto p:ans) cout << p << '\n';
  return 0; 
}