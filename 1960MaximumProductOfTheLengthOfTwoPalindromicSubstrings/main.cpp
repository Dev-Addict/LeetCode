#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
        long long maxProduct(string s) {
                int n = s.size();

                bool dp[n][n];
                long long result = 1;

                for (int i = 0; i < n; i++)
                        for (int j = i + 2; j < n; j += 2) {
                                dp[i][j] = true;

                                for (int k = 0; k < (j - i + 1) / 2; k++) 
                                                if (s[i + k] != s[j - k]) {
                                                        dp[i][j] = false;
                                                        break;
                                                }

                        }

                for (int firstPalindromeMaxSize = 1; firstPalindromeMaxSize < s.size(); firstPalindromeMaxSize += 2) {
                        if (firstPalindromeMaxSize * (s.size() - firstPalindromeMaxSize) < result)
                                break;

                        int firstPalindromeSize = 1;
                        int secondPalindromeSize = 1;

                        for (int i = 0; i < firstPalindromeMaxSize; i++) 
                                for (int j = i + 2; j < firstPalindromeMaxSize; j += 2)
                                        if (dp[i][j] && (j - i + 1) > firstPalindromeSize)
                                                firstPalindromeSize = j - i + 1;

                        for (int i = firstPalindromeMaxSize; i < s.size(); i++) 
                                for (int j = i + 2; j < s.size(); j += 2) 
                                        if (dp[i][j] && (j - i + 1) > secondPalindromeSize)
                                                secondPalindromeSize = j - i + 1;

                        if (firstPalindromeSize * secondPalindromeSize > result)
                                result = firstPalindromeSize * secondPalindromeSize;
                }

                return result;
        }
};

