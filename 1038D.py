n = int(input()); 


M = [0 for i in range(n + 1)]
m = [0 for i in range(n + 1)]

arr = list(map(int, input().split()))

ps = 0
m[0] = arr[0]
M[0] = arr[0]
ps += arr[0]

for i in range(1, n): 
    m[i] = min(arr[i] - M[i - 1], m[i - 1] - arr[i])
    M[i] = max(M[i - 1] - arr[i], arr[i] - m[i - 1])
    
    M[i] = max(arr[i] - ps, M[i])
    M[i] = max(ps - arr[i], M[i])
    
    m[i] = min(ps - arr[i], m[i])
    m[i] = min(arr[i] - ps, m[i])
    
    
    ps += arr[i]
    
print(M[n - 1]) 