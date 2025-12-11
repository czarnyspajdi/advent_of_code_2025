#include <fstream>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<string> get_input_from_file(const string file_name) {
  ifstream file(file_name);
  string input;
  getline(file, input);
  input += ",";

  size_t pos;
  vector<string> ids;

  while ((pos = input.find(",")) != string::npos) {
    if (pos == 0) {
      input.erase(0, 1);
      continue;
    }
    string id = input.substr(0, pos);
    ids.push_back(id);
    input.erase(0, pos + 1);
  }

  file.close();

  return ids;
}

bool is_id_valid(string id) {
  int len = id.length();
  if (len % 2 != 0) {
    return true;
  }

  string first_half = id.substr(0, len / 2);
  string second_half = id.substr(len / 2);

  if (first_half == second_half) {
    cout << "Id " << id << " is not valid!" << endl;
    return false;
  }

  return true;
}

set<string> get_invalid_ids(const string range) {
  const size_t delimeter_pos = range.find("-");
  const int length = range.length();

  const long long start = stoll(range.substr(0, delimeter_pos));
  const long long end = stoll(range.substr(delimeter_pos + 1));

  set<string> invalid_ids;

  for (long long id = start; id <= end; id++) {
    if (!is_id_valid(to_string(id))) {
      invalid_ids.insert(to_string(id));
    }
  }
  return invalid_ids;
}

int main() {
  const string FILE_NAME = "input.txt";
  vector<string> ids = get_input_from_file(FILE_NAME);

  set<string> all_invalid_ids;

  for (string id : ids) {
    set<string> invalid = get_invalid_ids(id);
    all_invalid_ids.insert(invalid.begin(), invalid.end());
  }
  cout << "Ammount of invalid ids: "
       << accumulate(all_invalid_ids.begin(), all_invalid_ids.end(), 0) << endl;
}
