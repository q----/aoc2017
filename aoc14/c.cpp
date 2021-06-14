#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <iomanip>

using namespace std;

const bool operator<(const pair<int,int>& a, const pair<int,int>& b){
  if(a.first == b.first) return a.second < b.second;
  return a.first < b.first;
}

vector<int> p(string l){
  vector<int> o;
  for(char c : l) o.push_back(c);
  for(int i : {17, 31, 73, 47, 23}) o.push_back(i);
  return o;
}

string conv(char c){
  if(c >= 'a') c -= 'a'-10;
  else c -= '0';
  bitset<4> o(c);
  return o.to_string();
}

string h(string l){
  vector<int> len = p(l);
  vector<int> x;
  for(int i = 0; i <= 255; i++) x.push_back(i);
  int s = 0;
  int i = 0;

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

  string o = "";
  for(auto q : n.str()) o += conv(q);
  return o;
}

queue<pair<int,int>> contig(int x, int y){
  queue<pair<int,int>> o;
  if(x > 0) o.push(pair<int,int>(x-1,y));
  if(y > 0) o.push(pair<int,int>(x,y-1));
  if(x < 127) o.push(pair<int,int>(x+1,y));
  if(y < 127) o.push(pair<int,int>(x,y+1));
  return o;
}

int main(){
  string input = "stpzcrnm";
  input += "-";

  vector<string> map;
  for(int i = 0; i < 128; i++) map.push_back(h(input + to_string(i)));

  int g = 0;
  set<pair<int,int>> aa;

  for(int i = 0; i < map.size(); i++){
    for(int j = 0; j < map[i].size(); j++){
      if(map[i][j] == '1' && aa.insert(pair<int,int>(i,j)).second){
        g++;
        queue<pair<int,int>> c = contig(i,j);
        while(c.size() > 0){
          pair<int,int> t = c.front();
          c.pop();
          if(map[t.first][t.second] == '1' && aa.insert(t).second){
            queue<pair<int,int>> t1 = contig(t.first,t.second);
            while(t1.size() > 0){
              c.push(t1.front());
              t1.pop();
            }
          }
        }
      }
    }
  }

  cout << aa.size() << endl;
  cout << g << endl;

  return 0;
}

