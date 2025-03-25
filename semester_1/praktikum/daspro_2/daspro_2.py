#apakah origin
def origin(x, y):
    return x==0 and y==0

print (origin(1, 0))
print (origin(1, 1))
print (origin(0, 0))
print (' ')

#apakah positif
def positif(x):
    return x>0

print (positif(2))
print (positif(-2))
print (' ')

#apakah huruf A
def isA(x):
    return x=='A'

print (isA('a'))
print (isA('A'))
print (' ')

#apakah valid untuk nilai x lebih dari sama dengan 60 dan kurang dari 100
def valid(x):
    return 60<=x<100

print (valid(75))
print (valid(60))
print (valid(50))
print (' ')

#jarak dua titik
def least_square (x1, y1, x2, y2):
    return ((x2-x1)**2 + (y2-y1)**2) **0.5

print (least_square (1, 3, 4, 6))
print (least_square (3, 2, 3, 4))