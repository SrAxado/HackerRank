#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, q;
  int num;
  vector<vector<int>> k;
  int i, j;

  cin >> n >> q;
  
  // fills the variable-length arrays
  for (int n_row = 0; n_row < n; ++n_row) {
    cin >> num;
    vector<int> row;
    for (int i = 0; i < num; ++i) {
      int tmp;
      cin >> tmp;
      row.push_back(tmp);
    }
    k.push_back(row);
  }

  for (int q_num = 0; q_num < q; ++q_num) {
    cin >> i >> j;
    cout << k[i][j] << endl;
  }

  return 0;
}