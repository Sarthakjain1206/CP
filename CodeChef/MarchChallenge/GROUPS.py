n = int(input())
for _ in range(n):
    s = input()
    start = 0
    end = -1
    flag = False
    count = 0
    for i in range(len(s)):
        if s[i] == '1' and not flag:
            flag = True
            count += 1
        elif s[i] == '1':
            continue
        else:
            flag = False
    print(count)