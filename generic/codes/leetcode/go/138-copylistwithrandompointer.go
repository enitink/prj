// Definition for a Node.

package main

type Node struct {
	Val    int
	Next   *Node
	Random *Node
}

func copyRandomList(head *Node) *Node {
	if head == nil {
		return nil
	}

	m := make(map[*Node]*Node)
	var newhead = new(Node)

	thead := head
	tnewhead := newhead

	for thead != nil {
		m[thead] = tnewhead
		tnewhead.Val = thead.Val
		tnewhead.Next = nil
		thead = thead.Next
		if thead != nil {
			tnewhead.Next = new(Node)
			tnewhead = tnewhead.Next
		}
	}

	thead = head
	tnewhead = newhead
	for thead != nil {
		if thead.Random == nil {
			tnewhead.Random = nil
		} else {
			tnewhead.Random = m[thead.Random]
		}
		thead = thead.Next
		tnewhead = tnewhead.Next
	}

	return newhead
}
