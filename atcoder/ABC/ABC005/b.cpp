#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
  int n; cin >> n;
  vector<int> t(n);
  for(int i=0; i<n; i++) cin >> t[i];
  cout << *min_element(begin(t), end(t)) << endl;
  return 0;
}