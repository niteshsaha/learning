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

##########Search Array of Unknown length: You are given an array, but you don't know the length. Write a program to find a target element in the array.

print 'Search Array of Unknown length: You are given an array, but you dont know the length'

