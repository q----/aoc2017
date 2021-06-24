#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <queue>

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

bool step2(c& a, c& b, vector<string>& i, int& x, queue<long long int>& ax, queue<long long int>& bx){
  stringstream s(i[a.p]);
  string t;
  char m;
  s >> t >> m;
  if(t == "snd"){
    ax.push(pre(a.r,m));
    a.s++;
  } else if(t == "rcv"){
    if(!bx.size()) return false;
    a.r[m] = bx.front();
    bx.pop();
  } else {
    return step(a,i,x);
  }
  a.p++;
  return true;
}

bool term(c& a, vector<string>& i){
  return a.p < 0 || a.p >= i.size();
}

bool test(c& a, c& b, vector<string>& i, queue<long long int>& ax, queue<long long int>& bx){
  return term(a,i) || term(b,i) || (i[a.p][0] == 'r' && bx.size() == 0 && i[b.p][0] == 'r' && ax.size() == 0);
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

//  c o;
  int x = 0;
 // while(step(o, i, x));
  cout << x << endl;

//  c a;
//  c b;
//  b.r['p'] = 1;
//  queue<long long int> ax;
//  queue<long long int> bx;
//
//  while(!test(a,b,i,ax,bx)){
//    step2(a,b,i,x,ax,bx);
//    step2(b,a,i,x,bx,ax);
//  }
//
//  if(!term(b,i)) while(step2(b,a,i,x,bx,ax));
//
//  cout << b.s << endl;
//
//

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

