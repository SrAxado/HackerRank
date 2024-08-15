#include <iostream>
#include <map>
using namespace std;

int main() {
  map<string, int> m;

  m["coiso"] = 10;

  cout << m["coiso"] << endl;

  int q;

  cin >> q;
  
  for (int i = 0; i < q; ++i) {
      int type;
      string name;
      cin >> type >> name;
      
      switch (type) {
          case 1:
              int mark;
              cin >> mark;
              if (m[name]) {
                  m[name] += mark;
              } else {
                  m[name] = mark;
              }
              break;
          case 2:
              m.erase(name);
              break;
          case 3:
              cout << m[name] << endl;
          default:
              break;
      }
    }
  return 0;
}