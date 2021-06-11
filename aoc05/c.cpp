#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main(){
  ifstream f("input");
  string l;
  vector<int> jumps;

  while(getline(f,l)){
    stringstream s(l);
    int x;
    s >> x;
    jumps.push_back(x);
  }

  vector<int> jumps2 = jumps;

  int x = 0;
  int count = 0;

  while( x >= 0 && x < jumps.size()){
    x += jumps[x]++;
    count++;
  }

  cout << count << endl;
  count = 0;
  x = 0;

  while( x >= 0 && x < jumps2.size()){
    int y = x;
    x += jumps2[x];
    if(jumps2[y] >= 3)jumps2[y]--;
    else jumps2[y]++;
    count++;
  }

  cout << count << endl;

  return 0;
}
