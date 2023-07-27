# 648
# TODO: find a way to make this in C!
def factorial(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n*factorial(n - 1)

n = factorial(100)
sum_digits = 0

while n != 0:
    sum_digits += n%10
    n //= 10

print(sum_digits)
