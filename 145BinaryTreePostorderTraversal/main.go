package solution

import "C"

 type TreeNode struct {
     Val int
     Left *TreeNode
     Right *TreeNode
 }

func postorderTraversal(root *TreeNode) []int {
  var result []int 

  traverse(root, &result)

  return result
}

func traverse(root *TreeNode, array *[]int) {
  if root == nil {
    return
  }

  traverse(root.Left, array)
  traverse(root.Right, array)

  *array = append(*array, root.Val)
}
