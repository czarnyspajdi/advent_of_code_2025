#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Range {
  long long begining;
  long long end;
};

vector<string> read_file(const string &FILE_NAME) {
  ifstream file(FILE_NAME);
  string s;

  vector<string> result;

  while (getline(file, s)) {
    result.push_back(s);
  }
  return result;
}

vector<Range> get_fresh_ids(const vector<string> input) {
  vector<Range> fresh_ids;
  for (string line : input) {
    if (line.empty()) {
      break;
    }
    string begining, end;
    begining = line.substr(0, line.find("-"));
    end = line.substr(line.find("-") + 1);
    Range l_range = {stoll(begining), stoll(end)};
    fresh_ids.push_back(l_range);
  }

  return fresh_ids;
}

vector<long long> get_product_ids(const vector<string> input) {
  vector<long long> product_ids;
  bool end_of_fresh_ids = false;
  for (string line : input) {
    if (line.empty()) {
      end_of_fresh_ids = true;
      continue;
    }

    if (!end_of_fresh_ids) {
      continue;
    }

    product_ids.push_back(stoll(line));
  }

  return product_ids;
}

int main() {
  const string FILE_NAME = "input.txt";

  vector<string> input = read_file(FILE_NAME);
  vector<Range> fresh_ids = get_fresh_ids(input);
  vector<long long> product_ids = get_product_ids(input);
  int count = 0;

  for (long long number : product_ids) {
    for (const Range &range : fresh_ids) {
      if (number >= range.begining && number <= range.end) {
        count++;
        break;
      }
    }
  }

  cout << count;
  return 0;
}
