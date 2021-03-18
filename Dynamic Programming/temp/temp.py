# # # int(input().split())

# # n, m = map(int, input().split())
# # dic = {}
# # for i in range(m):
# #     a, b = input().split()
# #     dic[a] = b

# # lst = input().split()
# # flag = False
# # output = ""

# # for i in lst:
# #     if len(i) > len(dic[i]):
# #         if not flag:
# #             output = output + dic[i]
# #             flag = True
# #         else:
# #             output = output + " " + dic[i]
# #     else:
# #         if not flag:
# #             output = output + i
# #             flag = True
# #         else:
# #             output = output + " " + i

# # print(output)


# def countSetBits(n): 
  
#     count = 0
#     while (n): 
#         n &= (n-1)  
#         count+= 1
      
#     return count
    
# # n, m, k = map(int, input().split())
# # lst = []
# # for i in range(m + 1):
# #     lst.append(int(input()))
# # count = 0
# # # x = len(bin(lst[m+1])[2:])
# # for i in range(m):
# #     num = lst[i] ^ lst[m]
# #     if countSetBits(num) <= k:
# #         count = count + 1

# # print(count)

# import math
 
# # Function to check
# # Log base 2
# def Log2(x):
#     if x == 0:
#         return False
 
#     return (math.log10(x) /
#             math.log10(2))
 
# # Function to check
# # if x is power of 2
# def isPowerOfTwo(n):
#     return (math.ceil(Log2(n)) ==
#             math.floor(Log2(n)))
# h, w = map(int, input().split())

# ratio = h / w

# if ratio >= 0.8 and ratio <= 1.25:
#     temp_h, temp_w = h, w

#     if isPowerOfTwo(h) or isPowerOfTwo(w):
#         # print(h, w)
#         pass
#     else:
#         if w == 2:
#             w = 1
#         else:
#             w = 2 ** math.floor(Log2(w))
#         ratio = h / w
#         if ratio >= 0.8 and ratio <= 1.25:
#             pass
#         else:
#             ratio = temp_h / temp_w
#             w = temp_w
#             while True:
#                 if ratio >= 0.8 and ratio <= 1.25:
#                     temp_h = h
#                     h = 2 ** math.ceil(Log2(h))
#                     ratio = h / w
#                 else:
#                     break
#             print(temp_h, w)

# while ratio < 0.8:
#     temp_h = h
#     temp_w = w
#     if w == 2:
#         w = 1
#     else:
#         w = 2 ** math.floor(Log2(w))
#     ratio = h / w

# while ratio > 1.25:
#     # print("HH")
#     temp_w = w
#     temp_h = h
#     if h == 2:
#         h = 1
#     else:
#         h = 2 ** math.floor(Log2(h))
#     ratio = h / w
# print(h, w)




# import math

# t = int(input())
# lst = list(map(int, input().split()))
# flag = False
# for num in lst:
#     # count = 0
#     hash_set = [0]*num
#     for i in range(1, num):
#         flag = True
#         # if i in hash_set:
#         #     continue
#         for j in range(i + 1, num + 1):
#             # print("H", j)
#             # if j in hash_set:
#             #     continue
#             gcd = math.gcd(i, j)
#             a, b = i // gcd, j // gcd
#             if a + b > gcd and a + gcd > b and b + gcd > a:
#                 flag = False
#                 hash_set[i-1] = 1
#                 hash_set[j - 1] = 1
#                 print(i, j)
#     print(hash_set)
#     count = 1
#     for i in range(2, num+1):
#         if hash_set[i - 1] == 0:
#             # print("hhhhh", i)
#             # print(count)
#             count += 1
#     print(count)
    # print("Hi",count)

# n = int(input())
# s = input()
# number = int(s, 2)
# def countSetBits(n): 
  
#     count = 0
#     while (n): 
#         n &= (n-1)  
#         count+= 1
      
#     return count
# maximum = countSetBits(number ^ (number >> 1))

# for i in range(1, n):
#     j = i
#     num = 0
#     while (n - j) >= 0:
#         # print(n - j)
#         num += 2 ** (n - j)
#         temp = number ^ num
#         maximum = max(maximum, countSetBits(temp ^ (temp >> 1)))
#         j += 1

# print(maximum)
# # print(int(s, 2))

from math import sqrt, floor  
# previous_start = 2
prime = [True for i in range(1000000 + 1)] 
prime[0]= False
prime[1]= False

def SieveOfEratosthenes(num, n, previous_start): 
      
    # Create a boolean array "prime[0..n]" and initialize 
    # all entries it as true. A value in prime[i] will 
    # finally be false if i is Not a prime, else true. 
    p = 2
    while (p * p <= n): 
          
        # If prime[p] is not changed, then it is a prime 
        if (prime[p] == True): 
              
            # Update all multiples of p
            if previous_start >= n:
                break
            # if previous_start < 4:
            else:
                for i in range(p*p, n + 1, p): 
                    prime[i] = False
            # else:
            #     for i in range(previous_start + (p - (previous_start%p)), n + 1, p): 
            #         prime[i] = False
              
        p += 1
    # Print all prime numbers
    count = 1
    for p in range(num+1, n + 1): 
        if prime[p]:
            count += 1  #Use print(p) for python 3
    previous_start = n
    return count, previous_start

# SieveOfEratosthenes(50)
t = int(input())
lst = list(map(int, input().split()))
previous_start = 2
for num in lst:
    ans, previous_start = SieveOfEratosthenes(floor(num ** 0.5), num, previous_start)
    print(ans)
        