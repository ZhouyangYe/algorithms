#include <string>
#include <iostream>

using namespace std;

string plu(string num1, string num2)
{
  int i = 0, carry = 0;
  string result = "";

  while (i < num1.length() || i < num2.length())
  {
    int n1 = i < num1.length() ? num1[num1.length() - i - 1] - '0' : 0, n2 = i < num2.length() ? num2[num2.length() - i - 1] - '0' : 0;
    int sum = n1 + n2 + carry, curr = sum % 10;
    carry = sum / 10;
    result = to_string(curr) + result;
    i++;
  }

  if (carry)
  {
    result = to_string(carry) + result;
  }

  return result;
}

string multiply(string num1, int num2)
{
  int carryTs = 0, carryHs = 0, carry = 0;
  string result = "", resultTs = "", resultHs = "";

  int hn = num2 / 100;
  int tn = num2 / 10 % 10;
  int n = num2 % 10;

  for (int i = num1.length() - 1; i >= 0; --i)
  {
    int num = num1[i] - '0';

    int newNum = num * n + carry;
    carry = newNum / 10;
    int curr = newNum % 10;
    result = to_string(curr) + result;

    int newNum1 = num * tn + carryTs;
    carryTs = newNum1 / 10;
    int curr1 = newNum1 % 10;
    resultTs = to_string(curr1) + resultTs;

    int newNum2 = num * hn + carryHs;
    carryHs = newNum2 / 10;
    int curr2 = newNum2 % 10;
    resultHs = to_string(curr2) + resultHs;
  }

  if (carry)
  {
    result = to_string(carry) + result;
  }

  if (carryTs)
  {
    resultTs = to_string(carryTs) + resultTs;
  }

  if (carryHs)
  {
    resultHs = to_string(carryHs) + resultHs;
  }

  result = tn == 0 ? result : plu(result, resultTs + "0");
  result = hn == 0 ? result :  plu(result, resultHs + "00");

  return result;
}

int main()
{
  int n = 25;

  if (n == 1)
  {
    cout << "1" << "\n";
    return 0;
  }

  // cout << (multiply("25", 12)) << "\n";

  string result = "1";
  for (int i = 2; i <= n; ++i)
  {
    result = multiply(result, i);
  }

  cout << result << "\n";
  return 0;
}
