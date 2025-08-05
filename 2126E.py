import math

def solve(n, p, s):
    if s[0] != p[-1]:
        print("NO")
        return

    for i in range(1, n):
        if p[i - 1] % p[i] != 0:
            print("NO")
            return

    for i in range(n - 1):
        if s[i + 1] % s[i] != 0:
            print("NO")
            return

    ans = [math.lcm(p[i], s[i]) for i in range(n)]

    for i in range(1, n):
        if math.gcd(ans[i] // p[i], p[i - 1] // p[i]) != 1:
            print("NO")
            return

    for i in range(n - 1):
        if math.gcd(ans[i] // s[i], s[i + 1] // s[i]) != 1:
            print("NO")
            return

    print("YES")


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        p = list(map(int, input().split()))
        s = list(map(int, input().split()))
        solve(n, p, s)
