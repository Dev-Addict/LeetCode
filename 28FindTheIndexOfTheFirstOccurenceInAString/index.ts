// eslint-disable-next-line @typescript-eslint/no-unused-vars
function strStr(haystack: string, needle: string): number {
  for (let i = 0; i <= haystack.length - needle.length; i++) {
    let isOccurence = true;

    for (let j = 0; j < needle.length; j++) {
      if (haystack[i + j] != needle[j]) {
        isOccurence = false;
        break;
      }
    }

    if (isOccurence)
      return i;
  }

  return -1;
}
