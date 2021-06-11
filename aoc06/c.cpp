#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

const bool operator<(const vector<int>& a, const vector<int>& b){
  for(int i = 0; i < a.size(); i++) if(a[i] != b[i]) return a[i] < b[i];
  return false;
}

vector<int> p(string l){
  stringstream s(l);
  int x;
  vector<int> o;
  while(s>>x)o.push_back(x);
  return o;
}

vector<int> step(vector<int> in){
  int max = 0;
  int j = 0;
  for(int i = 0; i < in.size(); i++){
    if(in[i] > max){
      max = in[i];
      j = i;
    }
  }
  in[j++] = 0;
  for(max; max > 0; max--)in[(j++) % in.size()]++;
  return in;
}

int main(){
  ifstream f("input");
  string l;
  getline(f,l);
  vector<int> o = p(l);

  set<vector<int>> x;
  x.insert(o);
  int count = 0;

  do{
    o = step(o);
    count++;
  }while(x.insert(o).second);

  cout << count << endl;

  count = 0;
  x.clear();
  x.insert(o);

  do{
    o = step(o);
    count++;
  }while(x.insert(o).second);

  cout << count << endl;

  return 0;
}
