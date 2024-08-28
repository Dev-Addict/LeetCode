// eslint-disable-next-line @typescript-eslint/no-unused-vars
function longestCommonPrefix(strs: string[]): string {
  let result = strs[0];

  for (let i = 1; i < strs.length; i++) {
    let newResult = "";
    const maxLength = Math.min(result.length, strs[i].length);

    for (let j = 0; j < maxLength; j++) {
      if (result[j] === strs[i][j]) {
        newResult += result[j];
      } else {
        break;
      }
    }

    result = newResult;
  }

  return result;
}
