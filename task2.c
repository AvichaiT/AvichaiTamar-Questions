#include <stdio.h>
#include <math.h>
#define NIBBLE_BITS 4

//create a representing deciaml value for a hexa decimal number
void representHexaByDecimal(unsigned int val1, unsigned int* val2)
{
	*val2 = 0;
	int i;
	//add nibble by nibble to val2 from val1 multilied by 10^i
	for (i = 0;val1 != 0;i++)
	{
		*val2 += (int)(val1 & 0x0F)*(int)(pow(10, i));
		val1 >>= NIBBLE_BITS;
	}
}

void main()
{
	unsigned int val1, val2;
	val1 = 0x1234;
	representHexaByNibbles(val1, &val2);

	printf("Decimal result: %d", val2);
}
