# not working =----


# from functools import cmp_to_key
# def comparator(x, y):
#     if x[0] > y[0]:
#         return 1
#     else:
#         return -1

# global dp, a, b, c, ans
# a, b, c = 0, 0, 0
# ans = float("inf")

# def solve(e, h, level):
#     if e < 0 or h < 0:
#         return 999999999999
    
#     if level == n:
#         return 0
#     if dp[e][h] != -1:
#         return dp[e][h]

#     om = solve(e - 2, h, level + 1)
#     shake = solve(e, h - 3, level + 1)
#     cake = solve(e - 1, h - 1, level + 1)
    
#     dp[e][h] = min(om + a, shake + b, cake + c)
#     return dp[e][h]

def solve(n, e, h):
    if n <= 0:
        return 0
    ans = float("inf")
    if 2 * n <= e:
        ans = min(n * a, ans)
    if 3 * n <= h:
        ans = min(ans, n * b)
    if n <= e and n <= h:
        ans = min(ans, n * c)

    if (h - n) // 2 >= 1 and (h - n) // 2 >= n - e:
        print("shake and cake")
        if b < c:
            x = min(n - 1, (h - n) // 2)
            ans = min((b - c) * x + n * c, ans)
        else:
            x = max(1, n - e)
            ans = min(ans, (b - c) * x + n * c)

    if (e - n) >= 1 and (e + h) >= 2 * n:
        print("om and cake")
        
        if a < c:
            x = min(n - 1, e - n)
            ans = min((a - c) * x + n * c, ans)
        else:
            x = max(1, n - h)
            ans = min(ans, (a - c) * x + n * c)
    
    if (e // 2) >= 1 and (e // 2) >= (3 * n - h + 2) // 3:
        print("om and shake")
        
        if a < b:
            x = min(n - 1, e // 2)
            ans = min((a - b) * x + n * b, ans)
        else:
            x = max(1, (3*n - h + 2)//3)
            ans = min(ans, (a - b) * x + n * b)

    if e >= 3 and h >= 4 and n >= 3:
        print("all")
        ans = min(a + b + c + solve(n - 3, e - 3, h - 4), ans)

    # elif n > 0:
    #     return float("inf")
    return ans

for _ in range(int(input())):
    
    n, e, h, a, b, c = map(int, input().split())
    res = solve(n, e, h)
    if res == float("inf"):
        print(-1)
    else:
        print(res)

# for _ in range(int(input())):
#     n, e, h, a, b, c = map(int, input().split())
    # dp = [[-1 for j in range(h + 1)] for i in range(e + 1)]
    # print(dp)
    # ans = solve(e, h, 0)
    # if ans >= 999999999999:
    #     print(-1)
    # else:
    #     print(ans)

    # x = 0
    # l = sorted([(a, 0), (b, 1), (c, 2)], key=cmp_to_key(comparator))
    # # print(l)
    # cost = 0
    # units = 0
    # flag = False
    # for i in l:
    #     # cake
    #     # print("----")
    #     # print(units)
    #     if units >= n:
    #         flag = True
    #         break
    #     requiredUnits = n - units
    #     # print(requiredUnits)
    #     # print(cost)
    #     if i[1] == 2:
    #         # requiredUnits = n - units
    #         cakeUnits = min(e, h)
    #         if cakeUnits >= requiredUnits:
    #             cost += i[0] * requiredUnits
    #             flag = True
    #             break
    #         else:
    #             e -= cakeUnits
    #             h -= cakeUnits
    #             units += cakeUnits
    #             cost += i[0]*cakeUnits

    #     # milkshake
    #     elif i[1] == 1:
    #         # requiredUnits = n - units
    #         # shakeUnits = h % 3
    #         if h >= 3:
    #             shakeUnits = h // 3
    #             if shakeUnits >= requiredUnits:
    #                 cost += i[0] * requiredUnits
    #                 flag = True
    #                 break
    #             else:
    #                 h -= 3 * shakeUnits
    #                 units += shakeUnits
    #                 cost += i[0]*shakeUnits
    #         else:
    #             pass
            
    #     elif i[1] == 0:
    #         # requiredUnits = n - units
    #         # omUnits = e % 2
    #         if e >= 2:
    #             omUnits = e // 2
    #             if omUnits >= requiredUnits:
    #                 cost += i[0] * requiredUnits
    #                 flag = True
    #                 break
    #             else:
    #                 e -= 2 * omUnits
    #                 units += omUnits
    #                 cost += i[0]*omUnits
    #         else:
    #             pass
    
    # if flag or units >= n:
    #     print(cost)
    # else:
    #     print(-1)
