t = int(input())
lst = []
Max = 0
for _ in range(t):
    x, y = map(int, input().split())
    lst.append((x, y))
    Max = max(Max, x)
print(Max)
prime = [True for i in range(Max+1)]
dp = [0, 0, 1, 2]

# Sieve of eratosthenes
p = 2
while (p * p <= Max):
    # If prime[p] is not 
    # changed, then it is a prime
    if (prime[p] == True):

        # Update all multiples of p
        for i in range(p * p, Max + 1, p):
            prime[i] = False

    p += 1

# Storing total number of prime numbers before x
for i in range(4, Max+1):
    if prime[i]:
        dp.append(dp[i - 1] + 1)
        # dp[i] = dp[i - 1] + 1
    else:
        dp.append(dp[i - 1])
        # dp[i] = dp[i - 1]

# def findTotalPrimes(x):
#     return dp[x+1]

for i in range(t):
    x, y = lst[i][0], lst[i][1]
    if dp[x] > y:
        print("Divyam")
    else:
        print("Chef")