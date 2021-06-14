#include <iostream>
#include <queue>

using namespace std;

struct g{
  long long int val;
  long long int mul;
  long long int mod = 2147483647;
  g(int a, int b){
    val = a;
    mul = b;
  }
};

struct j{
  queue<long long int> a;
  queue<long long int> b;
  long long int c = 0;
  int p = 0;
};

const bool operator==(const g& a, const g& b){
  return (a.val % 65536) == (b.val % 65536);
}

void step(g& a){
  a.val = (a.val * a.mul) % a.mod;
}

int main(){
  g a(679, 16807);
  g b(771, 48271);

  int o = 0;
  j d;

  for(long long int i = 0; i < 40000000; i++){
    step(a);
    if(!(a.val % 4)) d.a.push(a.val);
    step(b);
    if(!(b.val % 8)) d.b.push(b.val);
    if(a==b)o++;
    while(d.a.size() && d.b.size()){
      if((d.a.front() % 65536) == (d.b.front() % 65536)) d.p++;
      d.c++;
      d.a.pop();
      d.b.pop();
    }
  }

  cout << o << endl;

  while(d.c < 5000000){
    step(a);
    if(!(a.val % 4)) d.a.push(a.val);
    step(b);
    if(!(b.val % 8)) d.b.push(b.val);
    while(d.a.size() && d.b.size()){
      if((d.a.front() % 65536) == (d.b.front() % 65536)) d.p++;
      d.c++;
      d.a.pop();
      d.b.pop();
    }
  }

  cout << d.p << endl;

  return 0;
}
