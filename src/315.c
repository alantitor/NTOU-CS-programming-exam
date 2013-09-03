/*
 * 選讀大學 
 *
 * @Author: Alan Titor
 * @Date: 2013/8/30
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <stdbool.h>

typedef int bool;
#define TRUE 1
#define FALSE 0


int  university_number = 0;  //  count university number
char university_array[10][16] = {'\0'};  //  save universitys name
char info_array[10][36] = {'\0'};  //  use university_array to find index of info_array.  save attributes


void search_attribute(char * src)
{
	bool flag[10];
	bool flag_buffer[10];
	int index = 0;
	for (index = 0; index < 10; index++) {
		flag[index] = 0;
	}

	//  get each query units
	char * word1 = NULL, * word2 = NULL, * brk1 = NULL, * brk2 = NULL;
	word1 = strtok_r(src, "+", &brk1);
	while (word1 != NULL) {  //  trace each query
		for (index = 0; index < 10; index++) {
			flag_buffer[index] = 1;
		}

		char tt[512] = {'\0'};
		strcpy(tt, word1);
		word2 = strtok_r(tt, " ", &brk2);
		while (word2 != NULL) {
			/*
				algorithm:
					
			*/
			for (index = 0; index < university_number; index++) {
				if (strstr(info_array[index], word2) != NULL) {
					flag_buffer[index] &= TRUE;
				} else {
					flag_buffer[index] &= FALSE;
				}
			}

			word2 = strtok_r(NULL, " ", &brk2);
		}  //  end of while
		
		//  save flag_buffer[] array data to flag[] array
		for(index = 0; index < university_number; index++) {
			flag[index] |= flag_buffer[index];
		}

		word1 = strtok_r(NULL, "+", &brk1);  //  strtok_r for level 1
	}  //  end of while


	//  pirnt result
	index = 0;
	while(index < university_number) {
		if (flag[index] == TRUE)
			printf("%s ", university_array[index]);
		index++;
	}

	printf("\n");
	return ;
}

int main(void)
{
	//int university_number = 0;  //  count university number
	scanf("%d\n", &university_number);
	//char university_array[10][16] = {'\0'};  //  save universitys name
	//char info_array[10][36] = {'\0'};  //  use university_array to find index of info_array.  save attributes

	int index = 0;
	char buffer[64] = {'\0'};  //  input buffer
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
			info_array[index][info_array_count++] = '.';
		}
				
		index++;
		university_number--;
	}
	university_number += index;  //  bad code


	//  query data
	int query_number = 0;  //  count query data number
	scanf("%d\n", &query_number);
	char query_array[20][512] = {'\0'};
	index = 0;
	char temp[512] = {'\0'};
	while(index < query_number)
	{
		gets(temp);
		strcpy(query_array[index], temp);
		index++;
	}


	index = 0;
	while(index < query_number)
	{
		search_attribute(query_array[index]);
		index++;
	}


	return 0;
}
