# 871198282
# TODO: find a way to make this in C!

def get_score(name, pos):
    sum_name = 0
    for char in name:
        sum_name += (ord(char) - 64)

    return (pos + 1)*sum_name


names = open('ext/0022_names.txt', 'r').read().split(',')
names.sort()

total = 0
for i in enumerate(names):
    idx = i[0]
    name = i[1].strip('"')
    total += get_score(name, idx)

print(total)
