/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func helper(head *ListNode) int {
    if (head == nil){
        return 0
    }
    r := helper(head.Next)
    m := head.Val * 2

    head.Val = m%10
    head.Val += r
    
    return m/10
}
func doubleIt(head *ListNode) *ListNode {
    r := helper(head)
    if r > 0 {
        thead := head
        head = new(ListNode)
        head.Val = r
        head.Next = thead
    }
    return head
}
