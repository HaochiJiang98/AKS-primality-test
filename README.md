# AKS-primality-test
C++ based program

A basic implement for AKS primality algorithm. Since I use the unsigned long long date type for integers, therefore a upper bound for the input number n, should satisfies n(n-1)<2^64-1. Another constrain for n, is 2*O((log n)^5) < 2^32-1. (ie for all unsigned int n, this algorithm will give correct answer.)
