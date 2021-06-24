#include <iostream>
#include <set>

using namespace std;

char step(char s, int& x, set<int>& t){
  if(s == 'A'){
    if(!t.count(x)){
      t.insert(x);
      x++;
      return 'B';
    } else {
      t.erase(x);
      x--;
      return 'C';
    }
  } else if(s == 'B'){
    if(!t.count(x)){
      t.insert(x);
      x--;
      return 'A';
    } else {
      x++;
      return 'C';
    }
  } else if(s == 'C'){
    if(!t.count(x)){
      t.insert(x);
      x++;
      return 'A';
    } else {
      t.erase(x);
      x--;
      return 'D';
    }
  } else if(s == 'D'){
    if(!t.count(x)){
      t.insert(x);
      x--;
      return 'E';
    } else {
      x--;
      return 'C';
    }
  } else if(s == 'E'){
    if(!t.count(x)){
      t.insert(x);
      x++;
      return 'F';
    } else {
      x++;
      return 'A';
    }
  } else if(s == 'F'){
    if(!t.count(x)){
      t.insert(x);
      x++;
      return 'A';
    } else {
      x++;
      return 'E';
    }
  }
  return 'A';
}

int main(){
  set<int> t;
  int x = 0;
  char s = 'A';

  for(int i = 0; i < 12261543; i++) s = step(s,x,t);

  cout << t.size() << endl;

  return 0;
}

