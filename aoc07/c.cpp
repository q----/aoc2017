#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

struct p{
  string n;
  int w;
  vector<string> x;
};

p parse(string l){
  for(int i = 0; i < l.size(); i++) if(l[i] < '0' | l[i] == '>') l[i] = ' ';
  p o;
  stringstream s(l);
  s >> o.n >> o.w;
  string t;
  while(s>>t) o.x.push_back(t);
  return o;
}

p findbyname(string n, vector<p> x){
  for(int i = 0; i < x.size(); i++) if(x[i].n == n) return x[i];
  p o;
  return o;
}

int weight(string n, vector<p> x){
  p o = findbyname(n,x);
  int w = o.w;
  for(string m : o.x) w += weight(m, x);
  return w;
}

string uneven(string n, vector<p> x){
  p o = findbyname(n,x);
  vector<int> weights;
  for(auto a: o.x) weights.push_back(weight(a,x));
  int m;
  if(count(weights.begin(), weights.end(), weights[0]) == weights.size()) return n;
  for(int i = 0; i < weights.size(); i++) if(count(weights.begin(), weights.end(), weights[i]) == 1){
    m = i;
    break;
  }
  if(uneven(o.x[m], x) == o.x[m]){
    cout << findbyname(o.x[m], x).w + weights[(m+1) % weights.size()] - weights[m] << endl;
  }
  return ":)";
}

int main(){
  ifstream f("input");
  string l;
  vector<p> x;
  while(getline(f,l)) x.push_back(parse(l));

  vector<string> a;
  vector<string> b;

  for(p c : x){
    a.push_back(c.n);
    for(string d : c.x){
      b.push_back(d);
    }
  }

  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  for(int i = 0; i < a.size(); i++){
    if(a[i] != b[i]){
      cout << a[i] << endl;
      uneven(a[i], x);
      break;
    }
  }

  return 0;
}
  
