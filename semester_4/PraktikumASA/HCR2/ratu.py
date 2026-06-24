# Ruth Septriana Sipangkar
# 24060124120024

# def ratu(n):
#     if n < 1 or n >12 or n == 2 or n == 3:
#         print("Kerajaan tidak dapat dilindungi!")
#         return

#     if n % 2 == 0:
#         m = n // 2
#         for i in range(m):
#             print(".." * i, end="")
#             print(".Q", end="")
#             print(".." * (m - i - 1), end="")
#             print("")
#         for i in range(m):
#             print(".." * i, end="")
#             print("Q.", end="")
#             print(".." * (m - i - 1), end="")
#             print("")
#     else:
#         a = (n // 2) + 1
#         b = n // 2
#         for i in range(a):
#             print(".." * i, end="")
#             print("Q", end="")
#             print(".." * (a - i - 1), end="")
#             print("")
#         for i in range(b):
#             print(".." * i, end="")
#             print(".Q", end="")
#             print(".." * (b - i - 1), end="")
#             print(".")

def ratu(n):
    if n == 2 or n == 3:
        print("Kerajaan tidak dapat dilindungi!")
        return

    board = []
    for _ in range(n):
        row = []
        for _ in range(n):
            row.append(".")
        board.append(row)
    
    coloum = set()
    diagonal1 = set()
    diagonal2 = set()

    def backtrack(r):
        # basis
        if r == n:
            return True

        for c in range(n):
            if (c in coloum or 
                (r-c) in diagonal1 or 
                (r+c) in diagonal2):
                continue

            board[r][c] = "Q"
            coloum.add(c)
            diagonal1.add(r-c)
            diagonal2.add(r+c)

            # rekursif
            if backtrack(r+1):
                return True

            board[r][c] = "."
            coloum.remove(c)
            diagonal1.remove(r-c)
            diagonal2.remove(r+c)

        return False

    if backtrack(0):
        for row in board:
            print("".join(row))
    else:
        print("Kerajaan tidak dapat dilindungi!")


# hcr
# ratu(int(input()))

ratu(0)
print(" ")
ratu(1)
print(" ")
ratu(2)
print(" ")
ratu(3)
print(" ")
ratu(4)
print(" ")
ratu(5)
print(" ")
ratu(6)
print(" ")
ratu(7)
print(" ")
ratu(8)
print(" ")
ratu(9)
print(" ")
ratu(10)
print(" ")
ratu(11)
print(" ")
ratu(12)
print(" ")
ratu(13)
print(" ")