#include<string>
#include<vector>
using namespace std;

class Solution {
public:
  int numberOfSubstrings(string s) {
    int n = s.size();
        vector<int> prefixOnes(n + 1, 0);
        vector<int> prefixZeros(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            prefixOnes[i + 1] = prefixOnes[i] + (s[i] == '1' ? 1 : 0);
            prefixZeros[i + 1] = prefixZeros[i] + (s[i] == '0' ? 1 : 0);
        }

        int result = 0;

        for (int start = 0; start < n; ++start) 
            for (int end = start; end < n; ++end) {
                int ones = prefixOnes[end + 1] - prefixOnes[start];
                int zeros = prefixZeros[end + 1] - prefixZeros[start];
                
                if (ones >= zeros * zeros) 
                    result++;
            }

        return result;
  }
};

