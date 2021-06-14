#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
//#include <algorithm>

using namespace std;

void pre(string x, map<string,int>& p){
  if(!p.count(x)) p[x] = 0;
}

bool comp(string r, string c, int x, map<string,int>& p){
  if(c == "==") return p[r] == x;
  if(c ==  ">") return p[r] > x;
  if(c ==  "<") return p[r] < x;
  if(c == "!=") return p[r] != x;
  if(c == ">=") return p[r] >= x;
  if(c == "<=") return p[r] <= x;
  cout << "uh oh " << c << endl;
  return false;
}

void parse(string l, map<string,int>& p){
  stringstream s(l);
  string g,t,z,c,o;
  int x,y;
  s >> g >> t >> x >> z >> c >> o >> y;
  pre(g,p);
  pre(c,p);
  if(comp(c,o,y,p)) p[g] += (t == "inc")?x:-x;
}

int max(map<string,int>& p){
  int m = 0;
  for(auto a : p) m = (m > a.second)?m:a.second;
  return m;
}

int main(){
  ifstream f("input");
  string l;
  map<string,int> p;
  int x = 0;

  while(getline(f,l)){
    parse(l,p);
    int t = max(p);
    x = (x > t)?x:t;
  }

  cout << max(p) << endl;
  cout << x << endl;

  return 0;
}
