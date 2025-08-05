s = input()
arr = [[-1, -1] for _ in range(len(s) + 1)]
pos = []
ans = 0

for i in range(len(s)):
    if s[i] == '(':
        pos.append(i)
        continue

    if not pos:
        continue

    arr[i][0] = pos[-1]
    arr[i][1] = pos[-1]
    pos.pop()

    x = arr[i][0] - 1
    if x >= 0 and s[x] == ')' and arr[x][1] != -1:
        arr[i][1] = arr[x][1]

    ans = max(ans, i - arr[i][1] + 1)

if ans == 0:
    print("0 1")
else:
    cnt = 0
    for i in range(len(s)):
        if s[i] == '(':
            continue
        elif (arr[i][0] == -1) : 
            continue 
        if (i - arr[i][1] == ans - 1):
            cnt += 1
    print(ans, cnt)
