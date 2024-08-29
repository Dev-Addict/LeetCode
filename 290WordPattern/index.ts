// eslint-disable-next-line @typescript-eslint/no-unused-vars
function wordPattern(pattern: string, s: string): boolean {
  const bridge = new Map<string, string>();
  const reverseBridge = new Map<string, string>();

  let sIndex = 0;

  for (const c of pattern) {
    let word = "";

    while (s[sIndex] !== " " && sIndex < s.length) {
      word += s[sIndex];
      sIndex++;
    }

    sIndex++;

    if (word.length === 0) {
      return false;
    }

    if (bridge.has(c)) {
      if (bridge.get(c) !== word) {
        return false;
      }
    } else {
      bridge.set(c, word);
    }

    if (reverseBridge.has(word)) {
      if (reverseBridge.get(word) !== c) {
        return false;
      }
    } else {
      reverseBridge.set(word, c);
    }
  }

  if (sIndex <= s.length) {
    return false;
  }

  return true;
}
