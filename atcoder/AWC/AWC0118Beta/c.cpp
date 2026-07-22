#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
  int n, m; cin >> n >> m;
  string s; cin >> s;
  int id=0, l=s.size();
  vector<int> in;
  string t="ATCODER";
  int L=t.size();
  int ans=0;
  while(id<l){
    int c=0, p=id;
    while(id<l){
      if(s.substr(id, L)==t) id+=L, c++;
      else break;
    }
    if(c==0){
      id++;
      continue;
    }
    if(p==0||id==l){
      if(p==0&&id==l){
        cout << (m>=c-1?c:m) << endl;
        return 0;
      }
      else{
        int d=min(c, m);
        ans+=d; m-=d;
      }
      continue;
    }
    in.push_back(c);
  }
  sort(rbegin(in), rend(in));
  for(int c:in){
    if(m<=1) break;
    int d=min(m-1, c);
    ans+=d, m-=d+1;
  }
  cout << ans << endl;
  return 0; 
}