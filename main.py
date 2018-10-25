
"""
This is the main file to invoke the methods present in the solution files to each problem based
on the need.
"""
from SearchRotatedArray import *
def main():
    arr= list(map(int, input().split()))
    target = int(input())
    print("the key is present at index = ",search(arr,target))

if __name__ == '__main__':
    main()