#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, string> memo;

bool isMatch(string &password, string &attempt)
{
  if (attempt.size() < password.size())
  {
    return false;
  }

  int pointer = 0;
  for (int i = 0, length = password.size(); i < length; ++i)
  {
    if (password[i] != attempt[i])
    {
      return false;
    }
  }

  return true;
}

string cracker(vector<string> &passwords, string loginAttempt)
{
  if (memo.count(loginAttempt) != 0) {
    return memo[loginAttempt];
  }

  for (int i = 0, length = passwords.size(); i < length; ++i)
  {
    if (isMatch(passwords[i], loginAttempt))
    {
      if (passwords[i].size() == loginAttempt.size())
      {
        memo[loginAttempt] = passwords[i];
        return passwords[i];
      }

      string result = cracker(passwords, loginAttempt.substr(passwords[i].size(), loginAttempt.size() - passwords[i].size()));
      if (result == "WRONG PASSWORD")
      {
        continue;
      }
      memo[loginAttempt] = passwords[i] + " " + result;
      return memo[loginAttempt];
    }
  }

  memo[loginAttempt] = "WRONG PASSWORD";
  return "WRONG PASSWORD";
}

string passwordCracker(vector<string> passwords, string loginAttempt)
{
  int c = 0;

  for (int i = 0, length = loginAttempt.length(); i < length; ++i) {
    for (auto& password : passwords) {
      if (password.length() > loginAttempt.length()) {
        continue;
      }
      bool found = false;

      for (int j = 0, l = password.length(); j < l; ++j) {
        if (password[j] == loginAttempt[i]) {
          c++;
          found = true;
          break;
        }
      }

      if (found) {
        break;
      }
    }
  }

  if (c == loginAttempt.length()) {
    return cracker(passwords, loginAttempt);
  }

  return "WRONG PASSWORD";
}

void main()
{
  vector<string> input = {"c", "aaaa", "aaaaaa", "aaaaa", "b", "cc", "aaaaaaaaaa", "baaaaa", "aaaac", "caaaaa"};
  string result = passwordCracker(input, "caaaaaaaaaaaaaaaaaaaaaaaaaaaaaacaaaacbbaaaaabaaaaaaaacaaaaaaaaaacaaaaaaaaccaaaaacccaaaaaaaaaaaaaaacbbaaaaaaaaaacaaaaaaaaacaaaaaaaaaaaaaaaaaaaaaaaaacaaaaccaaaaaaaaacaaaaaabaaaaaccbaaaaabbaaaaaaaaaabaaaaaabaaaaaaaaacbaaaaaccbaaaaaaaaacccbaaaaaaaaabaaaaacccaaaaabcaaaaabaaaaaaaaacaaaaaaaaaaaaaacaaaaaaaaaacaaaaaccccaaaaabaaaaacaaaaaaaaaaaaaaaaaaaaaacccaaaaaaaaaccbaaaaaaaaacaaaaabaaaaaaaaaaccaaaaaacaaaaaccaaaabbaaaaabaaaabaaaaaaaaacbbaaaaabccaaaaaaaaaacbbaaaaabaaaaaaaaabaaaaaaaaaaaaaabaaaaaaaaaaaaaaabaaaaaaaaaaaaaaacccccaaaaaaaaacaaaaaaaaaabaaaaaaaaaaaccbaaaaaaaaaaaaaaaaaaabcaaaaaaaacccaaaaaaaaaaaaaaaaaaaabaaaaaaaaaccaaaacccaaaaaaaaaacbaaaaaaaaaaaaaaabaaaaaaaaaaaaaaacaaaaaaaaaaaaaaaaaacccaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaacaaaaabaaaaaaaaaaaaaaaaacccaaaaaaaaaacccaaaaabaaaaaaaaaaaaaaacaaaaaaaaacaaaaaaaaaaaaaaabaaaaaaaaaaaaaaabaaaacaaaaaaaaaaaaaaacaaaaaccaaaaccaaaaccaaaaaaaaacbaaaaacaaaaaaaaaaaaaaacaaaacaaaaaaaaaacaaaaaaaaaaaaaaccccaaaaaaaaacaaaacbbaaaaabaaaaaacaaaaaaaaaaaaaaaaaaaaaaaaaaaaacaaaaaaaaaacaaaacaaaaaaaaaabaaaaacaaaacaaaacaaaaacaaaaaaaaacaaaacaaaaaaaaaaaaaaabaaaaaaccaaaaabaaaaaaaaaaaaaaabaaaaaaaacaaaacaaaacaaaacaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaccccccaaaaaaaaaacbaaaaabaaaaabaaaaaaaaaaaabaaaacbaaaacbaaaaaaaaabaaaaaaaaaaaaaaacbaaaaabaaaaaaaaacaaaaaccccaaaaccccccaaaaaaaaaacaaaacccaaaacaaaacbaaaaaaaaaaaaaaabaaaaacbaaaaaaaaaaaaaaaaaaccccaaaaccaaaaaaaaaabaaaaabccaaaaaabaaaaaaaaaacaaaaaaaaaaaaaaaabaaaaaaaaaaaaacaaaacaaaacccccaaaaaaaaaaccaaaaccaaaaacccccaaaaaaaaaccaaaaacaaaaabaaaaaaaaacaaaacaaaaaaaaaaccaaaaaaaaaacaaaacccccccccaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaacaaaaacaaaaaaaaaccaaaaaccbaaaaaaaaacccaaaaabbbaaaaacaaaaaaaaaaaaaaaaaaaaaaaaaaaaaacaaaaaaaaaabbbaaaaaaaaaaaaaaacaaaaaaaaaaabcaaaaaaaaaabaaaaaaaaaabaaaaacccaaaaaccaaaaacccccbaaaaaaaaaaaaaaccbaaaaacccaaaaaaaaacaaaaaaaaaaaaaaacaaaaaaaaaacbbaaaaaaaaaaaaaaaaaaaacaaaaaaaaabaaaaaaaaaaaccccaaaaaaaaaaaaaaaaaaacaaaaacaaaaacaaaaabaaaaacaaaaacbcaaaaacaaaaaaaaaaaaaacaaaabaaaaaaaaacccaaaaacaaaacaaaaaaaaaaaaaaaaaaaac");
  // vector<string> input = {"ab", "abcd", "cd"};
  // string result = passwordCracker(input, "abcd");
  cout << result << "\n";
}
