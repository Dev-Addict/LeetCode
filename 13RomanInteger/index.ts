const SYMBOL_TO_VALUE = {
  'I': 1,
  'V': 5,
  'X': 10,
  'L': 50,
  'C': 100,
  'D': 500,
  'M': 1000,
};

// eslint-disable-next-line @typescript-eslint/no-unused-vars
function romanToInt(s: string): number {
  if (s.length == 0)
    return 0;

  let total = SYMBOL_TO_VALUE[s[0]];
  let lastValue = SYMBOL_TO_VALUE[s[0]];

  for (let i = 1; i < s.length; i++) {
    const symbolValue = SYMBOL_TO_VALUE[s[i]];

    if (symbolValue < total) {
      total = symbolValue;
    } else if (symbolValue > lastValue) {
      total += symbolValue - 2 * lastValue;
    } else {
      total += symbolValue;
    }

    lastValue = symbolValue;
  }

  return total;
}
