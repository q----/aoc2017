#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

stringstream p(string l){
  for(int i = 0; i < l.size(); i++) if(l[i] == ',') l[i] = ' ';
  return stringstream(l);
}

int abs(int x){
  return (x < 0)?-x:x;
}

int d(int x, int y){
  if((x<0)^(y<0)) return abs(x - y);
  x = abs(x);
  y = abs(y);
  return (x > y)?x:y;
}

int main(){
  ifstream f("input");
  string l;
  getline(f,l);
  stringstream s = p(l);

  int x = 0;
  int y = 0;
  int a = 0;

  while(s>>l){
    if(l == "n") y++;
    if(l == "s") y--;
    if(l == "nw") x--;
    if(l == "se") x++; 
    if(l == "ne"){
      x++;
      y++;
    }
    if(l == "sw"){
      x--;
      y--;
    }
    a = (a > d(x,y))?a:d(x,y);
  }
  
  cout << d(x,y) << endl;
  cout << a << endl;

  return 0;
}
