#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: 貪欲法

int main(void){
  int l, n; cin >> l >> n;
  vector<int> w(n);
  for(int i=0; i<n; i++) cin >> w[i];
  sort(w.begin(), w.end());
  int now=0, ans=0;
  for(int i=0; i<n; i++){
    if(now+w[i]<=l) now+=w[i], ans++;
    else break;
  }
  cout << ans << endl;
  return 0;
}