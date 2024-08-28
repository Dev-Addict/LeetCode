// eslint-disable-next-line @typescript-eslint/no-unused-vars
function canConstruct(ransomNote: string, magazine: string): boolean {
  const count: {[k: string]: number} = {};

  for (const character of magazine) {
    if (character in count) {
      count[character]++;
    } else {
      count[character] = 1;
    }
  }

  for (const character of ransomNote) {
    if (character in count) {
      count[character]--;
    } else {
      return false;
    }
  }

  for (const value of Object.values(count)) {
    if (value < 0) {
      return false;
    }
  }

  return true;
}
