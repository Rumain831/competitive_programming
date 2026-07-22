#include<iostream>
#include<vector>
using namespace std;

//Tags: データ構造

int main(void){
  int n, q; cin >> n >> q;
  vector<int> pre(n, -1), aft(n, -1);
  while(q--){
    int t; cin >> t;
    if(t==1){
      int x, y; cin >> x >> y; x--, y--;
      aft[x]=y, pre[y]=x;
    }
    else if(t==2){
      int x, y; cin >> x >> y; x--, y--;
      aft[x]=-1, pre[y]=-1;
    }
    else{
      int x; cin >> x; x--;
      int top=x;
      while(pre[top]!=-1) top=pre[top];
      vector<int> ans;
      while(top!=-1){
        ans.push_back(top+1);
        top=aft[top];
      }
      cout << ans.size() << ' ';
      for(auto p:ans) cout << p << ' ';
      cout << '\n';
    }
  }
  return 0;
}