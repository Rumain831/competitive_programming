#include<iostream>
#include<vector>
using namespace std;

int main(void){
  int h, w; cin >> h >> w;
  vector<string> s(h);
  int ui=1e9, uj=1e9, di=-1, dj=-1;
  for(int i=0; i<h; i++){
    cin >> s[i];
    for(int j=0; j<w; j++){
      if(s[i][j]=='#'){
        ui=min(ui, i), uj=min(uj, j);
        di=max(di, i), dj=max(dj, j);
      }
    }
  }
  for(int i=ui; i<=di; i++){
    for(int j=uj; j<=dj; j++){
      cout << s[i][j];
      if(j==dj) cout << endl;
    }
  }
  return 0; 
}