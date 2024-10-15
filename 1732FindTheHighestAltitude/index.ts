// eslint-disable-next-line @typescript-eslint/no-unused-vars
function largestAltitude(gains: number[]) {
  let currentAltitude = 0;
  let result = 0;

  for (const gain of gains) {
    currentAltitude += gain;
    result = Math.max(currentAltitude, result);
  }

  return result;
}
