import numpy

a = 35
b = 49

def euclidean_algorithm(a, b):
    while b:
        a, b = b, a % b
    return a

print(euclidean_algorithm(a, b))