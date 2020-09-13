# chapter 1

print 'chapter 1: why should I learn python'

x=6
y=x*7
print y

# chapter 2

print 'chapter 2: Variables, expressions, and statements'

print type('hello')

print 1,000,000

input = raw_input("please enter your desire number :")

if(int(input)):
        print 'your number is ' , input

words = {'nitesh','priyanka'}

for word in words:
        print word

# chapter 3

print 'chapter 3 Conditional execution'

input = raw_input('enter number to find even or odd: ')

if int(input)%2 == 0:
        print 'even number'
elif int(input)%2 !=0:
        print 'odd number'
else:
   print 'different number'

# chapter 4

import random

print 'chapter 4 Functions'

for i in range(10):
  x = random.random()
  print x
  x = random.randint(5,9)
  print x


        # defining new function

def myNewFunction(val):
  print 'passed value to function',val

myNewFunction(121)

# chapter 5

print 'chapter 5 Iteration'

n=5
while n > 0 and n < 10:
  print n
  n=n+1
