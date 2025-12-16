#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> get_input_from_file(const string &FILE_NAME) {
  ifstream file(FILE_NAME);
  vector<string> result;
  string s, first_line;
  size_t length;

  if (getline(file, first_line)) {
    first_line = "." + first_line + ".";
    length = first_line.length();
  }

  result.push_back(string(length, '.'));
  result.push_back(first_line);

  while (getline(file, s)) {
    result.push_back("." + s + ".");
  }
  result.push_back(string(length, '.'));
  return result;
}

bool is_available(const string &current_line, const string &next_line,
                  const string &prev_line, const int pos) {
  assert(current_line[pos] == '@');

  int count = 0;
  const char ROLL = '@';

  for (int i = pos - 1; i <= pos + 1; i++) {
    if (prev_line[i] == ROLL) {
      count++;
    }

    if (next_line[i] == ROLL) {
      count++;
    }
  }

  if (current_line[pos - 1] == ROLL) {
    count++;
  }

  if (current_line[pos + 1] == ROLL) {
    count++;
  }

  return count < 4;
}

int main() {
  string const FILE_NAME = "input.txt";
  vector<string> input = get_input_from_file(FILE_NAME);
  int count = 0;

  for (int i = 1; i < input.size() - 1; i++) {
    for (int j = 1; j < input[i].size() - 1; j++) {
      if (input[i][j] == '@' &&
          is_available(input[i], input[i + 1], input[i - 1], j)) {
        count++;
      }
    }
  }
  cout << count;

  return 0;
}
