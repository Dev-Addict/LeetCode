package main

import "C"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func largestValues(root *TreeNode) []int {
	var result []int

	if root == nil {
		return result
	}

	queue := []*TreeNode{root}

	for len(queue) > 0 {
		currentSize := len(queue)
		maxValue := ^(int(^uint(0) >> 1))

		for i := 0; i < currentSize; i++ {
			node := queue[0]
			queue = queue[1:]

			if node.Val > maxValue {
				maxValue = node.Val
			}

			if node.Left != nil {
				queue = append(queue, node.Left)
			}
			if node.Right != nil {
				queue = append(queue, node.Right)
			}
		}

		result = append(result, maxValue)
	}

	return result
}
