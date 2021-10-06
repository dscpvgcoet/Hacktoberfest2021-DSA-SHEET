
'''
QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot. There are many different versions of quickSort that pick pivot in different ways.
Always pick first element as pivot.
Always pick last element as pivot (implemented below)
Pick a random element as pivot.
Pick median as pivot.

The key process in quickSort is partition(). Target of partitions is, given an array and an element x of array as pivot, put x at its correct position in sorted array and put all smaller elements (smaller than x) before x, and put all greater elements (greater than x) after x. All this should be done in linear time
'''
def swap(x,y):
    temp = arr[x]
    arr[x] = arr[y]
    arr[y] = temp
    return arr

def partition(arr,l,h):
    i = l-1
    pivot = arr[h]

    for j in range(l,h):
        if arr[j] <= pivot:
            i += 1
            swap(i,j)
    swap(h,i+1)
    return i+1

def quicksort(arr,l,h):
    if l<h:
        p = partition(arr,l,h)

        quicksort(arr,p+1,h)
        quicksort(arr,l,p-1)
    return arr

arr=[5,3,7,2,9,5,6]
print(quicksort(arr,0,len(arr)-1))