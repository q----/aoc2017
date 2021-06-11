#include <iostream>

using namespace std;

struct c{
  int x = 0;
  int y = 0;
  int c = 1;
};

int abs(int a){
  return (a < 0)? -a: a;
}

const int operator!(c& a){
  return abs(a.x) + abs(a.y);
}

c operator++(c& a, int){
  a.c++;
  if(abs(a.x) > abs(a.y)){
    if(a.x < 0){
      a.y--;
    } else {
      a.y++;
    }
  } else if(abs(a.x) < abs(a.y)){
    if(a.y < 0){
      a.x++;
    } else {
      a.x--;
    }
  } else {
    if( a.x >= 0 && a.y <= 0) a.x++;
    else if(a.x > 0 && a.y > 0) a.x--;
    else if(a.x < 0 && a.y < 0) a.x++;
    else if(a.x < 0 && a.y > 0) a.y--;
  }
  return a;
}


int main(){
  int goal = 361527;

  c a;

  for(a; a.c < goal; a++);
  
  cout << !a << endl;
  return 0;
}
