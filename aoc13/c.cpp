#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int p(string l, int w){
  for(int i = 0; i < l.size(); i++) if(l[i] == ':') l[i] = ' ';
  int x,y;
  stringstream s(l);
  s >> x >> y;
  

  return ((w+x) % (2*y-2))?0:(w>0)?1:x*y;
}

int go(int w = 0){
  ifstream f("input");
  string l;
  int o = 0;
  while(getline(f,l)){
    o += p(l,w);
    if(o && w > 0) return 1;
  }
  return o;
}


int main(){
  cout << go() << endl;
  int w = 0;
  while(go(++w));
  cout << w << endl;
  return 0;
}
