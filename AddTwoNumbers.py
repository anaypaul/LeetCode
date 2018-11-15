"""
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

def addTwoNumbers(self, l1, l2):
    """
    :type l1: ListNode
    :type l2: ListNode
    :rtype: ListNode
    """
    result = []
    head1 = l1
    head2 = l2
    carry = 0 
    while head1 and head2:
        #print("calculating sum = ",head1.val + head2.val)
        if head1.val + head2.val+carry <=9:
            result.append(head1.val + head2.val+carry)
            #print("result ->",result)
            carry = 0
        else:
            result.append((head1.val + head2.val +carry)%10)
            carry = (head1.val + head2.val + carry)//10
        head1 = head1.next
        head2 = head2.next
    while head1:
        if head1.val + carry <= 9:
            result.append(head1.val+carry)
            carry = 0
        else:
            result.append((head1.val+carry)%10)
            carry = (head1.val + carry)//10
        head1 = head1.next
    while head2:
        if head2.val + carry <= 9:
            result.append(head2.val+carry)
            carry = 0
        else:
            result.append((head2.val+carry)%10)
            carry = (head2.val + carry)//10
        head2 = head2.next
    if carry >0:
        result.append(carry)
    return result
    