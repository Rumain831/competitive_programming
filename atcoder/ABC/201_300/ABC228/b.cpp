#include <iostream>
#include <vector>
using namespace std;

//Tags: Simulation

int main() {
  int n, x; cin >> n >> x; x--;
  vector<int> a(n), know(n);
  for(int i=0; i<n; i++) cin >> a[i], a[i]--;
  int now=x, ans=0;
  while(know[now]==0){
    know[now]++, ans++;
    now=a[now];
  }
  cout << ans << endl;
  return 0;
}