q = int(input())
for _ in range(q):
    k = int(input())
    numberOfDigits = 1
    while 9 * numberOfDigits * pow(10, numberOfDigits - 1) < k:
        k -= (9 * numberOfDigits * pow(10, numberOfDigits - 1))
        numberOfDigits += 1
    currentNumber = pow(10, numberOfDigits - 1) + (
        (k // numberOfDigits) - 1 if k % numberOfDigits == 0 else k // numberOfDigits)
    k %= numberOfDigits
    if k == 0:
        k = numberOfDigits
    k -= 1
    print(str(currentNumber)[k])
