#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <math.h>

using namespace std;

struct c{
  int p = 0;
  map<char,int> r;
  c(){
    for(char i = 'a'; i <= 'h'; i++) r[i] = 0;
    r['1'] = 1;
  }
};

int ah(string z, c& a){
  stringstream s(z);
  int x;
  return (s>>x)?x:a.r[z[0]];
}

bool step(c& a, string l){
  stringstream s(l);
  string x,y,z;
  a.p++;
  s >> x >> y >> z;
  if(x == "set"){
    a.r[y[0]] = ah(z, a);
  } else if(x == "mul"){
    a.r[y[0]] *= ah(z, a);
    return true;
  } else if(x == "sub"){
    a.r[y[0]] -= ah(z, a);
  } else if(x == "jnz"){
    if(a.r[y[0]]) a.p += ah(z,a) - 1;
  }
  return false;
}

bool prime(int x){
  for(int i = 2; i <= sqrt(x); i++) if(x % i == 0) return false;
  return true;
}

int main(){
  ifstream f("input");
  string l;
  vector<string> i;

  while(getline(f,l)) i.push_back(l);

  c a;
  int o = 0;
  while(a.p >= 0 && a.p < i.size()) if(step(a, i[a.p])) o++;

  cout << o << endl;

  int h = 0;

  for(int b = 106500; b <= 123500; b += 17) if(!prime(b)) h++;

  cout << h << endl;

  return 0;
}
