#include <bits/stdc++.h>
using namespace std;
class Solution {
    vector<bool> eratos; 
public:
    void sieve(int right) {
        eratos[0] = false;
        eratos[1] = false;
        int i = 2;
        while (i*i <= right) {
            if (eratos[i]){
                int j = i*i;
                while (j <= right) {
                    eratos[j] = false;
                    j += i;
                }
            }
            i++;
        }
    }
    vector<int> closestPrimes(int left, int right) {
        eratos.resize(1000001);
        fill(eratos.begin(), eratos.end(), true);

        sieve(right);
        vector<int> primes(2, -1);
        int placer = 0;
        int prev = -1, diff = INT_MAX;
        for (int i = left; i <= right; i++) {
            if (eratos[i] == true) {
                if (prev != -1 && (i - prev < diff)) {
                    diff = i - prev;
                    primes[0] = prev;
                    primes[1] = i;
                }
                prev = i;
            }
            
        }

        return primes;
    }
};