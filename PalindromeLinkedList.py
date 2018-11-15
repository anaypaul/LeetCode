"""
Given a singly linked list, determine if it is a palindrome.

Time Complezity : O(n) and space complexity :  O(1) 
"""# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


def isPalindrome(self, head):
    """
    :type head: ListNode
    :rtype: bool
    """
    if head == None:
        return True
    else:
        fast = head
        slow = head
        while(fast.next != None and fast.next.next!= None):
            fast = fast.next.next
            slow = slow.next
        print(slow.val)
        prev = None
        if slow.next != None:
            curr = slow.next
        else:
            return True
        #reverse the other half of the string
        while(curr!= None):
            n = curr.next
            curr.next = prev
            prev = curr
            curr = n
        slow.next = prev
        t1 = head
        t2 = slow.next
        while(t1!=None and t2!=None):
            if t1.val != t2.val:
                return False
            else:
                t1 = t1.next
                t2 = t2.next
        return True            