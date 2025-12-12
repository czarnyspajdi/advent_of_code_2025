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

long long find_highest_joltage(string bank) {
  const int MAX_AMMOUNT = 12;
  vector<char> stack;
  int size = bank.size();

  for (int i = 0; i < size; ++i) {
    char c = bank[i];
    while (!stack.empty() && stack.back() < c &&
           (stack.size() - 1 + size - i >= MAX_AMMOUNT)) {
      stack.pop_back();
    }

    if (stack.size() < MAX_AMMOUNT) {
      stack.push_back(c);
    }
  }

  string result(stack.begin(), stack.end());
  return stoll(result);
}

int main() {
  const string FILE_NAME = "input.txt";
  vector<string> banks = get_input(FILE_NAME);
  long long sum = 0;
  for (string bank : banks) {
    long long highest_joltage = find_highest_joltage(bank);
    cout << "Highest joltage found: " << highest_joltage << endl;
    sum += highest_joltage;
  }
  cout << "Sum of all the joltage: " << sum << endl;
}
