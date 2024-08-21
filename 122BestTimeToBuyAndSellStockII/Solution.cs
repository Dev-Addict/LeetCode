public class Solution
{
    public int MaxProfit(int[] prices)
    {
        int totalProfit = 0;

        for (int i = 1; i < prices.Length; i++)
            totalProfit += Math.Max(0, prices[i] - prices[i - 1]);

        return totalProfit;
    }
}
