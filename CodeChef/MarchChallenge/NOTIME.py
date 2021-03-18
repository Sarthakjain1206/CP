n, h, x = map(int, input().split())

if x + max(map(int, input().split())) >= h:
    print("YES")
else:
    print("NO")