MOD = 10**9 + 7
MAXN = 2 * 100 + 1

# Precompute factorials and inverse factorials
fact = [1] * (MAXN)
inv_fact = [1] * (MAXN)

# Compute factorials
for i in range(1, MAXN):
    fact[i] = fact[i - 1] * i % MOD

# Compute modular inverses using Fermat's little theorem
inv_fact[MAXN - 1] = pow(fact[MAXN - 1], MOD - 2, MOD)
for i in range(MAXN - 2, -1, -1):
    inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD

# Compute Catalan numbers
catalan = [0] * 101
for n in range(1, 101):
    catalan[n] = fact[2 * n] * inv_fact[n] % MOD * inv_fact[n + 1] % MOD

# Print all Pn for n = 1 to 100
for n in range(1,5):
    print(f"P[{n}] = {catalan[n]}")
