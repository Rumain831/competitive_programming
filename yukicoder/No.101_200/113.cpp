#include<iostream>
#include<math.h>
using namespace std;

//Tags: Simulation
//Level: 1

int main(void){
  string s; cin >> s;
  int x=0, y=0;
  string d="NESW";
  int dy[4]={1, 0, -1, 0};
  int dx[4]={0, 1, 0, -1};
  for(int i=0; i<s.size(); i++){
    int dir;
    for(int k=0; k<4; k++)if(s[i]==d[k]) dir=k;
    x+=dx[dir], y+=dy[dir];
  }
  printf("%.10f\n", (double)sqrt(x*x+y*y));
  return 0; 
}