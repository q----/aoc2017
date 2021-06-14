#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

pair<int,vector<int>> p(string l){
  for(int i = 0; i < l.size(); i++) if(l[i] == ',') l[i] = ' ';
  stringstream s(l);
  int x,y;
  string t;
  vector<int> o;
  s >> x >> t;
  while(s>>y)o.push_back(y);
  return pair<int,vector<int>>(x,o);
}

int main(){
  ifstream f("input");
  string l;
  map<int,vector<int>> q;
  while(getline(f,l))q.insert(p(l));

  queue<int> x;
  x.push(0);
  set<int> g;

  while(x.size() > 0){
    int t = x.front();
    x.pop();
    if(!g.insert(t).second) continue;
    for(int c : q[t]) x.push(c);
  }

  cout << g.size() << endl;

  int num = 1;
  int i = 1;
  while(g.size() < q.size()){
    if(!g.insert(i++).second) continue;
    num++;
    for(int c : q[i-1]) x.push(c);
    while(x.size() > 0){
      int t = x.front();
      x.pop();
      if(!g.insert(t).second) continue;
      for(int c : q[t]) x.push(c);
    }
  }

  cout << num << endl;  

  return 0;
}
