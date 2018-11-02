"""
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def mergeTwoLists(l1, l2):
    """
    :type l1: ListNode
    :type l2: ListNode
    :rtype: ListNode
    """
    if (l1 is not None and l2 is not None):
        head = None
        if(l1.val < l2.val):
            head = ListNode(l1.val)
            l1 = l1.next
        else:
            head = ListNode(l2.val)
            l2 = l2.next
        x = head
        while(l1 is not None and l2 is not None):
            if l1.val <= l2.val:
                x.next = ListNode(l1.val)
                l1 = l1.next
            else:
                x.next = ListNode(l2.val)
                l2 = l2.next
            x = x.next
        while(l1 is not None):
            x.next = ListNode(l1.val)
            l1 = l1.next
            x = x.next
        while(l2 is not None):
            x.next = ListNode(l2.val)
            l2 = l2.next
            x = x.next
        return head
            
    elif(l1 is not None and l2 is None):
        return l1
    elif(l1 is None and l2 is not None):
        return l2
    else:
        return None