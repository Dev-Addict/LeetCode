#include <cmath>
#include <cstdlib>
#include <numeric>
#include <string>
using namespace std;

struct fraction {
  bool isNegative;
  int numerator;
  int denominator;
};

string structToString(const fraction &f) {
  return (f.isNegative ? "-" : "") + to_string(f.numerator) + "/" +
         to_string(f.denominator);
}

class Solution {
public:
  string fractionAddition(string expression) {
    fraction result{false, 0, 1};

    fraction currentFraction{false, 0, 0};
    bool isDenominator = false;

    for (char c : expression) {
      if (c == '-' || c == '+') {
        addFractions(result, currentFraction);

        currentFraction = {c == '-', 0, 0};
        currentFraction.isNegative = c == '-';
        isDenominator = false;

        continue;
      }
      if (c == '/') {
        isDenominator = true;

        continue;
      }
      if (isDenominator) {
        currentFraction.denominator =
            currentFraction.denominator * 10 + (c - '0');

        continue;
      }

      currentFraction.numerator = currentFraction.numerator * 10 + (c - '0');
    }

    addFractions(result, currentFraction);
    simplifyFraction(result);

    return structToString(result);
  }

  void addFractions(fraction &sum, fraction &addition) {
    if (addition.numerator == 0)
      return;

    int newNumerator =
        (sum.isNegative ? -1 : 1) * sum.numerator * addition.denominator +
        (addition.isNegative ? -1 : 1) * addition.numerator * sum.denominator;

    sum.isNegative = newNumerator < 0;
    sum.numerator = abs(newNumerator);
    sum.denominator = sum.denominator * addition.denominator;
  }

  void simplifyFraction(fraction &f) {
    int greatestCommonDenominator = gcd(f.numerator, f.denominator);

    f.numerator /= greatestCommonDenominator;
    f.denominator /= greatestCommonDenominator;
  }
};
