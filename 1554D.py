def even(n: int) -> str: 
    s = []
    for _ in range(n // 2):
        s.append('a')
    s.append('b')
    for _ in range(n // 2 - 1):
        s.append('a')
    return ''.join(s)

def odd(n: int) -> str: 
    s = []
    for _ in range(n // 2):
        s.append('a')
    s.append('b')
    for _ in range(n // 2 - 1):
        s.append('a')
    s.append('c')
    return ''.join(s)

def main():
    t = int(input())
    for _ in range(t): 
        
        n = int(input())
        if (n == 1): 
            print("a")
            continue
        if n % 2 == 0:
            result = even(n)
        else:
            result = odd(n)
        print(result)

if __name__ == "__main__":
    main()
