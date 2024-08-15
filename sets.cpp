#include <iostream>
#include <set>
using namespace std;

int main() {
  set<int> s;
  set<int>::value_compare comp = s.value_comp();

  for (int i = 0; i < 6; ++i) {
    s.insert(i*10);
  }

  int high = *s.end();
  set<int>::iterator it = s.begin();
  do {
    cout << *it << ' ';
  } while (comp(*(++it), high));
  cout << endl;

  for (it = s.begin(); it != s.end(); ++it) {
    cout << *it << ' ';
  }
  cout << endl;

  set<int>::iterator it_f = s.find(50);  // gives the iterator to the element val if it is found; otherwise returns s.end()
  
  if (it_f == s.end()) {
    cout << "It does not exist\n";
  } else {
    cout << *it_f << endl;
  }

  cout << *--(--s.end()) << endl; // prints the one before last element

  return 0;
}