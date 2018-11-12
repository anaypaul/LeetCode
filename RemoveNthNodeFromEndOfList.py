"""
Given a linked list, remove the n-th node from the end of list and return its head.
"""
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

def removeNthFromEnd(head, n):
    """
    :type head: ListNode
    :type n: int
    :rtype: ListNode
    """
    dummy = ListNode(0)
    dummy.next = head
    first = second = dummy
    
    for i in range(n):
        first = first.next
    
    while first.next is not None:
        first = first.next
        second = second.next
    else:
        second.next = second.next.next
    
    return dummy.next