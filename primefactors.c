//unsigned long long factors[100];

int prime_factors(unsigned long long n, unsigned long long factors[]) {
    int index = 0;

    while (n % 2 == 0) {
        factors[index++] = 2;
        n /= 2;
    }

    for (unsigned long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors[index++] = i;
            n /= i;
        }
    }

    if (n > 2) {
        factors[index++] = n;
    }

    return index;
}