#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct p{
  vector<long long int> c = {0,0,0};
  vector<int> p;
  vector<int> v;
  vector<int> a;
  int id;
};

int abs(int a){
  return (a > 0)?a:-a;
}

int d(const p& a){
  return abs(a.c[0]) + abs(a.c[1]) + abs(a.c[2]);
}

int q(const p& a){
  return abs(a.a[0]) + abs(a.a[1]) + abs(a.a[2]);
}

const bool operator<(const p& a, const p& b){
  return d(a) < d(b);
}

const bool operator==(const p& a, const p& b){
  for(int i = 0; i < 3; i++) if(a.c[i] != b.c[i]) return false;
  return true;
}

p parse(string l, int i){
  for(int x = 0; x < l.size(); x++) if(l[x] < '-' || l[x] > '9') l[x] = ' ';
  stringstream s(l);
  p o;
  o.id = i;
  int x, y, z;
  s >> x >> y >> z;
  o.p = {x,y,z};
  s >> x >> y >> z;
  o.v = {x,y,z};
  s >> x >> y >> z;
  o.a = {x,y,z};
  return o;
}

p dist(p a, int t){
  for(int i = 0; i < 3; i++){
    a.c[i] = a.p[i] + a.v[i] * t + a.a[i] * t * (t + 1)/2;
  }
  return a;
}

vector<p> rem(vector<p> a, int t){
  for(int i = 0; i < a.size(); i++) a[i] = dist(a[i],t);
  set<int> r;
  for(int i = 0; i < a.size() - 1; i++){
    for(int j = i + 1; j < a.size(); j++){
      if(a[i] == a[j]){
        r.insert(i);
        r.insert(j);
      }
    }
  }
  vector<p> o;
  for(int i = 0; i < a.size(); i++){
    if(!r.count(i)) o.push_back(a[i]);
  }
  return o;
}

int main(){
  ifstream f("input");
  string l;
  vector<p> aa;
  while(getline(f,l)) aa.push_back(parse(l,aa.size()));

  int x = 0;
  int aaa = q(aa[0]);

  for(int i = 1; i < aa.size(); i++){
    if(q(aa[i]) < aaa){
      x = aa[i].id;
      aaa = q(aa[i]);
    }
  }

  cout << x << endl;

  for(int i = 0; i < 300; i++){
    aa = rem(aa, i);
  }

  cout << aa.size() << endl;
  
  return 0;
}
