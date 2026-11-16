#include<iostream>
#include<vector>
using namespace std;

//Tags: 条件を満たすものの個数

int main(void){
  int n; cin >> n;
  vector<int> a(n);
  for(auto&x:a) cin >> x;
  int up=0, down=0, same=0;
  for(int i=1; i<n; i++){
    if(a[i]==a[i-1]) same++;
    else if(a[i]>a[i-1]) up++;
    else down++;
  }
  printf("%d %d %d\n", up, down, same);
  return 0; 
}