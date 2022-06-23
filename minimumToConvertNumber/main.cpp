#include <queue>
#include <vector>
#include <iostream>

int minimumOperations(std::vector<int> &nums, int start, int goal)
{
  if (start < 0 || start > 1000 || start == goal)
  {
    return start == goal ? 0 : -1;
  }

  int length = nums.size();
  int depth = 1;
  bool path[1001] = {false};
  path[start] = true;
  std::queue<int> q1;
  std::queue<int> q2;

  q1.push(start);

  while (true)
  {
    if (!q1.size())
    {
      if (!q2.size())
      {
        return -1;
      }
      q1.swap(q2);
      depth++;
    }

    const int value = q1.front();
    q1.pop();

    for (int i = 0; i < length; i++)
    {
      int v1 = value + nums[i];
      if (v1 == goal)
      {
        return depth;
      }
      if (v1 >= 0 && v1 <= 1000 && !path[v1])
      {
        path[v1] = true;
        q2.push(v1);
      }

      int v2 = value - nums[i];
      if (v2 == goal)
      {
        return depth;
      }
      if (v2 >= 0 && v2 <= 1000 && !path[v2])
      {
        path[v2] = true;
        q2.push(v2);
      }

      int v3 = value ^ nums[i];
      if (v3 == goal)
      {
        return depth;
      }
      if (v3 >= 0 && v3 <= 1000 && !path[v3])
      {
        path[v3] = true;
        q2.push(v3);
      }
    }
  }
}

void main()
{
  std::vector<int> nums = {2, 4, 12};
  int start = 2;
  int goal = 12;

  int result = minimumOperations(nums, start, goal);
  std::cout << result << "\n";
}
