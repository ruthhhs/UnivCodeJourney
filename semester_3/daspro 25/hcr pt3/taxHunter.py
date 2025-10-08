def TaxCollector(a :float,b :int):
    if a < 50:
        return (a*b) - (a*b)*0.15
    elif a >= 50 and a <= 150:
        return (a*b) - (a*b)*0.1
    elif a > 150 and a < 500:
        return (a*b) - (a*b)*0.05
    else:
        return (a*b)

print(TaxCollector(55.0, 8))