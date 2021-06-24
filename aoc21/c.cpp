#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <stdexcept>

using namespace std;

pair<string,string> p(string l){
  stringstream s(l);
  string x,y,z;
  s >> x >> y >> z;
  return pair<string,string>(x,z);
}

string vts(vector<string> a){
  string o = "";
  for(auto b : a) o += "/" + b;
  return o.substr(1);
}

vector<string> stv(string a){
  vector<string> o;
  for(int i = 0; i < a.size(); i++) if(a[i] == '/') a[i] = ' ';
  stringstream s(a);
  string t;
  while(s>>t) o.push_back(t);
  return o;
}

vector<string> flip(vector<string> a){
  vector<string> o;
  for(int i = a.size()-1; i >= 0; i--){
    o.push_back(a[i]);
  }
  return o;
}

vector<string> rotate(vector<string> a){
  vector<string> o;
  for(int i = 0; i < a[0].size(); i++){
    string t = "";
    for(int j = a.size()-1; j >= 0; j--){
      t += a[j][i];
    }
    o.push_back(t);
  }
  return o;
}

vector<string> enhance(vector<string> a, map<string,string> q){
  vector<string> x;

  x.push_back(vts(a));
  x.push_back(vts(flip(a)));
  for(int i = 0; i < 6; i++) x.push_back(vts(rotate(stv(x[x.size()-2]))));
  for(auto g : x){
    if(q.count(g)){
      return stv(q[g]);
    }
  }
  throw runtime_error("no match found for " + x[0]);
}

vector<string> step(vector<string> a, map<string,string> q){
  vector<vector<vector<string>>> t;

  int f = (a.size() % 2)?3:2;
  for(int i = 0; i < a.size() / f; i++){
    vector<vector<string>> tem;
    for(int j = 0; j < a.size() / f; j++){
      vector<string> temp;
      for(int k = 0; k < f; k++){
        temp.push_back(a[i * f + k].substr(j*f, f));
      }
      tem.push_back(temp);
    }
    t.push_back(tem);
  }

  for(int i = 0; i < t.size(); i++){
    for(int j = 0; j < t[0].size(); j++){
      t[i][j] = enhance(t[i][j], q);
    }
  }

  vector<string> b;
  for(int i = 0; i < t.size(); i++){
    for(int k = 0; k < t[i][0].size(); k++){
      string g;
      for(int j = 0; j < t[i].size(); j++){
        g += t[i][j][k];
      }
      b.push_back(g);
    }
  }
  return b;
}

int count(vector<string> a){
  int o = 0;
  for(int i = 0; i < a.size(); i++) for(int j = 0; j < a[i].size(); j++) if(a[i][j] == '#') o++;
  return o;
}

int main(){
  ifstream f("input");
  string l;
  map<string,string> q;
  while(getline(f,l)) q.insert(p(l));

  vector<string> a = stv(".#./..#/###");
  for(int i = 0; i < 5; i++) a = step(a,q);

  cout << count(a) << endl;

  for(int i = 5; i < 18; i++) a = step(a,q);

  cout << count(a) << endl;

  return 0;
}
