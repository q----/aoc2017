#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

struct c{
  int p = 0;
  int s = 0;
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

bool sorted(vector<int>& b){
  for(int i = 0; i < b.size() - 1; i++) if(b[i] < b[i+1]) return false;
  return true;
}

int main(){
  ifstream f("input");
  string l;
  vector<string> i;
  while(getline(f,l)) i.push_back(l);

  c q;
  int x = 0;
  while(step(q, i, x));
  cout << x << endl;

  vector<int> b;
  long long int a = 1;
  for(int i = 0; i < 31; i++) a *= 2;
  a--;
  long long int p = 622;
  for(int i = 0; i < 127; i++){
    p = (p * 8505 * 129749 + 12345) % a;
    b.push_back(p % 10000);
  }

  int o = 2;
  while(!sorted(b)){
    o++;
    for(int i = 0; i < b.size() - 1; i++){
      if(b[i] < b[i+1]){
        int t = b[i];
        b[i] = b[i+1];
        b[i+1] = t;
      }
    }
  }

  cout << (o/2) * 127 << endl;

  return 0;
}

