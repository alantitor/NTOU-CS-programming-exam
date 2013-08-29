/*
 * used to manager problems.
 *
 * this program is designed to the 2013 NTOU-CS-programming-exam.
 * if you want used it in future, please check parameters carefully.
 *
 * @Author: Alan Titor
 * @Date: 2013/8/29
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <GM.h>


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
				help();
			else if (argv[i] == "-init")
				init();
			else if (argv[i] == "-path")
			{
				if (i + 1 != argc)
					set_path();
				else
				{
					printf("Not enough or invalid arguments, please try again\n");
					exit(0);
				}
			}
			//  finish coding files
			else if (argv[i] == "-finish" || argv[i] == "-f")
			{
				finished_file();
			}
			//  delete file.  change status to not yet coding.
			else if (argv[i] == "-delete" || argv[i] == "-d")
			{
				delete_file();
			}
			//  show index content
			//  show all files
			//  show finished files
			//  show not finished files
			//  show not start coding files
			else if (argv[i] == "-show")
			{
				show_index();
			}
			//  print index out to file
			else if (argv[i] == "-print")
			{
				print_index();
			}
			//  delete config and index files
			else if (argv[i] == "-eliminate")
			{
				eliminate_setting();
			}
		}

	}

	return 0;
}
