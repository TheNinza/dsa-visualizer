# Python Program for insertion, deletion, traversal and searching in one dimentional array

array = []  # declaring a list called array

# Insertion - Use the insert method of lists to
# insert an element at a position, first argument is the
# position or index at which the insertion is to be done
# (0 for first, positive for rest and negative for
# going in reverse from the end, for example -1 for the last second)
# and the second argument is the value to be inserted

# use append method to add at the end or use array.insert(len(array),value)

array.insert(0, 10)
print("The array is :", array)
array.insert(0, 11)
print("The array is :", array)
array.append(12)
print("The array is :", array)
array.insert(1, 13)
print("The array is :", array)
array.insert(0, 14)
print("The array is :", array)
array.append(15)
print("The array is :", array)
array.insert(0, 16)
print("The array is :", array)

# Deletion - Use the pop method of lists to delete
# an elements from a position, the only argument is the
# position or index from which a value is to be deleted
# (0 for first, positive for rest and negative for
# going in reverse from the end, for example -1 for the last)
array.pop(0)
print("The array is :", array)
array.pop(-1)
print("The array is :", array)
array.pop(2)
print("The array is :", array)

# Searching - use in keyword to directly search for an element in a list
if 10 in array:
    print("10 found")
if 13 not in array:
    print("13 not found")

# Output:
# The array is : [10]
# The array is : [11, 10]
# The array is : [11, 10, 12]
# The array is : [11, 13, 10, 12]
# The array is : [14, 11, 13, 10, 12]
# The array is : [14, 11, 13, 10, 12, 15]
# The array is : [16, 14, 11, 13, 10, 12, 15]
# The array is : [14, 11, 13, 10, 12, 15]
# The array is : [14, 11, 13, 10, 12]
# The array is : [14, 11, 10, 12]
# 10 found
# 13 not found
