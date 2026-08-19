#include<iostream>
using namespace std;

//Tags: grid

int main(void){
  int n, m; cin >> n >> m;
  int ui=1e9, uj=1e9, di=-1, dj=-1;
  for(int i=0; i<n; i++){
    string s; cin >> s;
    for(int j=0; j<m; j++){
      if(s[j]=='#'){
        ui=min(ui, i), uj=min(uj, j);
        di=max(di, i), dj=max(dj, j);
      }
    }
  }
  cout << (di-ui+1)*(dj-uj+1) << endl;
  return 0; 
}