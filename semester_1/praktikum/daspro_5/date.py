def make_date(d,m,y):
    return [d,m,y]

def day(D):
    return D[0]

def month(D):
    return D[1]

def year(D):
    return D[2]

def isKabisat(D):
    return ((year(D) % 4 == 0) and (year(D) % 100 != 0)) or (year(D) % 400 == 0)

def dpm(D):
    if month(D) == 1:
        return 1
    elif month(D) == 2:
        return 32
    elif month(D)==3:
        return 60
    elif month(D) == 4:
        return 91
    elif month(D) == 5:
        return 121
    elif month(D) == 6:
        return 152
    elif month(D) == 7:
        return 182
    elif month(D) == 8:
        return 213
    elif month(D) == 9:
        return 244
    elif month(D) == 10:
        return 274
    elif month(D) == 11:
        return 305
    elif month(D) == 12:
        return 335

def harike1900(D):
    if month(D) > 2 and isKabisat(D):
        return dpm(D) + day(D)
    else:
        return dpm(D) + day(D) - 1

def batasHari(D):
    if month(D) == 1 or month(D)==3 or month(D)== 5 or month(D)== 7 or month(D)== 8 or month(D)== 10 or month(D)== 12:
        return 31
    elif month(D) == 2:
        return 28 + (1 if isKabisat(D) else 0)
    elif month(D) == 4 or month(D) == 6 or month(D) == 9 or month(D) == 11:
        return 30

def nextDay(D):
    if day(D) >= batasHari(D):
        if month(D) == 12:
            return make_date(1,1,year(D)+1)
        else:
            return make_date(1,month(D)+1,year(D))
    else:
        return make_date(day(D)+1,month(D),year(D))

def yesterday(D):
    if day(D) == 1:
        if month(D) == 1:
            return make_date(batasHari(make_date(day(D), month(D)-1, year(D))),12,year(D)-1)
        else:
            return make_date(batasHari(make_date(day(D), month(D)-1, year(D))),month(D)-1,year(D))
    else:
        return make_date(day(D)-1,month(D),year(D))

def isEqd(D1,D2):
    return year(D1) == year(D2) and month(D1) == month(D2) and day(D1) == day(D2)

def isBefore(D1,D2):
    if year(D1) > year(D2):
        return False
    elif month(D1) > month(D2):
        return False
    elif day(D1) > day(D2):
        return False
    else:
        return True

def isAfter(D1,D2):
    if year(D1) < year(D2):
        return False
    elif month(D1) < month(D2):
        return False
    elif day(D1) < day(D2):
        return False
    else:
        return True

print(isBefore(make_date(2,2,400), make_date(2,1,400)))