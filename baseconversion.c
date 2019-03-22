#include <stdio.h>
#include <inttypes.h>
uint64_t dec2bin(uint64_t n)
{
    if (n < 2)
    {
        return n;
    }
    else
    {
        return 10 * dec2bin(n / 2) + (n % 2);
    }
}
void main(void)
{
    uint64_t n;
    printf("Enter Base 10 Number : ");
    scanf("%"SCNd64, &n);
    printf("Binary of %"PRId64" : %"PRId64, n, dec2bin(n));
}