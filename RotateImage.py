"""
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).
Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
"""

def rotate(matrix):
    """
    :type matrix: List[List[int]]
    :rtype: void Do not return anything, modify matrix in-place instead.
    """
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            if i < j:
                matrix[i][j] , matrix[j][i] = matrix[j][i], matrix[i][j]

    for i in range(len(matrix)):
        for j in range(len(matrix[0])//2):
            matrix[i][j], matrix[i][len(matrix[0])-1-j] = matrix[i][len(matrix[0])-1-j], matrix[i][j]

        
        
        