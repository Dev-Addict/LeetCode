#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
  vector<int> closestPrimes(int left, int right) {
    vector<int> result;

    int num1 = -1, num2 = -1;

    for (int i = left; i < right; i++)
      if (isPrime(i)) {
        num1 = i;
        break;
      }

    if (num1 == -1)
        return {-1, -1};

    for (int i = num1 + 1; i <= right; i++)
      if (isPrime(i)) {
        num2 = i;
        break;
      }

    if (num2 == -1)
      return {-1, -1};

    if (num2 - num1 <= 2)
      return {num1, num2};

    int latestPrime = num2;

    for (int i = (num2 + 1) / 2 * 2 + 1; i <= right; i++)
      if (isPrime(i)) {
        if (i - latestPrime < num2 - num1) {
          num1 = latestPrime;
          num2 = i;

          if (num2 - num1 <= 2)
            return {num1, num2};
        }

        latestPrime = i;
      }

    return {num1, num2};
  }

  bool isPrime(int num) {
    if (num == 1)
      return false;
    if (num != 2 && num % 2 == 0)
         return false;
    for (int i = 3; i <= sqrt(num); i += 2)
      if (num % i == 0)
        return false;
    return true;
  }
};

