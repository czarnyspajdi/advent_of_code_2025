#include <fstream>
#include <iostream>
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

bool is_id_periodic(string id) {
  if (id.size() < 2)
    return false;
  return (id + id).find(id, 1) < id.size();
}

vector<string> get_invalid_ids(const string range) {
  const size_t delimeter_pos = range.find("-");
  const int length = range.length();

  const long long start = stoll(range.substr(0, delimeter_pos));
  const long long end = stoll(range.substr(delimeter_pos + 1));

  vector<string> periodic_ids;

  for (long long id = start; id <= end; id++) {
    if (is_id_periodic(to_string(id))) {
      periodic_ids.push_back(to_string(id));
    }
  }
  return periodic_ids;
}

int main() {
  const string FILE_NAME = "input.txt";
  vector<string> ids = get_input_from_file(FILE_NAME);

  set<string> all_periodc_ids;

  for (string id : ids) {
    vector<string> invalid = get_invalid_ids(id);
    all_periodc_ids.insert(invalid.begin(), invalid.end());
  }

  long long sum = 0;
  for (string id : all_periodc_ids) {
    sum += stoll(id);
  }

  cout << "Sum of invalid ids: " << sum << endl;
}
