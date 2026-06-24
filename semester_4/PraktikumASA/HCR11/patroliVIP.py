# Ruth Septriana Sipangkar
# 24060124120024

def patroliVIP(n, m, matriks, dp):
    # base
    if n == 0 or m == 0:
        return dp[n][m]
    
    # base
    if dp[n][m] != -1 :
        return dp[n][m]

    # niatnya mau nyari max per baris
    for i in range(n):
        maks = 0
        for j in range(m):
            # maks per baris
            if maks < matriks[i][j] :
                maks = matriks[i][j]
                dp[i][j] = maks
                jmaks = j

        # niatnya nyari kandidat terbaik
        kiriatas = matriks[i-1][jmaks-1]
        atas = matriks[i-1][jmaks]
        kananatas = matriks[i-1][jmaks+1]

        # maks dari 3 kandidat
        maks = max(kiriatas, max(atas, kananatas))

        if maks == kiriatas:
            dp[n][m] = patroliVIP(i-1, jmaks-1, matriks, dp)
        if maks == atas:
            dp[n][m] = patroliVIP(i-1, jmaks, matriks, dp)
        if maks == kananatas:
            dp[n][m] = patroliVIP(i-1, jmaks+1, matriks, dp)

    return dp[n][m]

# input
n, m = list(map(int, input().split()))
matriks = [list(map(int, input().split())) for _ in range(n)]
dp = [[-1]*m for _ in range(n)]

# output
print(patroliVIP(n, m, matriks, dp))