# primality.cpp
Checking some primes.

## Normal Primality Test
Is x prime?

### primality_N(x): O(N)
Checking primality by dividing x with 2 ~ x-1.

### primality_sqrtN(x): O(sqrt(N))
Checking primality by dividing x with 2 ~ sqrt(x).

## Primality for all!
Is x prime for x in 1 ~ N?

### eratosthenes(N): O(N log log N)
Using well-known "Sieve of Eratosthenes".
Assuming N >= 1.

## Prime Factorization
Factorize x.

### factorize(x): O(sqrt(N))
Dividing x with 2 ~ sqrt(x).
If divisible, then divide and proceed.