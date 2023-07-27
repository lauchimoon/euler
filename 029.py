# 9183
# TODO: find a way to make this in C!
lower = 2
upper = 100
terms = set()

for a in range(lower, upper + 1):
    for b in range(lower, upper + 1):
        terms.add(a**b)

nterms = len(terms)
print(nterms)
