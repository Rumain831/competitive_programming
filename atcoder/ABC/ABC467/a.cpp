#include<iostream>
using namespace std;

int main(void){
  int h, w; cin >> h >> w;
  cout << (w*10000>=h*h*25?"Yes":"No") << endl;
  return 0; 
}