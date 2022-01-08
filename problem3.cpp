#include <iostream>

void factor(long long n)
{
	for (long long i = 3; i <= sqrt(n); i += 2)
	{
		while (n % i == 0)
		{
			n = n / i;
	    }
	}
	// if n at the end is a prime number.
	if (n > 2)
    std::cout << n << std::endl;
}

int main()
{
	long long n = 600851475143;
    factor(n);
return 0;
}