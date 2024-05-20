/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func helper(root *TreeNode) (int, int) {
	if root == nil {
		return 0, 0
	}
	lrob1, lrob2 := helper(root.Left)
	lmax := lrob1
	if lrob1 < lrob2 {
		lmax = lrob2
	}

	rrob1, rrob2 := helper(root.Right)
	rmax := rrob1
	if rrob1 < rrob2 {
		rmax = rrob2
	}

	rob1 := lmax + rmax
	rob2 := root.Val + lrob1 + rrob1

	return rob1, rob2
}

func rob(root *TreeNode) int {
	rob1, rob2 := helper(root)

	if rob1 > rob2 {
		return rob1
	} else {
		return rob2
	}
}