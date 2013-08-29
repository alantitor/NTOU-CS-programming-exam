/*
 * used to manager problems
 *
 * @Author: Alan Titor
 * @Date: 2013/8/29
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		printf("no command,  try"-h"\n);
		exit(0);
	} else {
		//  check is init or not

		for (int count = 1; count < argc; count++) 
		{
			if (argv[i] == "-h")
				//  call help function
			else if (argv[i] == "-init")
				//  call init functin
			else if (argv[i] == "-path")
			{
				if (i + 1 != argc
					//  call set path function
				else
				{
					printf("Not enough or invalid arguments, please try again\n");
					exit(0);
				}
			}
			else if (argv[i] == "-finish")
			//  finish coding file
			else if (argv[i] == "-delete")
			//  delete file.  change status to not yet coding.

			else if (argv[i] == "-show"
			//  show all files
			//  show finished files
			//  show not finished files
			//  show not start coding files

			//  print index out to file

			else if (argv[i] == "-eliminate"
			//  delete config and index files
		}

	}

	return 0;
}
