// eslint-disable-next-line @typescript-eslint/no-unused-vars
function isAnagram(s: string, t: string): boolean {
  const count = new Map();

  for (const c of s) {
    if (count.has(c)) {
      count.set(c, count.get(c) + 1);
    } else {
      count.set(c, 1);
    }
  }

  for (const c of t) {
    if (count.has(c)) {
      count.set(c, count.get(c) - 1);
    } else {
      return false;
    }
  }

  for (const value of count.values()) {
    if (value != 0) {
      return false;
    }
  }

  return true;
}
