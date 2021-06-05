#pragma warning(disable:4996)
#include <stdio.h>

//import data from input file, calculate displacement by given time
//and velocity and export mismatches into another file
void exportCalculationErros(char filePath[])
{
	FILE *input = fopen(filePath, "r");
	//check if each file opened successfully in order to close those which opened properly
	if (input != NULL)
	{
		FILE *output = fopen("vehicle_text_errors.txt", "w");

		if (output != NULL)
		{
			int i, time, velocity, displacement;
			//skip title in file, imoprt data and have it calculated and compared with given displacement
			fscanf(input, "%*s");
			for (i = 2; !feof(input); i++)
			{
				fscanf(input, "%d%*c%d%*c%d", &time, &velocity, &displacement);

				if ((time*velocity) != (displacement / 3))
					fprintf(output, "Calculation error at line %d\n", i);
			}
			printf("File created successfully\n");
			fclose(output);
		}
		else
			printf("Could not open output file\n");

		fclose(input);
	}
	else
		printf("Could not open input file\n");
}

void main()
{
	exportCalculationErros("vehicle_text.txt");
}
