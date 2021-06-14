#include <iostream>
#include <vector>

using namespace std;

int main(){
  int a = 312;
  vector<int> p = {0};

  int i = 0;

  for(int j = 1; j <= 2017; j++){
    i = (i + a) % p.size();
    p.insert(p.begin() + i + 1, j);
    i++;
  }

  cout << p[i+1] << endl;

  for(int j = 2018; j <= 50000000; j++){
    i = (i + a) % j;
    i++;
    if(i == 1) p[1] = j;
  }

  cout << p[1] << endl;

  return 0;
}

