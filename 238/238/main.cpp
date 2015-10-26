#include <iostream>
#include <cctype>

using namespace std;

const char CONSONANTS[] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
const char VOWELS[] = {'a', 'e', 'i', 'o', 'u'};

const int CONSONANTS_SZ = sizeof(CONSONANTS);
const int VOWELS_SZ = sizeof(VOWELS);

char *make_word(const string pattern) {
  char *new_word = new char[pattern.size()];

  for (int i = 0; i < pattern.size(); i++) {
    switch (pattern[i]) {
      case 'c':
      case 'C':
        new_word[i] = CONSONANTS[rand() % CONSONANTS_SZ];
        break;
      case 'v':
      case 'V':
        new_word[i] = VOWELS[rand() % VOWELS_SZ];
        break;
    }

    if (isupper(pattern[i])) {
      new_word[i] = toupper(new_word[i]);
    }
  }

  return new_word;
}

bool is_valid(const string pattern) {
  for (const char &c : pattern) {
    if (c != 'c' && c != 'C' && c != 'v' && c != 'V') {
      return false;
    }
  }
  return true;
}

void print_words(int times, const string pattern) {
  while(times--) {
    char *word = make_word(pattern);
    cout << word << endl;
    delete [] word;
  }
}

int main(int argc, const char * argv[]) {
  srand(static_cast<unsigned int>(time(NULL)));

  string pattern;

  while (true) {
    cout << "enter word pattern (using c's and v's, single 'q' to quit): ";
    cin >> pattern;

    if (pattern.size() == 1 && (pattern == "q" || pattern == "Q")) {
      cout << "quitting..." << endl;
      break;
    }

    if (is_valid(pattern)) {
      cout << "# of words to generate: ";
      int times;
      cin >> times;

      print_words(times, pattern);
    } else {
      cout << "bad input - use only c's and v's." << endl;
    }
  }

  cout << "done!";
  return 0;
}
