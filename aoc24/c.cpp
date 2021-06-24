#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <vector>

using namespace std;

vector<int> p(string l){
  for(int i = 0; i < l.size(); i++) if(l[i] == '/') l[i] = ' ';
  stringstream s(l);
  int x;
  int y;
  s >> x >> y;
  return {x,y};
}

int next(int g, int a, queue<vector<int>> x, pair<int,int>& q){
  int max = 0;
  if(x.size() < q.first || (x.size() == q.first && a > q.second)) q = pair<int,int>(x.size(),a);
  for(int i = 0; i < x.size(); i++){
    vector<int> t = x.front();
    x.pop();
    if(t[0] == g){
      int f = next(t[1], t[0] + t[1] + a, x, q);
      max = (max < f)?f:max;
    } else if(t[1] == g){
      int f = next(t[0], t[0] + t[1] + a, x, q);
      max = (max < f)?f:max;
    }
    x.push(t);
  }
  return (a > max)?a:max;
}

int main(){
  ifstream f("input");
  string l;
  queue<vector<int>> x;

  while(getline(f,l)) x.push(p(l));

  pair<int,int> q(x.size(),0);

  cout << next(0,0,x,q) << endl;
  cout << q.second << endl;

  return 0;
}

      

