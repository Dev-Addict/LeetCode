package solution

import "C"

func maxProfit(prices []int) int {
  totalProfit := 0

  for i := 1; i < len(prices); i++ {
    totalProfit += max(0, prices[i] - prices[i - 1]);
  }

  return totalProfit
}
