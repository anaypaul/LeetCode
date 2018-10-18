from exp import bSearch

"""
This is the main file to invoke the methods present in the solution files to each problem based
on the need.
"""
def main():
    arr = list(map(int, input().split()))
    arr.sort()
    target = int(input())
    print(bSearch(arr, target))

if __name__ == '__main__':
    main()