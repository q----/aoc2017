#include <iostream>
#include <fstream>

using namespace std;

int t(string& l, int& i, int x, int& g){
  int m = 0;
  for(i; i < l.size(); i++){
    if(l[i] == '!'){
      i++;
      continue;
    }
    if(l[i] == '<'){
      while(l[++i] != '>'){
        if(l[i] == '!') i++;
        else g++;
      }
      continue;
    }
    if(l[i] == '{'){
      m += t(l, ++i, x+1,g);
      continue;
    }
    if(l[i] == '}'){
      return m + x;
    }
  }
  return m + x;
}

int main(){
  ifstream f("input");
  string l;
  getline(f,l);
  int i;
  int g;
  cout << t(l,i,0,g) << endl;
  cout << g << endl;

  return 0;
}

