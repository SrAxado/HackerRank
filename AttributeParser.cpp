#include <iostream>
#include <map>
using namespace std;

int main() {
  int n, q;
  string line;
  size_t pos, pos_tmp;
  map<string, map<string, string> > hrml;
  string tag, attrib, value;
  
  cin >> n >> q;

  
  for (int i = 0; i <= n; ++i) {
    // string tag;
    
    getline(cin, line);

    pos = line.find(' ');

    if (pos != string::npos) {
      // cout << pos << "<-----" << endl;
      tag = line.substr(1, pos - 1);  // discards the first character, '<'
      hrml[tag]; // creates the tag set

      line.erase(0, pos + 1); // line --> values / attributes + ">"

      // cout << pos << "^ " << tag << "  --- " << line << endl;
      while ((pos = line.find(' ')) != string::npos) {
        // string attrib, value;
        // size_t pos_tmp;
        string sub_line = line.substr(0, pos);

        // cout << "esta é a sub-line --> " << sub_line << "<--" << endl;

        if ((pos_tmp = sub_line.find('"')) != string::npos) { // there's no space between attribute and value definition
          // cout << "No space between attrib and values: " << sub_line << "<--" << endl;
          attrib = sub_line.substr(0, pos_tmp - 1);
          value = sub_line.substr(pos_tmp + 1, (sub_line.size() - 1) - (pos_tmp + 1));  // (size() - 1) - 1 <-- " char at the end
        
        } else {  // there's space between the attribute and the value definition
          // simply don't use the attrib variable --> hrml[tag][sub_line] = value;
          attrib = sub_line;  // sub_line.copy(attrib, sub_line.size(), 0);

          pos_tmp = line.find('"');
          // position 0 is equal in line and sub_line
          pos = line.find(' ', pos_tmp);  // finds next space after the " char --> next definition position
          if (pos != string::npos) {  // other attribute(s) exist
            value = line.substr(pos_tmp + 1, (pos - 1) - (pos_tmp + 1));
          } else {  // last value
            value = line.substr(pos_tmp + 1, (line.size() - 2) - (pos_tmp + 1));  // (size() - 1)) - 1 ('"')
            pos = line.size() - 2;  // to get ">" after erasing
            // line.erase(0, line.size() - 1);
          }
        }
        // hrml[tag][attrib] = value;
        hrml[tag][attrib] = value;

        line.erase(0, pos + 1);
        
        // cout << "-->"<< line << "<--" << endl;
/*
        if ((pos = line.find(' ')) != string::npos) {
          cout << "Before new While-->" << line << "<--" << endl;
          if ((pos_tmp = line.find('"')) != string::npos) {
            attrib = line.substr(0, pos_tmp);
            
            pos = line.find('"');
            value = line.substr(pos_tmp + 1, pos - (pos_tmp + 1));
          }
        } else {  // last value
          cout << "Last value -->" << line << "<--" << endl;
          if ((pos_tmp = line.find('"')) != string::npos) {
            attrib = line.substr(0, pos_tmp);
          }
        }
*/
      }

      if ((pos_tmp = line.find('"')) != string::npos) {
        attrib = line.substr(0, pos_tmp - 1);

        pos = line.find('"', pos_tmp + 1); // a second " always exists
        value = line.substr(pos_tmp + 1, (pos - 1) - pos_tmp);

        // cout << "line_size=" << line.size() << " pos=" << pos << " pos_tmp=" << pos_tmp << endl;

        hrml[tag][attrib] = value;
      }

    } else {  // end tag || tag without attributes ("a tag can/may have no attributes")
      // if ((pos = line.find('/')) == string::npos) { // tag without attributes
      //   hrml[line.substr(1, line.size() - 2)];
      // }

    }

    // map<string, string>::iterator it;

    // hrml.at("val")


    ///////cout << hrml["tag1"]["value"] << endl;
  }
  
  //cout << line << endl;

  for (const auto &[t, v] : hrml) {
    cout << "hrml[" << t << "]" << endl;
    for (const auto &[attrib, value] : v) {
      cout << "\t(" << attrib << ", " << value << ");" << endl;
    }
  }

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

// <tag1 value = "HelloWorld">
// <tag2 name = "Name1" name2 = "Name2">
// <tag3 another="another" final="final">
// </tag3>
// </tag2>
// </tag1>