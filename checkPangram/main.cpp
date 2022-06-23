#include <string>
#include <iostream>

int main() {
  std::string sentence = "thequickbrownfoxjumpsoverthelazydog";

  bool arr[26] = { false };
  int count = 0;

  const int length = sentence.length();
  for (int i = 0; i < length; i++) {
      int index = sentence[i] % 26;
      
      if (!arr[index]) {
          arr[index] = true;
          count++;
      }
  }

  for (int i = 0; i < 26; i ++) {
    std::cout << arr[i] << "\n";
  }

  std::cout << (count == 26) << "\n";
  return 1;
}