t = int(input())
for _ in range(t):
    n = int(input())
    words = input().split()
    # wordsSet = set(words)
    # pair = 0
    # # visited = [False for i in range(n)]
    # for i in range(n - 1):
    #     for j in range(i + 1, n):
    #         if words[i][0] != words[j][0]:
    #             st2 = words[j][0] + words[i][1:]
    #             st = words[i][0] + words[j][1:]
    #             if st not in wordsSet and st2 not in wordsSet:
    #                 print(st, st2)
    #                 pair += 2
    #                 # visited[i], visited[j] = True, True

    # print(pair)

    d = {}
    for i in range(n): 
        if words[i][1:] in d:
            d[words[i][1:]].add(words[i][0])
        else:
            d[words[i][1:]] = set()
            d[words[i][1:]].add(words[i][0])
    keys = list(d.keys())
    totalKeys = len(keys)
    ans = 0
    # loop over all keys pair wise.
    # lets say, TC: dtp ctq rts etp
    temp = ''' For this test case our dictionary(d) will look like this
    d = {
        'tp': {d, e}
        'tq': {c}
        'ts': {r}
    }
    In below loops i am looping, lets say: one outer set( {d, e} ) and all other sets are in nested loop ==> to find how many pairs like this can be formed
    1st inner iteration: "dtq ctp" & "etq ctp"        as, {d, e}tq * {c}tp
    2nd inner iteration: "dts rtp" & "ets rtp"
    NOTE: if there is any common element in both sets then we will not form pair for them.
    '''

    for i in range(totalKeys - 1):
        for j in range(i + 1, totalKeys):
            firstSetLength = len(d[keys[i]])
            secondSetLength = len(d[keys[j]])
            sameHeaders = firstSetLength - len(d[keys[i]].difference(d[keys[j]]))       # how many common elements are there.
            ans += (firstSetLength - sameHeaders)*(secondSetLength - sameHeaders)       # total possible pairs
    print(2*ans)