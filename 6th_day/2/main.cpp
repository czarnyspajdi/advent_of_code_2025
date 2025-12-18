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

vector<vector<string>> process_input(const vector<string> &input) {
  string new_column = "";

  vector<vector<string>> result;
  vector<string> group;

  char expresion = ' ';
  const int row_count = input.size();
  const int column_count = input.front().size();

  group.reserve(row_count + 1);
  new_column.reserve(row_count);

  // for every row from behind
  for (int i = column_count - 1; i >= 0; i--) {

    // for every column
    for (int j = 0; j < row_count; j++) {

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
      group.push_back(std::move(new_column));
      new_column.clear();
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
    for (const string &value : input) {
      cout << value << " ";
      sum += stoll(value);
    }
    cout << endl;
    break;
  case '*':
    sum = 1;
    cout << "Now we are multiplying numbers: ";
    for (const string &value : input) {
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
