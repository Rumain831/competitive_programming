#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Tags: 順列全探索

int main(void){
  string s; int k; cin >> s >> k;
  sort(s.begin(), s.end());
  vector<string> dict;
  do{
    dict.push_back(s);
  }while(next_permutation(s.begin(), s.end()));
  //dict.erase(unique(dict.begin(), dict.end()), dict.end());
  cout << dict[k-1] << endl;
  return 0;
}