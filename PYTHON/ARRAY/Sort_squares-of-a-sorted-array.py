#QUESTION :Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

#Following is the function which returns an array after squaring and sorting
def sortedSquares(nums):
        arr=[]
        for i in range (0,len(nums)):
            arr.append(nums[i]**2)
        arr.sort()
        return arr

#at leet code platform there was the array provided but here we need to take the array as input from user
num=int(input("Enter length of the array : "))
arr=[]
for i in range (0,num):
    arr.append(int(input("Enter the "+str(i)+"th item of array : ")))

#following code prints the desired oputput
print("The squared sorted array is : ")
for i in sortedSquares(arr):
    print(i,end=" ")