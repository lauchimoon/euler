# 210
# TODO: create a C solution

n = 1
limit = 200000
s = "".join([str(i) for i in range(1, limit)])
print(len(s))
indices = [10**i for i in range(7)]

for index in indices:
    n *= int(s[index - 1])

print(n)
