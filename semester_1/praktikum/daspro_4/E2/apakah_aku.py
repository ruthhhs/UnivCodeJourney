def apakah(x) :
    if type(x) == int :
        return "integer"
    elif type(x) == str :
        return "string"
    elif type(x) == bool :
        return "boolean"

def apakahAku(x) :
    return "Aku adalah " + apakah(x)

print(apakahAku(1000))
print(apakahAku("string"))