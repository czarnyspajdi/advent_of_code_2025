#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> get_input(const string FILE_NAME) {
  ifstream file = ifstream(FILE_NAME);
  string s;
  vector<string> input;
  while (getline(file, s)) {
    input.push_back(s);
  }
  return input;
}

int find_highest_joltage(string bank) {
  int number;
  int first_highest_num = 0;
  int second_highest_num = 0;
  int highest_pos;

  for (int i = 0; i < bank.length() - 1; i++) {
    number = stoi(bank.substr(i, 1));
    if (number > first_highest_num) {
      first_highest_num = number;
      highest_pos = i;
    }
  }

  for (int i = highest_pos + 1; i < bank.length(); i++) {
    number = stoi(bank.substr(i, 1));
    if (number > second_highest_num) {
      second_highest_num = number;
    }
  }
  string result = to_string(first_highest_num) + to_string(second_highest_num);

  return stoi(result);
}

int main() {
  const string FILE_NAME = "input.txt";
  vector<string> banks = get_input(FILE_NAME);
  int sum = 0;
  for (string bank : banks) {
    int highest_joltage = find_highest_joltage(bank);
    cout << "Highest joltage found: " << highest_joltage << endl;
    sum += highest_joltage;
  }
  cout << "Sum of all the joltage: " << sum << endl;
}
