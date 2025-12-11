#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int translate_movement(const string &input) {

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

    if (abs(delta) >= 100) {
      int cycles = abs(delta) / 100;
      delta = delta % 100;
      count_zero += cycles;
    }

    int old_pos = pos;
    pos = normalize_number(pos + delta);

    if (delta > 0 && pos < old_pos) {
      count_zero++;
    }

    if (delta < 0) {
      if ((pos > old_pos && old_pos != 0) || pos == 0) {
        count_zero++;
      }
    }
  }
  printf("Dial pointed at zero %d times.", count_zero);
}
