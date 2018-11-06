# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
def hasCycle(self, head):
    """
    :type head: ListNode
    :rtype: bool
    """
    # mydict = {}
    # curr = head
    # if curr == None:
    #     return False
    # elif curr!= None and curr.next == None:
    #     return False
    # else:
    #     mydict = {}
    #     while(curr != None):
    #         if mydict.get(curr) == None:
    #             mydict[curr] = 1
    #         else:
    #             return True
    #         curr = curr.next
    #     return False
    if(head == None or head.next == None):
        return False
    slow = head
    fast = head.next
    while(slow != fast):
        if(fast == None or fast.next == None):
            return False
        slow = slow.next
        fast = fast.next.next
    return True