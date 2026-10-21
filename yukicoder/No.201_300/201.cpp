#include<iostream>
using namespace std;

//Tags: 巨大数の扱い, 実装
//Level: 1

int main(void){
  string sa, pa, xa, sb, pb, xb;
  cin >> sa >> pa >> xa >> sb >> pb >> xb;
  if(pa==pb){
    cout << -1 << endl; return 0;
  }
  int na=pa.size(), nb=pb.size();
  if(na!=nb){
    cout << (na>nb?sa:sb) << endl; return 0;
  }
  for(int i=0; i<na; i++){
    if(pa[i]!=pb[i]){
      cout << (pa[i]>pb[i]?sa:sb) << endl; return 0;
    } 
  }
  return 0; 
}