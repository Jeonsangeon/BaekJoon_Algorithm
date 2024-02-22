S = input()
string_set = set()
for i in range(len(S)):
    for j in range(i , len(S)):
        string_set.add(S[i:j+1])

print(len(string_set))