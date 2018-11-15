"""
Given a sorted linked list, delete all duplicates such that each element appear only once.
"""
def deleteDuplicates(self, head):
    """
    :type head: ListNode
    :rtype: ListNode
    """
    curr = head
    
    if curr == None :
        return None
    elif curr != None and curr.next == None:
        return curr
    elif curr!= None and curr.next != None:
        while(curr.next!= None):
            if curr.next!= None and curr!=None and curr.val == curr.next.val:
                while( curr.next != None and curr.val == curr.next.val ):
                    curr.next = curr.next.next
                curr.next = curr.next
            else:
                curr = curr.next
        return head