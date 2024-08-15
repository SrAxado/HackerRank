#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);



int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        vector<int> multiples;
        string n_temp;
        getline(cin, n_temp);
        int n;

        try {
          n = stoi(ltrim(rtrim(n_temp)));
        }
        catch (const out_of_range& err) {
          cerr << "Out of range: " << err.what() << endl;
          continue;
        }
        catch (const invalid_argument& err) {
          cerr << "Invalid argument: " << err.what() << endl;
          continue;
        }

        for (int j = 3; j < n; ++j) {
            if ((j % 3 == 0) || (j % 5 == 0)) {
                multiples.push_back(j);
            }
        }
        int sum = 0;
        for (int i : multiples) {
            sum += i;
        }
        cout << sum << endl;
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
