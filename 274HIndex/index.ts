// eslint-disable-next-line @typescript-eslint/no-unused-vars
function hIndex(citations: number[]): number {
  const publishedOver = new Array(citations.length + 1).fill(0);

  for (const citationNumber of citations)
    ++publishedOver[Math.min(citationNumber, citations.length)];

  let publishedOverTotal = 0;
  let h = 0;

  for (let i = citations.length; i >= 0; --i) {
    publishedOverTotal += publishedOver[i];

    h = Math.max(h, Math.min(i, publishedOverTotal));

    if (h == i)
      return h;
  }

  return h;
}
