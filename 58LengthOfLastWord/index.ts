function lengthOfLastWord(s: string): number {
  let length = 0;
  let lastLength = 0;

  for (const c of s) {
    if (c === " ") {
      if (length !== 0) lastLength = length;
      length = 0;
    } else length++;
  }

  if (length == 0) return lastLength;
  return length;
}
