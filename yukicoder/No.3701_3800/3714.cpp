#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

//Tags: 全探索
//Level: 1.5

int main(void){
  string x[3]; cin >> x[0] >> x[1] >> x[2];
  set<string> all;
  int p[3]={0, 1, 2};
  int l[3]={(int)x[0].size(), (int)x[1].size(), (int)x[2].size()};
  do{
    for(int i=1; i<=l[p[0]]; i++)for(int j=1; j<=l[p[1]]; j++)for(int k=1; k<=l[p[2]]; k++){
      string now=x[p[0]].substr(0, i)+x[p[1]].substr(0, j)+x[p[2]].substr(0, k);
      all.insert(now);
    }
  }while(next_permutation(p, p+3));
  cout << all.size() << endl;
  return 0; 
}