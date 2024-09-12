// eslint-disable-next-line @typescript-eslint/no-unused-vars
function countConsistentStrings(allowed: string, words: string[]): number {
  const allowedMap = new Array(26).fill(false);
  let count = 0;

  const aCharCode = 'a'.charCodeAt(0);

  for (const c of allowed) {
    allowedMap[c.charCodeAt(0) - aCharCode] = true;
  }

  for (const word of words) {
    let notAllowed = false;

    for (const c of word) {
      if (!allowedMap[c.charCodeAt(0) - aCharCode]) {
        notAllowed = true;
        break;
      }
    }

    count += notAllowed ? 0 : 1;
  }

  return count;
};
