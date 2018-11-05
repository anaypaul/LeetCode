# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
def reverseList(head):
    """
    :type head: ListNode
    :rtype: ListNode
    """
    prev = None
    curr = head
    while(curr!= None):
        # print(prev,curr.val,curr.next.val)
        n = curr.next
        curr.next = prev
        prev = curr
        curr = n
    head = prev
    return head