#include <stdio.h>
#include <stdlib.h>



int main(void)
{
	int N = 0;  //  input data number
	int row = 0, col = 0;  // row: n, col: m

	scanf("%d", &N);

	int row_count = 0;
	int col_count = 0;
	int data_count = 0;
	for (data_count = 0; data_count < N; data_count++)
	{
		scanf("%d %d", &row, &col);

		//  malloc data_array space
		char **data_array;
		data_array = (char **) malloc(row * sizeof(char *));
		for (row_count = 0; row_count < row; row_count++)
			data_array[row_count] = (char *) malloc(col * sizeof(char));
		for (row_count = 0; row_count < row; row_count++)
		{
			for (col_count = 0; col_count < col; col_count++)
			{
				data_array[row_count][col_count] = 0;
			}
		}


		//  read input data to data_array

		//  algorithm


		//  print data array content
		for (row_count = 0; row_count < row; row_count++)
		{
			for(col_count=0; col_count < col; col_count++)
			{
				printf("%d", data_array[row_count][col_count]);
				
			}
			printf("\n");
		}

	}


	return 0;
}
