
"""
This is the main file to invoke the methods present in the solution files to each problem based
on the need.
"""
from FindPeak import *
def main():
    # arr = [5,6,7,1,2,3,4]
    arr= []
    target = int(input())
    print("the key is present at index = ",search(arr,target))
    # print("pivot element index = ",getPivot(arr))

if __name__ == '__main__':
    main()