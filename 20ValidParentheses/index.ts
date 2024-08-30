// eslint-disable-next-line @typescript-eslint/no-unused-vars
function isValid(s: string, start = 0): boolean {
  if (s.length == 0) {
    return true;
  }
  if (s.length % 2 == 1) {
    return false;
  }

  for (let i = start; i < s.length - 1; i++) {
    if ((s[i] == '(' && s[i + 1] == ')') || (s[i] == '{' && s[i + 1] == '}') || (s[i] == '[' && s[i + 1] == ']')) {
      return isValid(s.substring(0, i) + s.substring(i + 2), Math.max(i - 1, 0));
    }
  }

  return false;
}
