# 1366
# TODO: find a way to make this in C!
n = 2**1000
sum_digits = 0

while n != 0:
    sum_digits += n % 10
    n //= 10

print(sum_digits)
