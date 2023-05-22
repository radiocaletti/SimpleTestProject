print("Hello, this is Python.")

import hashlib

algos = hashlib.algorithms_available
for algo in algos:
    print(algo)

sha256hash = hashlib.sha256()
sha256hash.update(b"hello")
#print(sha256hash.digest())
print(sha256hash.hexdigest())