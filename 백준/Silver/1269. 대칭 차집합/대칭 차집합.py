import sys

_, _ = map(int, sys.stdin.readline().split())
A = list(map(int, sys.stdin.readline().split()))
B = list(map(int, sys.stdin.readline().split()))

a_dict = {}
for a in A:
    a_dict[a] = 0

overlap_count = 0
for b in B:
    if b in a_dict:
        overlap_count += 1

print(len(A) + len(B) - (2*overlap_count))