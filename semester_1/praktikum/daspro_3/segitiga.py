def is_segitiga(a, b, c) :
    if (a+b>c) and (a+c>b) and (b+c>a) :
        return "segitiga"
    else: return "bukan segitiga"

print (is_segitiga(3, 4, 5))
print (is_segitiga(1, 1, 100))