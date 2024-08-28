// eslint-disable-next-line @typescript-eslint/no-unused-vars
function isIsomorphic(s: string, t: string): boolean {
  const sToT: {[k: string]: string} = {};
  const tToS: {[k: string]: string} = {};

  for (let i = 0; i < s.length; i++) {
    if (sToT[s[i]]) {
      if (!tToS[t[i]]) {
        return false;
      }
      if (sToT[s[i]] != t[i] || tToS[t[i]] != s[i]) {
        return false;
      }
    } else {
      if (tToS[t[i]]) {
        return false;
      }

      sToT[s[i]] = t[i];
      tToS[t[i]] = s[i];
    }
  }

  return true;
};
