#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

string move(string m, string l){
  if(m[0] == 's'){
    stringstream s(m.substr(1));
    int x;
    s >> x;
    string o;
    for(int i = 0; i < l.size(); i++) o += l[(i+l.size() - x)%l.size()];
    return o; 
  } else if(m[0] == 'p'){
    int x = l.find(m[1]);
    l[l.find(m[3])] = m[1];
    l[x] = m[3];
    return l;
  } else if(m[0] == 'x') {
    string t = m.substr(1);
    for(int i = 0; i < t.size(); i++) if(t[i] == '/') t[i] = ' ';
    stringstream s(t);
    int x,y;
    s >> x >> y;
    char f = l[x];
    l[x] = l[y];
    l[y] = f;
    return l;
  }
  cout << "yikes" << endl;
  return "uh oh";
}

string step(string x, string& l){
  stringstream s(l);
  string t;
  while(s >> t) x = move(t,x);
  return x;
}

int main(){
  string a = "abcdefghijklmnop";
  string b = a;
  ifstream f("input");
  string l;
  getline(f,l);
  for(int i = 0; i < l.size(); i++) if(l[i] == ',') l[i] = ' ';
  stringstream s(l);
  string x;
  while(s>>x) a = move(x, a);

  cout << a << endl;

  vector<string> g;
  g.push_back(b);
  g.push_back(a);

  while(g.front() != g.back()) g.push_back(step(g.back(),l));
  g.pop_back();
  
  cout << g[1000000000 % g.size()] << endl;

  return 0;
}
