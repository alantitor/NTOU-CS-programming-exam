/*
 * 一維陣列反轉 II
 *
 * @Author: Alan Titor
 * @Date: 2013/8/30
 */


#include <stdio.h>

int main(void)
{
	int array_index = 0;
	int array_size = 6;

	int array[6] = {0};
	int buf = 0;

	int count = 5;  //  array index 
	for (count = 5; count >= 0; count--)
	{
		scanf("%d", &buf);
		array[count] = buf;
	}

	for (count = 0; count < 6; count++)
	{
		printf("%d ", array[count]);
	}

	return 0;
}
