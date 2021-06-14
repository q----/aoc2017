#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

vector<int> p(string l){
  for(int i = 0; i < l.size(); i++) if(l[i] == ',') l[i] = ' ';
  stringstream s(l);
  int x;
  vector<int> o;
  while(s>>x) o.push_back(x);
  return o;
}

vector<int> p2(string l){
  vector<int> o;
  for(char c : l) o.push_back(c);
  for(int i : {17, 31, 73, 47, 23}) o.push_back(i);
  return o;
}

int main(){
  ifstream f("input");
  string l;
  getline(f,l);
  vector<int> len = p(l);

  vector<int> x;
  for(int i = 0; i <= 255; i++) x.push_back(i);

  int s = 0;
  int i = 0;

  for(int g : len){
    vector<int> x2;
    for(int j = 0; j < g; j++) x2.push_back(x[(i+j)%x.size()]);
    for(int j = 0; j < g; j++) x[(i+g-j-1)%x.size()] = x2[j];
    i += g + s++;
  }

  cout << x[0] * x[1] << endl;

  for(i = 0; i <= 255; i++) x[i] = i;
  s = 0;
  i = 0;
  len = p2(l);

  for(int j = 0; j < 64; j++){
    for(int c : len){
      vector<int> x2;
      for(int k = 0; k < c; k++) x2.push_back(x[(i+k)%x.size()]);
      for(int k = 0; k < c; k++) x[(i+c-k-1)%x.size()] = x2[k];
      i += c + s++;
    }
  }

  vector<int> hash;
  for(int k = 0; k < 16; k++){
    int z = 0;
    for(int d = 0; d < 16; d++){
      z = z ^ x[k*16+d];
    }
    hash.push_back(z);
  }


  stringstream n;
  n << hex ;
  for(auto q : hash) n << setw(2) << setfill('0') << q;

  cout << n.str() << endl;

  return 0;
}
