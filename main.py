
"""
This is the main file to invoke the methods present in the solution files to each problem based
on the need.
"""
from MergeTwoSortedList import *



def main():
    l1 = ListNode(1)
    l1.next = ListNode(2)
    l1.next.next = ListNode(4)

    l2 = ListNode(1)
    l2.next = ListNode(5)
    l2.next.next = ListNode(10)

    ll = mergeTwoLists(l1, l2)
    while(ll is not None):
        print(ll.val,end="->")
        ll = ll.next
    print("Null")
if __name__ == '__main__':
    main()