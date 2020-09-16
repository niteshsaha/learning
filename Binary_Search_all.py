#######

# All program performed in Ologn time complexity

#######

############ Binary search

def binary_search(a,target):
   end = len(a) - 1
   start = 0
   while(start <= end):
        mid = start + (end - start)/2
        if (a[mid] < target):
                start = mid +1
        elif (a[mid] > target):
                end = mid - 1
        else:
                return  a[mid]
   return -1
arry = [1,2,4,5,7,9]
result = binary_search(arry,9)

if result == -1:
        print 'Data not found'
else:
        print '(%d)Data found'%result

############## find duplicate in below array

def dup_search(a,target):
   end = len(a) - 1
   start = 0
   while(start <= end):
        mid = start + (end - start)/2
        if (a[mid] < target ):
                start = mid +1
        elif (a[mid] > target) or (a[mid] == target and a[mid] > 0 and a[mid-1] == target):
                end = mid - 1
        else:
                return mid
   return -1

print 'find duplicate in below array'
print '1,2,2,4,5,7,9'
arry1 = [1,2,2,4,5,7,9]
result = dup_search(arry1,4)
print '(%d) number at index %d'%(2,result)


###########Given a sorted array of Integers, find the target. If the target is not found, return the element closest to the target.

def record(a,mid,result,target):
    if result == -1:
        return  mid
    if (a[mid] - target) < (a[result] - target):
        return mid
    return result

def closest_val(a,target):
   end = len(a) - 1
   start = 0
   result = -1
   while(start <= end):
        mid = start + (end - start)/2
        result = record(a,mid,result,target)
        if (a[mid] < target):
                start = mid +1
        elif (a[mid] > target):
                end = mid - 1
        else:
                return  mid
   return result
print 'find the target. If the target is not found, return the element closest to the target of arry [1,2,4,5,7,8,9]'
arry3 = [1,2,4,5,7,8,9]
target = 6
res = closest_val(arry3,target)
print 'closest vlaue for target(%d) is: %d' %(target,arry3[res])


#############Given an array that is cyclically sorted, find the minimum element. A cyclically sorted array is a sorted array rotated by some number of elements. Assume all elements are unique.

def min_ele(a):
   end = len(a) - 1
   start = 0
   pivot = a[len(a) - 1]
   while(start <= end):
        mid = start + (end - start)/2
        if (a[mid] <= end) and (mid == 0 or a[mid-1] > a[mid]):
                return mid
        elif (a[mid] > right):
                start = mid +1
        else:
               end = mid - 1
   return -1

print 'ind the minimum element. A cyclically sorted array A = [4,5,1,2,3], which is just [1,2,3,4,5] rotated by 2'

arry5 = [4,5,1,2,3]
result = min_ele(arry5)
print 'min rotation required: %d'%result

try:
        print arry5[1]
except:
        print 'out of bound please check'
   
#########################
# You are given a sorted array A and a target T. Return the index where it would be placed if inserted in order.
# For example,
# A = [1,2,4,4,5,6,8] and T = 3, return index 2
# A = [1,2,4,4,5,6,8] and T = 0, return index 0
# A = [1,2,4,4,5,6,8] and T = 4, return index 4, insert after other 4
########################

print 'You are given a sorted array A and a target T. Return the index where it would be placed if inserted in order'

def findInsertionIndex(array,target):
        end = len(array) -1
        start = 0
        while (start <= end):
                mid = start + (end - start)/2
                if(array[mid] <= target):
                        if(mid == len(array) -1):
                                return len(array) -1
                        start = mid + 1
                else:
                        if mid == 0 or array[mid - 1] <= target:
                                return mid
                        end = mid -1
        return -1


arry6 = [1,2,4,4,5,6,8]
target = 3

index = findInsertionIndex(arry6,target)
print 'We can insert in position %d in arry [1,2,4,4,5,6,8]'%index


######### Search Array of Unknown length
## You are given an array, but you don't know the length. Write a program to find a target element in the array.
########

print 'Search Array of Unknown lengt'

def findTarget(a,target,start,end):
   while(start <= end):
        mid = start + (end - start)/2
        if (a[mid] < target):
                start = mid +1
        elif (a[mid] > target):
                end = mid - 1
        else:
                return  mid
   return -1

def findArrayOutofBoundRange(array, inRange,outRange):
        while(inRange<= outRange):
                mid = inRange + (outRange - inRange)/2
                try:
                        tmp = array[mid]
                except:
                        outRange = mid - 1
                        continue
                try:
                        tmp = array[mid +1]
                except:
                        return mid
                inrange = mid + 1
        return -1 # This should never happen

def targetInUnknowArrayLen(array,target):
        end = 1
        while True:
                try:
                        temp = array[end]
                except:
                        lastIndex = findArrayOutofBoundRange(array,end/2,end)
                        break
                end = (end * 2)

        return findTarget(array, target, 0 , lastIndex)

array10 = [10,1,3,4,6,7,8,9,12]
index  = targetInUnknowArrayLen(array10,7)
print 'Target found in position : %d'%index

##### Find the square root of an integer X. For example, squareRoot(4) = 2 If X is not a perfect square, find the integer floor of the square root

print 'Find the square root of an integer X. For example, squareRoot(4) = 2'

def squareRoot(num):
        start =0; end =num/2
        while start <= end:
                mid = start + (end - start)/2
                if (mid * mid) > num:
                        end = mid - 1
                elif (mid * mid) < num:
                        if ((mid + 1 ) * (mid + 1)) > num:
                                return mid
                        start = mid +1
                else:
                        return mid
        return -1

num = int(raw_input('Enter number to find the square root : '))
print 'square root of given number (%d) is  : %d'%(num, squareRoot(num))

##### Search for a Peak

print 'Search for a Peak element left and right of that element should be less than of that element'

def peakElement(array):
        low = 0; high = len(array) -1
        while low <= high:
                mid = low + (high - low)/2
                left = (mid -1) if (mid > 0) else -math.inf
                right = (mid + 1 ) if (mid < len(array) - 1) else math.inf
                print left, right
                if array[left] < array[mid] and array[mid] < array[right]:
                        low = mid +1
                elif array[left] > array[mid] and array[mid] > array[right]:
                        high = mid - 1
                elif array[left] > array[mid] and array[mid] < array[right]:
                        high = mid -1  # we can traverse in either way
                else:
                        return mid
        return -1 # This should never happen.


array11 = [1,3,4,5,2]
ele = peakElement(array11)
print 'peak element of array11 %d'%array11[ele]

