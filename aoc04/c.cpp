#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

bool val(string l){
  stringstream s(l);
  set<string> x;
  string m;
  while(s>>m) if(!x.insert(m).second) return false;
  return true;
}

bool val2(string l){
  stringstream s(l);
  set<string> x;
  string m;
  while(s>>m){
    sort(m.begin(), m.end());
    if(!x.insert(m).second) return false;
  }
  return true;
}

int main(){
  ifstream f("input");
  string l;
  int o = 0;
  int o2 = 0;
  while(getline(f,l)){
    if(val(l)) o++;
    if(val2(l)) o2++;
  }

  cout << o << endl;
  cout << o2 << endl;

  return 0;
}
