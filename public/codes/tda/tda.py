# Python Program for row major and column major traversal of 2 dimentional array

n = 4
m = 5

array = [[1, 2, 3, 4, 5],
         [6, 7, 8, 9, 10],
         [11, 12, 13, 14, 15],
         [16, 17, 18, 19, 20]]


# row major traversal
print("The array in row major traversal is : [", end="")
for i in range(n):
    for j in range(m):
        print(array[i][j], end=", ")
print("]")

# column major traversal
print("The array in column major traversal is : [", end="")
for j in range(m):
    for i in range(n):
        print(array[i][j], end=", ")

print("]")

# Output:
# The array in row major traversal is : [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, ]
# The array in column major traversal is : [1, 6, 11, 16, 2, 7, 12, 17, 3, 8, 13, 18, 4, 9, 14, 19, 5, 10, 15, 20, ]
