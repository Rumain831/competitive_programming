#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: 貪欲法

int f(vector<int> a, vector<int> b){
  int na=a.size(), nb=b.size();
  int pre=1e9, ia=0, ib=0, ans=0;
  while(ia<na){
    while(ia<na){
      if(pre>a[ia]){
        ans++;
        pre=a[ia]; break;
      }
      ia++;
    }
    if(ia==na) break;
    while(ib<nb){
      if(pre>b[ib]){
        ans++;
        pre=b[ib]; break;
      }
      ib++;
    }
    if(ib==nb) break;
  }
  return ans;
}

int main(void){
  int nw, nb; 
  cin >> nw;
  vector<int> w, b;
  for(int i=0; i<nw; i++){int x; cin >> x; w.push_back(x);}
  cin >> nb;  
  for(int i=0; i<nb; i++){int x; cin >> x; b.push_back(x);} 
  sort(rbegin(w), rend(w)); 
  sort(rbegin(b), rend(b)); 
  int ans=max(f(w, b), f(b, w));
  cout << ans << endl;
  return 0; 
}