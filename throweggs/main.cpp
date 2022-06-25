#include <iostream>
#include <vector>

using namespace std;

// dp[k][m] = dp[k-1][m-1] + dp[k][m-1]

void main() {
  int N = 100, K = 2;

  vector<vector<int>> dp(K + 1, vector<int>(N + 1));

  int m = 0;
  
  while(dp[K][m] < N) {
    m++;

    for (int k = 1; k <= K; k++) {
      dp[k][m] = dp[k - 1][m - 1] + dp[k][m - 1] + 1;
    }
  }

  std::cout << dp[K][m] << " " << dp[K][m - 1] << "\n";
  std::cout << m << "\n";
}
