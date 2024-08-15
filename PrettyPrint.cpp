#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
// #include <iomanip>
using namespace std;

char* hex_convert(double num) {
  constexpr const char* hex {"0123456789ABCDEF"};
  const auto ucx {static_cast<unsigned char>(num)};
  char var1 {hex[ucx >> 4]};  // divide by 2 * 4 = 16
  char var2 {hex[ucx >> 4 >> 4]};
  char var3 {hex[ucx & 0xf]};

  cout << var1 << var2 << var3 << endl;

  return nullptr;
}

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
  int t;
  vector<vector<double>> numbers;
  cin >> t;
  
  for (int i = 0; i < t; ++i) {
      string num;
      vector<double> tmp_vector;
      
      cin >> num;
      tmp_vector.push_back(atof(num.c_str()));
      
      cin >> num;
      tmp_vector.push_back(atof(num.c_str()));
      
      cin >> num;
      tmp_vector.push_back(atof(num.c_str()));

      numbers.push_back(tmp_vector);
  }
  
  //cout << hex << *reinterpret_cast<unsigned __int64 *>(&numbers[0]);
  // constexpr const char* hex {"0123456789ABCDEF"};

  // const auto ucx {static_cast<unsigned char>(numbers[0])};
  // char var1 {hex[ucx >> 4]};  // divide by 2 * 4 = 16
  // char var2 {hex[ucx & 0xf]};

  // cout << var1 << var2 << endl;

  // const char* numaro = "0x422db513ac";
  // unsigned long hexNumber;
  // sscanf(numaro, "%x", &hexNumber);

  // std::cout << hexNumber << endl;

  for (int i = 0; i < t; ++i) {
    vector<char> hex_num = {'0', 'x'};

    double tmp_hex = trunc(numbers[i][0]);
    double a = 1;

    while (a * 16 < tmp_hex) {
      a *= 16;
    }

    while (a >= 1) {
      int m;
      for (m = 0; m < 16 && (m + 1) * a <= tmp_hex; ++m) {}

      hex_num.push_back("0123456789abcdef"[m]);

      tmp_hex -= m * a;
      a /= 16;
    }

    for (char c : hex_num) {
      cout << c;
    }
    cout << endl;
    
    // std::cout << trunc(numbers[i][0]) << endl;
    // hex_convert(numbers[i][0]);
    // printf("%#x\n", trunc(numbers[i][0]));
    // std::cout << hexfloat << trunc(numbers[i][0]) << endl;

    // constexpr const char* hex {"0123456789abcdef"};
    // const auto ucx {static_cast<unsigned char>(trunc(numbers[i][0]))};
    // char var1 {hex[ucx >> 4]};  // divide by 2 * 4 = 16
    // char var2 {hex[ucx & 0xf]};

    // // int var4 = int(numbers[i][0]) % 16;
    // // int var3 = numbers[i][0] / 16;

    // cout << "0x" << var1 << var2 << endl;
    // printf("%#x\n", numbers[i][0]);


    char str[40];
    sprintf(str, "%015.2f", numbers[i][1]);

    for (int j = 0; j < 15; ++j) {
      if (str[j] == '0') {
        str[j] = '_';
      } else {
        str[j - 1] = (numbers[i][1] >= 0) ? '+' : '-';
        break;
      }
    }

    cout << str << endl;


    printf("%.9E\n", numbers[i][2]);
  }
    
  return 0;
}



/*
Sample Input
  1  
  100.345 2006.008 2331.41592653498

Sample Output
  0x64             
  _______+2006.01  
  2.331415927E+03

*/