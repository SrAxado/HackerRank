#include <iostream>
#include <map>
using namespace std;

int main() {
  int n, q;
  string line;
  size_t pos;
  map<string, map<string, string> > hrml;
  string tag, attrib, value;
  
  cin >> n >> q;
  
  for (int i = 0; i <= n; ++i) {
    // string tag;
    
    getline(cin, line);

    pos = line.find(' ');
    tag = line.substr(1, pos);  // discards the first character, '<'
    // hrml[tag]; // creates the tag set

    line.erase(0, pos + 1);

    while ((pos = line.find(' ')) != string::npos) {
      string sub_line = line.substr(0, pos);
      size_t pos_tmp;
      // string attrib, value;

      if ((pos_tmp = sub_line.find('=')) != string::npos) { // there's no space between attribute and value definition
        attrib = sub_line.substr(0, pos_tmp);
        value = sub_line.substr(pos_tmp + 1, sub_line.size());
      
      } else {  // there's space between the attribute and the value definition
        pos_tmp = line.find('=');
        attrib = sub_line;
        // position 0 is equal in line and sub_line
        pos = line.find(' ', pos_tmp + 2);  // finds next space after the "= " --> next definition position
                  
        value = line.substr(pos_tmp + 1, pos);
      }

      hrml[tag][attrib] = value;

      line.erase(0, pos + 1);
      
      cout << line << endl;
    }

    // map<string, string>::iterator it;

    // hrml.at("val")

    cout << hrml["tag1"]["value"] << endl;
  }
  
  //cout << line << endl;
  
  return 0;
}

// 4 3
// <tag1 value = "HelloWorld">
// <tag2 name = "Name1">
// <tag3 another="another" final="final">
// </tag2>
// </tag1>
// tag1.tag2~name
// tag1~name
// tag1~value