#include <iostream>
#include <cstdio>
#include <math>

bool is_prime(long& num)
{
    if (num == 2 || num == 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;

    // To check primality, we must check a number is only divisible by one and itself.
    // To do this, we could check every number under num. However it turns out that you only need to check up to the sqrt of num
    // Additionally, you only need to check the primes up to sqrt num, but since we don't have a list of primes we can't
    // do this, instead we utilize the fact that each prime (besides 2 or 3) must be one above or 1 below a multiple of 6

    // NOTE: if you check i - 1 < sqrt(num) then you have a false positive on any num = p^2 where p is some prime 6n-1
    // Think checking 25, sqrt 25 is 5, 6 - 1 !< 5 so we return true, when we should return false.
    for (long i = 6; i*i <= num; i+=6){
        if (num % (i - 1) == 0) {
            return false;
        }
        if (num % (i + 1) == 0) {
            return false;
        }
    }

    return true;
}

int main()
{
    long startVal, endVal;
    printf("Enter starting value: ");
    std::cin >> startVal;
    printf("Enter end value: ");
    std::cin >> endVal;

    // Only start at values of 2 or greater
    for (long i = startVal < 2 ? startVal : 2; i < endVal; ++i){
        if (is_prime(i))
            printf("%d is Prime\n", i);
    }

    return 0;
}