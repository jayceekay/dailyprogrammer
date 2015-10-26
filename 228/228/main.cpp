#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {

  vector<string> words = {
    "billowy",
    "biopsy",
    "chinos",
    "defaced",
    "chintz",
    "sponged",
    "bijoux",
    "abhors",
    "fiddle",
    "begins",
    "chimps",
    "wronged"
  };

  for (auto it = words.begin(); it < words.end(); it++) {
    bool ordered = true, reversed = true;

    for (auto i = 1; i < it->size(); i++) {
      auto forward_leftmost = (*it)[i - 1];
      auto forward_leftmost_second = (*it)[i];
      auto backward_rightmost = (*it)[it->size() - i];
      auto backward_rightmost_second = (*it)[it->size() - i - 1];

      if (forward_leftmost > forward_leftmost_second) {
        ordered = false;
      }

      if (backward_rightmost > backward_rightmost_second) {
        reversed = false;
      }
    }

    cout << *it << (reversed ? " REVERSE ORDER" : (ordered ? " IN ORDER" : " NOT IN ORDER")) << endl;
  }
  
  return 0;
}
