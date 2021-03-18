t = int(input())

# Checking time a is greater or not
def compareTime(a_hrs, a_mins, b_hrs, b_mins):
    if a_hrs > b_hrs:
        return True
    elif a_hrs == b_hrs:
        if a_mins >= b_mins:
            return True
        return False
    return False    
    
for _ in range(t):
    p = input()
    p_hrs, p_mins = int(p[:2]), int(p[3:5])
    if p[-2:] == 'AM' and p_hrs == 12:
        p_hrs = 0
    if p[-2:] == 'PM' and p_hrs != 12:
        p_hrs += 12

    n = int(input())
    output = ''
    for _ in range(n):
        x = input()
        l, r = x[:8], x[9:]
        # print(l, r)
        # l, r = input(), input()
        l_hrs, r_hrs = int(l[:2]), int(r[:2])
        l_mins, r_mins = int(l[3:5]), int(r[3:5])
        if l[-2:] == 'AM' and l_hrs == 12:
            l_hrs = 0
        if r[-2:] == 'AM' and r_hrs == 12:
            r_hrs = 0
        
        if l[-2:] == 'PM' and l_hrs != 12:
            l_hrs += 12
        if r[-2:] == 'PM' and r_hrs != 12:
            r_hrs += 12
        if compareTime(p_hrs, p_mins, l_hrs, l_mins):
            if compareTime(r_hrs, r_mins, p_hrs, p_mins):
                output += '1'
            else:
                output += '0'
        else:
            output += '0'

    print(output)

