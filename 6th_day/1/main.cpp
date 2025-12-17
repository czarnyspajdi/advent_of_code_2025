#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<string>> get_input(const string &FILE_NAME) {
  ifstream file(FILE_NAME);

  vector<vector<string>> result;
  string s;

  while (getline(file, s)) {
    size_t pos;
    size_t i = 0;

    while ((pos = s.find(' ')) != string::npos) {
      if (pos == 0) {
        s.erase(0, 1);
        continue;
      }
      string word = s.substr(0, pos);
      s.erase(0, pos + 1);

      if (i >= result.size()) {
        result.emplace_back();
      }

      result[i].push_back(word);
      i++;
    }
    if (!s.empty()) {
      if (i >= result.size()) {
        result.emplace_back();
      }
      result[i].push_back(s);
    }
  }
  return result;
}

long long process_operation(vector<string> &input) {
  char operation = input.back()[0];
  input.pop_back();
  long long sum;
  switch (operation) {
  case '+':
    sum = 0;
    cout << "Now we are adding numbers: ";
    for (string value : input) {
      cout << value << " ";
      sum += stoll(value);
    }
    cout << endl;
    break;
  case '*':
    sum = 1;
    cout << "Now we are multiplying numbers: ";
    for (string value : input) {
      cout << value << " ";
      sum *= stoll(value);
    }
    cout << endl;
    break;
  }
  cout << "The sum is " << sum << endl;
  return sum;
}

int main() {
  const string FILE_NAME = "input.txt";
  vector<vector<string>> input = get_input(FILE_NAME);
  long long sum = 0;
  for (vector<string> group : input) {
    sum += process_operation(group);
  }
  cout << sum;
  return 0;
}
