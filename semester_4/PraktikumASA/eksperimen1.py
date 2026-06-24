import time
start_time = time.time()
count = 0

while time.time() - start_time < 1:
    count += 1

print(f"jumlah operasi dalam 1 detik adalah: {count:,}")