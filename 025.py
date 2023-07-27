# 4782
# TODO: find a way to make this in C!
first = 1
second = 1
dig = 1
i = 2
limit = 1000

while True:
    i += 1
    next_term = first + second
    first = second
    second = next_term
    dig = len(str((next_term)))
    if dig == limit:
        break

print(i)

