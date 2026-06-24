# Ruth Septriana Sipangkar
# 24060124120024

def ryoikiTenai(stat, enemies, time):
    # anuin nilai awal dulu
    attack = stat[0]
    buff = stat[1]
    debuff = stat[2]

    damage = attack + (buff * time)

    # cek menang or kalah
    win = True
    for enemy in enemies:
        hp = enemy - (debuff * time)
        if damage <= hp:
            win = False

    if win:
        print("WIN")
    else:
        print("LOSE")

# hcr
# stat = list(map(int, input().split()))
# enemies = list(map(int, input().split()))
# time = int(input())
# ryoikiTenai(stat, enemies, time)

# test
s1 = [379, 47, 0, 7]
e1 = [659, 507, 598, 494, 352, 298, 504]
t1 = 9
ryoikiTenai(s1, e1, t1) # WIN

s2 = [288, 29, 43, 5]
e2 = [575, 474, 208, 100, 461]
t2 = 2
ryoikiTenai(s2, e2, t2) # LOSE