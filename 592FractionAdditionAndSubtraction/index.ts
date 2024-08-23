function gcd(a: number, b: number): number {
  if (b === 0) {
    return a;
  }
  return gcd(b, a % b);
}

type Fraction = {
  isNegative: boolean;
  numerator: number;
  denominator: number;
};

// eslint-disable-next-line @typescript-eslint/no-unused-vars
function fractionAddition(expression: string): string {
  if (expression[0] != "-")
    expression = "+" + expression;

  const fractionExpressions = expression.match(/([+-]\d+\/\d+)/g) || [];

  const result: Fraction = {isNegative: false, numerator: 0, denominator: 1};

  for (const fractionExpression of fractionExpressions) {
    const parts = fractionExpression.substring(1).split('/').map(num => +num);
    const newNumerator = (result.isNegative ? -1 : 1) * result.numerator * parts[1] + (fractionExpression[0] == '-' ? -1 : 1) * parts[0] * result.denominator;

    result.isNegative = newNumerator < 0;
    result.numerator = Math.abs(newNumerator);
    result.denominator = result.denominator * parts[1];
  }

  const greatestCommonDenominator = gcd(result.numerator, result.denominator);

  result.numerator /= greatestCommonDenominator;
  result.denominator/= greatestCommonDenominator;

  return (result.isNegative ? "-" : "") + result.numerator + "/" + result.denominator;
}
