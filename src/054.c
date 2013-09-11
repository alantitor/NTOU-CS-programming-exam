/*
 * 馬的跳法
 *
 * @Author: Alan Titor
 * @Date: 2013/9/5
 */


/*
 *  Problem:
 *	assume start point is (1, 1),  so we need virtual start point(0, 0) and transfer function..
 *
 *	max steps is row * col.  use it as loop bound.
 *
 *	
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//  define direction parameters
#define UUR 0
#define UUR_X  1
#define UUR_Y  2

#define URR 1
#define URR_X  2
#define URR_Y  1

#define DRR 2
#define DRR_X  2
#define DRR_Y -1

#define DDR 3
#define DDR_X  1
#define DDR_Y -2

#define DDL 4
#define DDL_X -1
#define DDL_Y -2

#define DLL 5
#define DLL_X -2
#define DLL_Y -1

#define ULL 6
#define ULL_X -2
#define ULL_Y  1

#define UUL 7
#define UUL_X -1
#define UUL_Y  2

typedef struct {
	int row;
	int col;
} coordinate;

int ** board = NULL;
int board_row = 0, board_col = 0;
int step_count = 1;
int max_steps = 0;
int eureka = 0;

//  delete
int d;

void print_board(char * message)
{
	printf("%s\n", message);

	int index_row = 0;
	int index_col = 0;

	for(index_row = 0; index_row < board_row; index_row++) {
		for(index_col = 0; index_col < board_col; index_col++) {
			printf("%5d", board[index_row][index_col]);
		}
		printf("\n");
	}

	return ;
}

bool avail_position(int coordinate_now_row, int coordinate_now_col, int * coordinate_next_row, int * coordinate_next_col, int direction)
{
	switch(direction) {
		case UUR:
			if((coordinate_now_row - 2) >= 0 && (coordinate_now_col + 1) <= (board_col - 1) && board[coordinate_now_row - 2][coordinate_now_col + 1] == -1) {
				*coordinate_next_row = coordinate_now_row - 2;
				*coordinate_next_col = coordinate_now_col + 1;
				return true;
			}
			break;
		case URR:
			if((coordinate_now_row - 1) >= 0 && (coordinate_now_col + 2) <= (board_col - 1) && board[coordinate_now_row - 1][coordinate_now_col + 2] == -1) {
				*coordinate_next_row = coordinate_now_row - 1;
				*coordinate_next_col = coordinate_now_col + 2;
				return true;
			}
			break;
		case DRR:
			if((coordinate_now_row + 1) <= (board_row - 1) && (coordinate_now_col + 2) <= (board_col - 1) && board[coordinate_now_row + 1][coordinate_now_col + 2] == -1) {
				*coordinate_next_row = coordinate_now_row + 1;
				*coordinate_next_col = coordinate_now_col + 2;
				return true;
			}
			break;
		case DDR:
			if((coordinate_now_row + 2) <= (board_row - 1) && (coordinate_now_col + 1) <= (board_col - 1) && board[coordinate_now_row + 2][coordinate_now_col + 1] == -1) {
				*coordinate_next_row = coordinate_now_row + 2;
				*coordinate_next_col = coordinate_now_col + 1;
				return true;
			}
			break;
		case DDL:
			if((coordinate_now_row + 2) <= (board_row - 1) && (coordinate_now_col - 1) >= 0 && board[coordinate_now_row + 2][coordinate_now_col - 1] == -1) {
				*coordinate_next_row = coordinate_now_row - 2;
				*coordinate_next_col = coordinate_now_col - 1;
				return true;
			}
			break;
		case DLL:
			if((coordinate_now_row + 1) <= (board_row - 1) && (coordinate_now_col - 2) >= 0 && board[coordinate_now_row + 1][coordinate_now_col - 2] == -1) {
				*coordinate_next_row = coordinate_now_row + 1;
				*coordinate_next_col = coordinate_now_col - 2;
				return true;
			}
			break;
		case ULL:
			if((coordinate_now_row - 1) >= 0 && (coordinate_now_col - 2) >= 0 && board[coordinate_now_row - 1][coordinate_now_col - 2] == -1) {
				*coordinate_next_row = coordinate_now_row - 1;
				*coordinate_next_col = coordinate_now_col - 2;
				return true;
			}
			break;
		case UUL:
			if((coordinate_now_row - 2) >= 0 && (coordinate_now_col - 1) >= 0 && board[coordinate_now_row - 2][coordinate_now_col - 1] == -1) {
				*coordinate_next_row = coordinate_now_row - 2;
				*coordinate_next_col = coordinate_now_col - 1;
				return true;
			}
			break;
		default:
			return false;
			break;
	}

	return false;
}

void trace_board(const int coordinate_now_row, const int coordinate_now_col, const int direction_come)
{
	step_count++;

	int coordinate_next_row = coordinate_now_row;
	int coordinate_next_col = coordinate_now_col;
	int direction_next = (direction_come + 1) % 8;
print_board("");//scanf("%d", &d);
	while(direction_next != direction_come) {
		if(avail_position(coordinate_now_row, coordinate_now_col, &coordinate_next_row, &coordinate_next_col, direction_next) == true) {
			board[coordinate_next_row][coordinate_next_col] = step_count;
print_board("");//scanf("%d", &d);
			trace_board(coordinate_next_row, coordinate_next_col, direction_next);
		}
printf("%d %d %d %d %d\n", coordinate_now_row, coordinate_now_col, coordinate_next_row, coordinate_next_col, direction_next);
		direction_next = (direction_next + 1) % 8;
	}

	board[coordinate_now_row][coordinate_now_col] = -1;
print_board("");//scanf("%d", &d);
	step_count--;
	return ;
}

int main(void)
{
	/*  1. get input parameters  */
	scanf("%d %d", &board_row, &board_col);
	int temp_row = 0, temp_col = 0;
	scanf("%d %d", &temp_row, &temp_col);  //  real coordinate.  we need transfer to virtual coordinate
	int coordinate_now_row = 0, coordinate_now_col = 0;
	coordinate_now_row = temp_row - 1;
	coordinate_now_col = temp_col - 1;
	max_steps = board_row * board_col;


	/*  2. create board  */
	board = (int **)malloc(board_row * sizeof(int *));
	int index_row = 0, index_col = 0;
	for(index_row = 0; index_row < board_row; index_row++) {
		board[index_row] = (int *)malloc(board_col * sizeof(int));
		for(index_col = 0; index_col < board_col; index_col++) {
			board[index_row][index_col] = -1;  //  -1 mean you can go to there
		}
	}
	print_board("init board");


	/*
	   as time gose by, I still walking.  Orz  /|_
	*/


	/*  3. start trace  */
	int direction = UUR;  //  0 ~ 7
	board[coordinate_now_row][coordinate_now_col] = step_count;
	trace_board(coordinate_now_row, coordinate_now_col, direction);



	/*  4. print resoult  */


	return 0;
}
