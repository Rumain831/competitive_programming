#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: ソート

int main(void){
  int n, k; cin >> n >> k;
  vector<int> a(n), b(n);
  for(auto&x:a) cin >> x;
  b=a;
  sort(begin(b), end(b));
  int l=-1, r=-1;
  for(int i=0; i<n; i++)if(a[i]!=b[i]){l=i; break;}
  for(int i=n-1; i>=0; i--)if(a[i]!=b[i]){r=i; break;}
  if(l==-1||r-l+1<=k) cout << "Yes" << endl;
  else cout << "No" << endl;  
  return 0; 
}