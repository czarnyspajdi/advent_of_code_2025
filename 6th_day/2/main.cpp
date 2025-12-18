#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> get_input(const string &FILE_NAME) {
  ifstream file(FILE_NAME);

  vector<string> result;
  string s;
  int longest = 0;
  int last_lenght = 0;

  while (getline(file, s)) {
    longest = s.length() > longest ? s.length() : longest;
    last_lenght = s.length();
    result.push_back(s);
  }
  return result;
}

int count_rows(const vector<string> &input) {
  int count = 0;
  for (string row : input) {
    count++;
  }

  return count;
}

vector<vector<string>> process_input(const vector<string> &input) {
  string new_column = "";
  vector<vector<string>> result;
  vector<string> group;
  char expresion = ' ';

  // for every row from behind
  for (int i = input[0].length() - 1; i >= 0; i--) {

    // for every column
    for (int j = 0; j < count_rows(input); j++) {

      char symbol = input[j][i];
      if (symbol == ' ') {
        continue;
      }

      if (symbol != '+' && symbol != '*') {
        new_column += symbol;
      } else {
        expresion = symbol;
      }
    }
    if (new_column != "") {
      group.push_back(new_column);
      new_column = "";
    }

    if (expresion != ' ') {
      group.push_back(string(1, expresion));
      result.push_back(group);
      expresion = ' ';
      group.clear();
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
  vector<string> input = get_input(FILE_NAME);
  vector<vector<string>> processed_input = process_input(input);

  long long sum = 0;

  for (auto &row : processed_input) {
    sum += process_operation(row);
  }
  cout << "Sum: " << sum << endl;
  return 0;
}
