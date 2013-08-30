/*
 * 迴文字串
 *
 * @Author: Alan Titor
 * @Date: 2013/8/30
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define array_size 260

void init_string2(char *string);

int main(void)
{
	char input_data[array_size] = {'\n'};
	int input_data_number = 0;
	int input_data_size = 0;

	scanf("%d\n", &input_data_number);


	while(input_data_number != 0)
	{
		gets(input_data);
		input_data_size = strlen(input_data);

		int count = 0;
		for(count = input_data_size; count >= 0; count-- )
			printf("%c", input_data[count]);

		printf("\n");
		init_string2(input_data);  //  init string
		input_data_number--;
	}

	return 0;
}

void init_string2(char *string)
{
	int count = 0;
	for(count = array_size; count >= 0; count--)
		string[count] = '\n';

	return ;
}
