#include <iostream>
#include <map>

using namespace std;

struct c{
  int x = 0;
  int y = 0;
  int d = 1;
  c(){}
  c(int a, int b){
    x = a;
    y = b;
  }
};

int abs(int a){
  return (a < 0)? -a: a;
}

const int operator!(c& a){
  return abs(a.x) + abs(a.y);
}

const c operator+(const c& a, const c& b){
  c o;
  o.x = a.x + b.x;
  o.y = a.y + b.y;
  return o;
}

c operator++(c& a, int){
  a.d++;
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

const bool operator<(const c& a, const c& b){
  if(a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}

int sum(c& b, map<c,int> o){
  int out = 0;
  for(c x: {c(0,-1), c(0,0), c(0,1)}){
    for(c y: {c(-1,0), c(0,0), c(1,0)}){
      out += o[b+x+y];
    }
  }
  return out;
}

int main(){
  int goal = 361527;

  c a;

  for(a; a.d < goal; a++);
  
  cout << !a << endl;

  map<c,int> o;

  c b;
  o[b] = 1;
  b++;
  int x = 0;
  while(x < goal){
    x = sum(b,o);
    o[b] = x;
    b++;
  }

  cout << x << endl;

  return 0;
}
