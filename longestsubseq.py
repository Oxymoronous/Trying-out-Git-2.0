#function below is to find the longest common subseq between two strings
#the recurrence relation is to recursively remove the last element from each string
#length of str1 = 7
#length of str2 = 6
def longestsubseq(str1, str2, i, j):
    #i and j start counting from the final position
    if (i <= -8 or j <=-7):
        empty = ''
        return empty
    last1 = str1[i]
    last2 = str2[j]
    if (last1 == last2):
        return (longestsubseq(str1, str2, i-1, j-1) + last1)
    else:
        return (max(longestsubseq(str1, str2, i-1, j), longestsubseq(str1, str2, i, j-1)))
if __name__ == '__main__':

    arr1 = ['a', 'b', 'c', 'b', 'd', 'a', 'b']
    arr2 = ["b", "d","c", "a", "b","a"]
    print(longestsubseq(arr1, arr2, -1, -1))
