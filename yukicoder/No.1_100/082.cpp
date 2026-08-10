#include<iostream>
using namespace std;

//Tags: grid

int main(void){
  int w, h; char c[2]; cin >> w >> h >> c[0];
  c[1]='W'+'B'-c[0];
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      cout << c[(i+j)%2];
    }
    cout << endl;
  }
  return 0; 
}