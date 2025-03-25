#suhu : mengonfersi suhu x dalam derajat x ke dalam derajat y
def suhu(x, y):
    if y == "R" :
        return 4/5 * x
    elif y == "F" :
        return 9/5 * x +32
    elif y == "K" :
        return x + 273.15

print (suhu(30, "R"))
print (suhu(30, "F"))
print (suhu(30, "K"))