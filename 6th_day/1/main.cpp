#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<string>> get_input(const string &FILE_NAME) {
  ifstream file(FILE_NAME);

  vector<vector<string>> result;
  vector<string> local_vec;

  size_t pos = 0;
  string s;
  while (getline(file, s)) {
    while ((pos = s.find(" ")) != string::npos) {
      if (pos == 0) {
        s.erase(0, 1);
        continue;
      }
      local_vec.push_back(s.substr(0, pos));
      s.erase(0, pos);
    }
    local_vec.push_back(s);
    result.push_back(local_vec);
    local_vec.erase(local_vec.end());
  }

  return result;
}

int main() {
  return 0;
  const string &FILE_NAME = "example.txt";
  vector<vector<string>> input = get_input(FILE_NAME);

  for (vector<string> vec : input) {
    cout << "Vec: " << endl;
    for (string s : vec) {
      cout << s << endl;
      ;
    }
  }
}
