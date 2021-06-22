#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct c{
  int x;
  int y;
  c(){}
  c(int a, int b){
    x = a;
    y = b;
  }
};

const c operator+(const c& a, const c& b){
  return c(a.x+b.x, a.y+b.y);
}

const c operator-(const c& a, const c& b){
  return c(a.x-b.x, a.y-b.y);
}

const c operator-(const c& a){
  return c(-a.x, -a.y);
}

const c operator~(const c& a){
  return c(a.y, a.x);
}

const bool operator&(const c& a, const c& b){
  return (a.x == b.x) || (a.y == b.y);
}

const bool operator==(const c& a, const c& b){
  return (a.x == b.x) && (a.y == b.y);
}

char q(c a, vector<string>& p){
  return p[a.y][a.x];
}

c n(c a, c b, string& x, vector<string>& p){
  char t = q(a,p);
  c o = a - b;
  c s;
  char m;
  if(t == '+') o = ~o;
  for(c g : {-o, o}){
    if(a + g == b) continue;
    s = a + g;
    m = q(s,p);
    if(m != ' ') break;
  }
  if(m == ' ') return c(-1,-1);
  if(m >= 'A' && m  <= 'Z') x += m;
  return s;
}

int main(){
  ifstream f("input");
  string l;
  vector<string> p;
  while(getline(f,l)) p.push_back(l);
  string s = "";
  c a(p[0].find('|'), 0);
  c b = a + c(0,1);
  int o = 1;
  while(b.x >= 0){
    c t = a;
    a = b;
    b = n(a,t,s,p);
    o++;
  }

  cout << s << endl;
  cout << o << endl;

  return 0;
}

