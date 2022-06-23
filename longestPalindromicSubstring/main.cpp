#include <string>
#include <iostream>

int main()
{
  std::string s = "babad";

  int range[2] = {0, 0};
  const int length = s.length();
  int i = 0;
  while (i < length)
  {
    int pointer1 = i, pointer2 = i;
    while (pointer2 < length && s[pointer2] == s[i])
    {
      pointer2++;
    }
    pointer1--;
    i = pointer2;
    while (pointer1 >= 0 && pointer2 < length)
    {
      if (s[pointer1] == s[pointer2])
      {
        pointer1--;
        pointer2++;
      }
      else
      {
        break;
      }
    }

    if (pointer2 - pointer1 - 2 > range[1] - range[0])
    {
      range[0] = pointer1 + 1;
      range[1] = pointer2 - 1;
    }
  }

  std::cout << s.substr(range[0], range[1] - range[0] + 1) << "\n";
}
