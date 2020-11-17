# Python3 implementation of worst case 
# linear time algorithm to find 
# k'th smallest element 

# Returns k'th smallest element in arr[l..r] 
# in worst case linear time. 
# ASSUMPTION: ALL ELEMENTS IN ARR[] ARE DISTINCT 

import math
def kthSmallest(arr, l, r, k): 
    
    # If k is smaller than number of 
    # elements in array 
    if (k > 0 and k <= r - l + 1): 
        
        # Number of elements in arr[l..r] 
        n = r - l + 1

        # Divide arr[] in groups of size 5, 
        # calculate median of every group 
        # and store it in median[] array. 
        median = [] 

        i = 0
        while (i < n // 5): 
            median.append(findMedian(arr, l + i * 5, 5)) 
            i += 1

        # For last group with less than 5 elements 
        if (i * 5 < n): 
            median.append(findMedian(arr, l + i * 5, 
                                            n % 5)) 
            i += 1

        # Find median of all medians using recursive call. 
        # If median[] has only one element, then no need 
        # of recursive call 
        if i == 1: 
            medOfMed = median[i - 1] 
        else: 
            medOfMed = kthSmallest(median, 0, 
                                i - 1, i // 2) 

        # Partition the array around a medOfMed 
        # element and get position of pivot 
        # element in sorted array 
        pos = partition(arr, l, r, medOfMed) 

        # If position is same as k 
        if (pos - l == k - 1): 
            return arr[pos] 
        if (pos - l > k - 1): # If position is more, 
                            # recur for left subarray 
            return kthSmallest(arr, l, pos - 1, k) 

        # Else recur for right subarray 
        return kthSmallest(arr, pos + 1, r, 
                        k - pos + l - 1) 

    # If k is more than the number of 
    # elements in the array 
    return 999999999999
    

# It searches for x in arr[l..r], 
# and partitions the array around x. 
def partition(arr, l, r, x): 
    for i in range(l, r): 
        if arr[i] == x: 
            arr[r], arr[i] = arr[i], arr[r] 
            break

    x = arr[r] 
    i = l 
    for j in range(l, r): 
        if (arr[j] <= x): 
            arr[i], arr[j] = arr[j], arr[i]  
            i += 1
    arr[r], arr[i] = arr[i], arr[r] 
    return i 

# A simple function to find 
# median of arr[] from index l to l+n 
def findMedian(arr, l, n): 
    l = sorted(l)
    if len(l) % 2 == 1:
        return l[n // 2]
    else:
        return 0.5 * (l[n // 2 - 1] + l[n // 2])


def main():

    #arr = [12, 3, 5, 7, 4, 19, 26] 
    arr = [i for i in range(1, 11)]
    print(arr)
    n = len(arr)
    k = math.ceil(n/2) 
    ans = kthSmallest(arr, 0, n - 1, k)
    if n%2 == 0:
        ans = (ans + kthSmallest(arr, 0, n - 1, k + 1)) * 0.5
    

    print("Median is", ans)

if __name__ == '__main__':
    main()
        
