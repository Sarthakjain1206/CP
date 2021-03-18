import math
# t = int(input())

# for _ in range(t):
#     c = int(input())
#     d = 2 ** math.ceil(math.log2(c + 1))
#     # maxProd = 1

#     print((((d - 1) // 2) ^ c) * ((d - 1) // 2))
#     # for i in range(1, c):
#     #     xor = i ^ c
#     #     if xor < d:
#     #         # print(i,'*',xor,'=',i*xor)
#     #         maxProd = max(maxProd, i * xor)
#     # print(maxProd)

for _ in range(int(input())):
    C = int(input())
    minPower = 2 ** math.ceil(math.log2(C + 1))
    print((minPower - 1 >> 1)*((minPower - 1 >> 1) ^ C))