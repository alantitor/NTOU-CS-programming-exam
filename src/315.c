/*
 * 選讀大學 
 *
 * @Author: Alan Titor
 * @Date: 2013/8/30
 */


#include <stdio.h>
#include <string.h>

int main(void)
{
	int university_number = 0;
	scanf("%d\n", &university_number);

	int index = 0;
	char university_array[10][16] = {'\0'};
	char info_array[10][36] = {'\0'};  //  use university_array to find index of info_array
	char buffer[64] = {'\0'};
	while(university_number > 0)
	{
		gets(buffer);
		int info_array_count = 0;
		char * pch = NULL;
		pch = strtok(buffer, " ");
		strcpy(university_array[index], pch);
		while((pch = strtok(NULL, " ")) != NULL)
		{
			info_array[index][info_array_count++] = pch[0];
			info_array[index][info_array_count++] = pch[1];
			info_array[index][info_array_count++] = ' ';
		}
				
		index++;
		university_number--;
	}

	//  query data
	int query_number = 0;
	scanf("%d\n", &query_number);

	int query_array[20][512] = {'\0'}
	index = 0;
	while(index < query_number)
	{
		gets(query_array[index++]);
	}


	index = 0;
	while(index < query_array)
	{
		

	}


	return 0;
}
