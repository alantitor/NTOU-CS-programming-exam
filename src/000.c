/*
 * 一維陣列反轉 I
 *
 * @Author: Alan Titor
 * @Date: 2013/8/30
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int input_data[1024] = {0};
	int buf = 0;
	int num_count = 0;
	int count1 = 0, count2 = 0;;

	//  read input data
	while (scanf("%d", &buf) != EOF) {
		input_data[num_count] = buf;
		num_count++;
	}

	int middle = (num_count / 2) + (num_count % 2);
	middle -= 1;  //  array index

	count1 = 0;
	count2 = num_count - 1;
	while (count1 <= middle) {
		buf = input_data[count1];
		input_data[count1] = input_data[count2];
		input_data[count2] = buf;

		count1++;
		count2--;
	}

	// print
	count1 = 0;
	while (count1 < num_count) {
		printf("%d ", input_data[count1]);
		count1++;
	}

	return 0;
}
