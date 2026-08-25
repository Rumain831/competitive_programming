#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: 順列全探索
//Level: 2

int main(void){
  int n; cin >> n;
  vector<int> a(n), b(n);
  for(auto&x:a) cin >> x;
  for(auto&x:b) cin >> x;
  int c=0, all=0;
  vector<int> pa(n);
  for(int i=0; i<n; i++) pa[i]=i;
  do{
    vector<int> pb(n);
    for(int i=0; i<n; i++) pb[i]=i;
    do{
      all++;
      int wa=0, wb=0;
      for(int i=0; i<n; i++){
        if(a[pa[i]]>b[pb[i]]) wa++;
        else wb++;
      }
      if(wa>wb) c++;
    }while(next_permutation(begin(pb), end(pb)));
  }while(next_permutation(begin(pa), end(pa)));
  printf("%.10f\n", (double)c/all);
  return 0; 
}