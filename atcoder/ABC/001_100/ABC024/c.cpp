#include<iostream>
#include<vector>
using namespace std;

//Tags: Simulation

int main(void){
  int n, d, k; cin >> n >> d >> k;
  vector<int> l(d), r(d), s(k), t(k);
  for(int i=0; i<d; i++) cin >> l[i] >> r[i];
  for(int i=0; i<k; i++) cin >> s[i] >> t[i];
  for(int i=0; i<k; i++){
    int L=s[i], R=L;
    for(int j=0; j<d; j++){
      int nl=l[j], nr=r[j];
      if(max(L, nl)>min(R, nr)) continue;
      L=min(L, nl), R=max(R, nr);
      if(L<=t[i]&&t[i]<=R){
        cout << j+1 << '\n';
        break;
      }
    }
  }
  return 0;
}