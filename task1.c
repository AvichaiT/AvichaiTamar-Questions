#pragma warning(disable:4996)
#include <stdio.h>
#include <math.h>
#define NIBBLE_BITS 4

//set val2's to represent val1's digits by nibbles
void representNumberByNibbles(unsigned int val1, unsigned int* val2)
{
	*val2 = 0;
	int i, j;

	//add bit by bit from val1 multiplied by 10^i into val2 in order to maintain their order
	for (i = 0; val1 != 0; i++)
	{
		*val2 += (int)(val1 & 0x01) * (int)(pow(10, i));

		val1 >>= 1;
	}
}


void main()
{
	unsigned int val1, val2;

	representNumberByNibbles(0x123, &val2);

	printf("Result: %d\n", val2);
}
