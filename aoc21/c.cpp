#include <iostream>
#include <fstream>
#include <set>
#include <map>

using namespace std;

const bool operator<(const pair<int,int>& a, const pair<int,int>& b){
  if(a.first == b.first) return a.second < b.second;
  return a.first < b.first;
}

void move(int& x, int& y, const int& d){
  if(d % 2){
    x += (d < 2)?1:-1;
  } else {
    y += (d > 1)?1:-1;
  }
}

bool step(int& x, int& y, int& d, set<pair<int,int>>& f){
  bool g = f.count(pair<int,int>(x,y));
  d = (d+((g)?1:-1)+4)%4;
  if(!g){
    f.insert(pair<int,int>(x,y));
  } else {
    f.erase(pair<int,int>(x,y));
  }
  move(x,y,d);
  return !g;
}

bool step2(int& x, int& y, int& d, map<pair<int,int>,int>& q){
  pair<int,int> s(x,y);
  q[s] = (q[s] + 1) % 4;
  d = (d + q[s] + 2) % 4;
  move(x,y,d);
  return (q[s] == 2);
}

set<pair<int,int>> p(string l, int y){
  set<pair<int,int>> o;
  for(int i = 0; i < l.size(); i++) if(l[i] == '#') o.insert(pair<int,int>(i,y));
  return o;
}

int main(){
  ifstream f("input");
  string l;
  set<pair<int,int>> m;
  int y = 0;
  int x;
  while(getline(f,l)){
    set<pair<int,int>> t = p(l, y++);
    m.insert(t.begin(),t.end());
    x = l.size()/2;
  }

  map<pair<int,int>,int> q;

  for(auto a: m) q[a] = 2;

  y /= 2;
  int x2 = x;
  int y2 = y;
  int d = 0;

  int o = 0;

  for(int i = 0; i < 10000; i++){
    if(step(x,y,d,m)) o++;
  }

  cout << o << endl;

  int o2 = 0;
  d = 0;

  for(int i = 0; i < 10000000; i++){
    if(step2(x2,y2,d,q)) o2++;
  }

  cout << o2 << endl;

  return 0;
}
