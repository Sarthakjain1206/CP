from queue import Queue

st = input()
vowels = ['a', 'e', 'i', 'o', 'u']
q = Queue(maxsize=len(st))

for i in st:
    if ord(i) >= 65 and ord(i) <= 90:
        char = chr(ord(i) + 32)
        if char not in vowels:
            q.put(char)
    else:
        if i not in vowels:
            q.put(i)

output = ''
while not q.empty():
    output += '.' + q.get()

print(output)