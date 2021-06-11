#include <iostream>
#include <fstream>

using namespace std;

int main(){
  ifstream f("input");
  string l;

  getline(f,l);

  int o = 0;
  for(int i = 0; i < l.size(); i++) if(l[i] == l[(i+1)%l.size()]) o += l[i] - '0';
  int o2 = 0;
  for(int i = 0; i < l.size(); i++) if(l[i] == l[(i+l.size()/2)%l.size()]) o2 += l[i] - '0';

  cout << o << endl;
  cout << o2 << endl;

  return 0;
}
