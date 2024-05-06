// Result TLE

package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func removeNodes(head *ListNode) *ListNode {
	var newHead *ListNode = nil
	var stack []*ListNode

	for head != nil {
		for (len(stack) > 0) && (stack[0].Val < head.Val) {
			stack = stack[1:]
		}
		if len(stack) == 0 {
			newHead = head
		} else {
			stack[0].Next = head
		}
		//stack = append(stack, head)
		stack = append([]*ListNode{head}, stack...)
		head = head.Next
	}
	return newHead
}
