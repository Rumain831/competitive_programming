#include<iostream>
using namespace std;

string dir(int deg){
  if(deg>=113&&deg<=337) return "NNE";
  else if(deg>=338&&deg<=562) return "NE"; 
  else if(deg>=563&&deg<=787) return "ENE"; 
  else if(deg>=788&&deg<=1012) return "E"; 
  else if(deg>=1013&&deg<=1237) return "ESE"; 
  else if(deg>=1238&&deg<=1462) return "SE"; 
  else if(deg>=1463&&deg<=1687) return "SSE"; 
  else if(deg>=1688&&deg<=1912) return "S"; 
  else if(deg>=1913&&deg<=2137) return "SSW"; 
  else if(deg>=2138&&deg<=2362) return "SW"; 
  else if(deg>=2363&&deg<=2587) return "WSW"; 
  else if(deg>=2588&&deg<=2812) return "W"; 
  else if(deg>=2813&&deg<=3037) return "WNW"; 
  else if(deg>=3038&&deg<=3262) return "NW"; 
  else if(deg>=3263&&deg<=3487) return "NNW";
  else return "N"; 
}

int pow(int dis){
  if(dis<=14) return 0;
  else if(dis<=92) return 1;
  else if(dis<=200) return 2;
  else if(dis<=326) return 3;
  else if(dis<=476) return 4;
  else if(dis<=644) return 5;
  else if(dis<=830) return 6;
  else if(dis<=1028) return 7;
  else if(dis<=1244) return 8;
  else if(dis<=1466) return 9;
  else if(dis<=1706) return 10;
  else if(dis<=1958) return 11;
  else return 12;
}

int main(void){
  int deg, dis; cin >> deg >> dis;
  dis=pow(dis);
  if(dis==0){
    cout << 'C' << ' ' << dis << endl;
    return 0;
  }
  cout << dir(deg) << ' ' << dis << endl;
  return 0;
}
