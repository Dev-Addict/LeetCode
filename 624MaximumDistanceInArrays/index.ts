function maxDistance(arrays: number[][]): number {
  let minNum = Number.POSITIVE_INFINITY;
  let minIndex = 0;
  let maxNum = Number.NEGATIVE_INFINITY;
  let maxIndex = 0;
  let secondMin = Number.POSITIVE_INFINITY;
  let secondMax = Number.NEGATIVE_INFINITY;

  for (let i = 0; i < arrays.length; i++) {
    if (minNum >= arrays[i][0]) {
      secondMin = minNum;
      minNum = arrays[i][0];
      minIndex = i;
    } else if (secondMin > arrays[i][0]) secondMin = arrays[i][0];

    if (maxNum <= arrays[i][arrays[i].length - 1]) {
      secondMax = maxNum;
      maxNum = arrays[i][arrays[i].length - 1];
      maxIndex = i;
    } else if (secondMax < arrays[i][arrays[i].length - 1])
      secondMax = arrays[i][arrays[i].length - 1];
  }

  if (minIndex != maxIndex) return Math.abs(maxNum - minNum);
  return Math.max(Math.abs(secondMax - minNum), Math.abs(maxNum - secondMin));
}
