import sys
n = int(sys.stdin.readline())
num_list = list(map(int, sys.stdin.readline().split()))
num_list2 = sorted(list(set(num_list)))
dic = {num_list2[i]: i for i in range(len(num_list2))}
for j in num_list:
    print(dic[j], end=' ')