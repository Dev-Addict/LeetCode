package com.ariaazadipour.leetcode

class Solution {
    fun hIndex(citations: IntArray): Int {
        val publishedOver = IntArray(citations.size + 1)

        for (citationNumber in citations) {
            publishedOver[minOf(citationNumber, citations.size)] += 1
        }

        var publishedOverTotal = 0
        var h = 0

        for (i in citations.size downTo 0) {
            publishedOverTotal += publishedOver[i]

            h = maxOf(h, minOf(i, publishedOverTotal))

            if (h == i) {
                return h
            }
        }

        return h
    }
}
