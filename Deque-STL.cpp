#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
  int test_cases;
  string line;
  
  getline(cin, line);
  test_cases = stoi(line);
  // cin >> test_cases;
  
  for (int test = 0; test < test_cases; ++test) {
    int size_N, size_K;
    vector<int> arr;
    int tmp, max;
    size_t pos;
    
    // getline(cin, line);
    cin >> size_N >> size_K;
    // pos = line.find(' ');
    
    // size_N = stoi(line.substr(0, pos));
    // size_K = stoi(line.substr(pos + 1, line.size() - pos)); // size => line[] +1  (<-- -1 ) --> pos + 1 ===> -1 + 1 = 0 --> size + pos
    
    // cout << "pos->" << line.size() - pos << "<-  -->" << line.substr(pos + 1, line.size() - pos) << endl;
    
    // cout << size_N << "' -- '" << size_K << endl;

    for (int i = 0; i < size_N; ++i) {
      cin >> tmp;
      arr.push_back(tmp);
    }
    // getline(cin, line);
    
    // cout << "--------------------------" << endl;
    // cout << line << endl;
    
    // int arr[size_N];
/*
    // int tmp = 0;
    while ((pos = line.find(' ')) != string::npos) {
      arr.push_back(stoi(line.substr(0, pos)));
      // arr[tmp] = stoi(line.substr(0, pos));
      line.erase(0, pos + 1);
      // ++tmp;
    }
    arr.push_back(stoi(line));
*/
    // arr[tmp] = stoi(line);
    cout << "---------- [" << arr.size() << "] " << arr[arr.size() - 1] << " ----------------" << endl;
    /*
    for (int i : arr) {
      cout << i << ' ';
    }
    */

  //  getline(cin, line);

    // cout << "--- Pause ---";
    // cin >> tmp;
    for (int i = 0; i < size_N - size_K; ++i) {
      max = 0;
      for (int j = i; j < i + size_K; ++j) {
      // cout << "[[" << j << "] " << i << " + " << size_K << " = " << i + size_K << "] " << arr[j] << endl;
        // cout << arr[j] << ',';
        if (arr[j] > max) {
          max = arr[j];
          // cout << '[' << j << "] " << max << endl;
        }
      }
      // cout << '}' << endl;
      // cout << '[' << size_N << size_N - size_K << " - " << i << "] -- {";
      cout << max << ' ';
      max = 0;
    }
    cout << endl;
/*
*/
    /*
    */
    // cout << endl;
    /*
    for (int i = 0; i <= size_N - size_K; ++i) {
      for (int j = 0; j < size_K; ++j) {
        cin >> tmp;
        arr.push_back(tmp);
      }
      
      for (int j : arr) {
        cout << j << ' ';
      }
      cout << endl;
    }
    */
      
  }
  
  return 0;
}
