#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int p(string l){
  stringstream s(l);
  int max;
  int min;
  s >> max;
  min = max;
  int x;
  while(s >> x){
    if(x > max) max = x;
    if(x < min) min = x;
  }
  return max - min;
}

int p2(string l){
  stringstream s(l);
  int x;
  vector<int> m;
  while(s >> x) m.push_back(x);
  for(int i = 0; i < m.size(); i++){
    for(int j = 0; j < m.size(); j++){
      if(i==j)continue;
      if(m[i] % m[j] == 0){
        return m[i]/m[j];
      }
    }
  }
  return 0;
}

int main(){
  ifstream f("input");
  string l;

  int o = 0;
  int q = 0;

  while(getline(f,l)){
    o += p(l);
    q += p2(l);
  }

  cout << o << endl;
  cout << q << endl;

  return 0;
}
