#include<iostream>
using namespace std;

int main(void){
  int n, l, w; cin >> n >> l >> w;
  int ans=0;
  for(int i=0; i<n; i++){
    int d; cin >> d;
    if(l-w<=d&&d<=l+w) ans++;
  }
  cout << ans << endl;
  return 0;
}