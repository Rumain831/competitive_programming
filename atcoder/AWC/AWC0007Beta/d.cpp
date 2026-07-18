#include<iostream>
#include<vector>
using namespace std;

int main(void){
  int n, a, b; cin >> n >> a >> b;
  vector t(n+1, vector<int>(n+1));
  vector ao(n+1, vector<int>(n+1));
  for(int i=0; i<a; i++){
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--, c1--;
    t[r1][c1]++, t[r1][c2]--;
    t[r2][c1]--, t[r2][c2]++;
  }
  for(int i=0; i<b; i++){
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--, c1--;
    ao[r1][c1]++, ao[r1][c2]--;
    ao[r2][c1]--, ao[r2][c2]++;
  }
  for(int i=0; i<n+1; i++)for(int j=1; j<=n; j++) t[i][j]+=t[i][j-1];
  for(int i=0; i<n+1; i++)for(int j=1; j<=n; j++) ao[i][j]+=ao[i][j-1];
  for(int j=0; j<n+1; j++)for(int i=1; i<=n; i++) t[i][j]+=t[i-1][j];
  for(int j=0; j<n+1; j++)for(int i=1; i<=n; i++) ao[i][j]+=ao[i-1][j];
  int ans=0;
  for(int i=0; i<n; i++)for(int j=0; j<n; j++)if(t[i][j]&&ao[i][j]) ans++;
  cout << ans << endl;
  return 0;
}