#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> sieveOfEratosthenes(int n) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= n; i++) 
            if (isPrime[i])
                for (int j = i * i; j <= n; j += i) 
                    isPrime[j] = false;
        return isPrime;
    }
    int countPrimes(int n) {
        vector<bool>sieve = sieveOfEratosthenes(n);
        int count = 0;
        for(int i = 2; i < n; i++) {
            count += int(sieve[i]);
        }
        return count;
    }
};