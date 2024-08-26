const VOWELS = ["A", "E", "I", "O", "U", "a", "e", "i", "o", "u"];

function isVowel(c: string): boolean {
  return (
    c === "a" ||
    c === "e" ||
    c === "i" ||
    c === "o" ||
    c === "u" ||
    c === "A" ||
    c === "E" ||
    c === "I" ||
    c === "O" ||
    c === "U"
  );
}

// eslint-disable-next-line @typescript-eslint/no-unused-vars
function sortVowels(s: string): string {
  const vowels = {
    A: 0,
    E: 0,
    I: 0,
    O: 0,
    U: 0,
    a: 0,
    e: 0,
    i: 0,
    o: 0,
    u: 0,
  };
  const indices: number[] = [];

  for (let i = 0; i < s.length; i++) {
    if (isVowel(s[i])) {
      ++vowels[s[i] as keyof typeof vowels];
      indices.push(i);
    }
  }

  let i = 0;

  const result = s.split('');

  for (const vowel of VOWELS) {
    while (vowels[vowel as keyof typeof vowels] > 0) {
      result[indices[i]] = vowel;
      i++;
      --vowels[vowel as keyof typeof vowels];
    }
  }

  return result.join('');
}
