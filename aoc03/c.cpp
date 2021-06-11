#include <iostream>

using namespace std;

struct c{
  int x;
  int y;
};

int abs(int a){
  return (a < 0)? -a: a;
}

c operator++(c& a, int){
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
    if( a.x > 0 && a.y < 0) a.x++;
    else if(a.x > 0 && a.y > 0) a.x--;
    else if(a.x < 0 && a.y < 0) a.x++;
    else if(a.x < 0 && a.y > 0) a.y--;
  }
  return a;
}


int main(){
  int goal = 361527;

  int i;
  for(i = 0; ((2*i)-1)*((2*i)-1) <= goal; i--);
  
  int x = -i;
  int y = i;
  i = (2*i)-1;
  i *= i;

  while(x > y && i > goal){
    x--;
    i--;
  }

  while(y < -x && i > goal){
    y++;
    i--;
  }

  while(x < y && i > goal){
    x++;
    i--;
  }

  while(y > -x && i > goal){
    y--;
    i--;
  }
  
  cout << abs(x) + abs(y) << endl;
  return 0;
}
