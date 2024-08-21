// eslint-disable-next-line @typescript-eslint/no-unused-vars
function maxProfit(prices: number[]): number {
  let totalProfit = 0;

  for (let i = 1; i < prices.length; i++)
    totalProfit += Math.max(0, prices[i] - prices[i - 1]);

  return totalProfit;
}
