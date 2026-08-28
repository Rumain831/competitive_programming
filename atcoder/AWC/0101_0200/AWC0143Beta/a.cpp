#include<iostream>
#include<vector>
using namespace std;

//Tags: grid

int main(void){
  int h, w; cin >> h >> w;
  int ui=1e9, uj=1e9, di=-1, dj=-1;
  for(int i=0; i<h; i++){
    string s; cin >> s;
    for(int j=0; j<w; j++)if(s[j]=='#'){
      ui=min(ui, i), uj=min(uj, j);
      di=max(di, i), dj=max(dj, j);
    }
  }
  if(di==-1) cout << 0 << endl;
  else cout << (di-ui+dj-uj+2)*2 << endl;
  return 0; 
}