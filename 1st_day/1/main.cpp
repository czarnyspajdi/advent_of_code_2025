#include <fstream>
#include <string>
#include <vector>

using namespace std;

int translate_movement(string input) {
  string symbol = input.substr(0, 1);
  int ammount = stoi(input.substr(1));
  return (symbol == "R") ? ammount : -ammount;
}

int normalize_number(int number) {
  number %= 100;
  if (number < 0)
    number += 100;
  return number;
}

int main() {
  std::ifstream file("input.txt");

  vector<string> data;
  string s;

  while (file >> s) {
    data.push_back(s);
  }

  int count_zero = 0;
  int pos = 50;
  for (const string &movement : data) {
    int delta = translate_movement(movement);
    pos = normalize_number(pos + delta);

    if (pos == 0) {
      count_zero++;
    }
  }
  printf("Dial pointed at zero %d times.", count_zero);
}
