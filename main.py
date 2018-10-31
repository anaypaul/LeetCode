
"""
This is the main file to invoke the methods present in the solution files to each problem based
on the need.
"""
from SearchRotatedArray import *
from RemoveDuplicatesFromSortedArray import removeDuplicates
def main():
    arr= list(map(int, input().split()))
    print(removeDuplicates(arr))
    print(arr)

if __name__ == '__main__':
    main()