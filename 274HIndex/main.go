package solution

import "C"

func hIndex(citations []int) int {
  n := len(citations)
  publishedOver := make([]int, n + 1)

  for _, citationNumber := range citations {
    publishedOver[min(citationNumber, n)]++
  }

  var (
    publishedOverTotal = 0
    h = 0
  )

  for i := n; i >= 0; i-- {
    publishedOverTotal += publishedOver[i];

    h = max(h, min(i, publishedOverTotal))

    if h == i {
      return h
    }
  }

  return h
}
