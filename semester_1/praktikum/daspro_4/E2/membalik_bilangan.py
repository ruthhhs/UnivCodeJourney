def balikBilangan (x) :
    return (x % 10) * 1000 + ((x // 10) % 10 ) * 100 + ((x // 100) % 10) * 10 + ((x // 1000) % 10)

print (balikBilangan(1234))