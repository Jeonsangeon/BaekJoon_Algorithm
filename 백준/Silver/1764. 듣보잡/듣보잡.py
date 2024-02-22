import sys

n, m = map(int, sys.stdin.readline().split())
n_set = set()
result = list()

for _ in range(n):
    n_set.add(sys.stdin.readline().strip())
for _ in range(m):
    name = sys.stdin.readline().strip()
    if name in n_set:
        result.append(name)
result.sort()
print(len(result))
for name in result:
    print(name)
