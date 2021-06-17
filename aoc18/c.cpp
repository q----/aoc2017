#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

struct c{
  int p = 0;
  map<char,long long int> r;
};

int pre(map<char,long long int>& p, char x){
  if(!p.count(x)) p[x] = 0;
  return p[x];
}

int conv(string x, c& o){
  if(x[0] < 'a'){
    stringstream s(x);
    int n;
    s >> n;
    return n;
  }
  return pre(o.r, x[0]);
}

bool step(c& o, vector<string>& i, int& x){
  stringstream s(i[o.p]);
  string t, g;
  char m;
  s >> t >> m >> g;
  pre(o.r, m);
  if(t == "set"){
    o.r[m] = conv(g,o);
  } else if (t == "snd") {
    x = o.r[m];
  } else if (t == "rcv") {
    if(o.r[m] != 0){
      return false;
    }
  } else if (t == "add"){
    o.r[m] += conv(g, o);
  } else if (t == "mul"){
    o.r[m] *= conv(g, o);
  } else if (t == "mod"){
    o.r[m] %= conv(g, o);
  } else if (t == "jgz"){
    if(o.r[m] > 0){
      o.p += conv(g, o) - 1;
    }
  }
  o.p++;
  return true;
}

int main(){
  ifstream f("input");
  string l;
  vector<string> i;
  while(getline(f,l)) i.push_back(l);

  c o;
  int x = 0;

  while(step(o, i, x));
  cout << x << endl;

  return 0;
}

