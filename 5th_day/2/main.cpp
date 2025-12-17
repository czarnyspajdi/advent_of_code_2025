#include <algorithm>
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

bool compareRanges(const Range &a, const Range &b) {
  return a.begining < b.begining;
}

int main() {
  const string FILE_NAME = "input.txt";

  vector<string> input = read_file(FILE_NAME);
  vector<Range> fresh_ids = get_fresh_ids(input);
  long long count = 0;

  sort(fresh_ids.begin(), fresh_ids.end(), compareRanges);

  vector<Range> merged_fresh_ids;
  merged_fresh_ids.push_back(fresh_ids[0]);

  for (int i = 1; i < fresh_ids.size(); i++) {
    Range current_range = fresh_ids[i];
    Range &last_range = merged_fresh_ids.back();

    if (current_range.begining <= last_range.end + 1) {
      last_range.end = max(last_range.end, current_range.end);
    } else {
      merged_fresh_ids.push_back(current_range);
    }
  }

  for (Range range : merged_fresh_ids) {
    count += range.end - range.begining + 1;
  }

  cout << count;
  return 0;
}
