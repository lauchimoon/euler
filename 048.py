# 9110846700
# TODO: find a way to make this in C!
total = 0
for n in range(1, 1001):
    total += n**n

print(str(total)[::-1][:10][::-1])
