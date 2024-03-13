import numpy

a = 35
b = 47

def expand_euclidean_algorithm(a, b):
    if b == 0:
        return (a, 1, 0)
    else:
        d, x, y = expand_euclidean_algorithm(b, a % b)
        return (d, y, x - (a // b) * y)

print(expand_euclidean_algorithm(a, b))