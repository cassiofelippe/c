/* attempt to create the famous minesweeper game in C */
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void load_matrix();
void print_display(int gameover);
void randomize_bombs();
int start_game();
int user_play();
int convert_input_into_value(char v);

#define WIDTH 16
#define HEIGHT 16

int matrix[WIDTH][HEIGHT];
char rule[16] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P'};

int main() {

	int result = start_game();

	if (result) {
		printf("\nYOU LOSE! TRY AGAIN...\n");
		print_display(1);
		return 1;
	} else {
		printf("\nYOU WIN! CONGRATULATIONS!\n");
	}

	return 0;
}


int start_game() {
	load_matrix();
	randomize_bombs();

	return user_play();
}

int user_play() {
	print_display(0);

	char h_point, v_point;
	
	printf("\nChose the HORIZONTAL point: ");
	scanf("\n%c", &h_point);
	
	printf("\nChose the VERTICAL point: ");
	scanf("\n%c", &v_point);

	int h_coord = convert_input_into_value(toupper(h_point));
	int v_coord = convert_input_into_value(toupper(v_point));

	if (matrix[h_coord][v_coord]) {
		return 1;
	} else {
		matrix[h_coord][v_coord] = 2;
		return user_play();
	}
}

int convert_input_into_value(char v) {
	int i = 0;

	while (rule[i]) {
		if (rule[i] == v) {
			return i;
		}
		i++;
	}

	return -1;
}

void load_matrix() {
	int i, j;

	for (i = 0; i < WIDTH; i++) {
		for (j = 0; j < HEIGHT; j++) {
			matrix[i][j] = 0;
		}
	}
}

void print_display(int gameover) {
	int i, j;

	printf("  A B C D E F G H I J K L M N O P\n");

	for (i = 0; i < WIDTH; i++) {
		printf("%c ", rule[i]);
		for (j = 0; j < HEIGHT; j++) {
			// printf("%d ", matrix[i][j]);

			/* not bomb, not discovered */
			if (matrix[i][j] == 0 || matrix[i][j] == 1) {
				printf("%c ", '-');
			}
			
			/* bomb, discovered */
			if (matrix[i][j] == 1) {
				printf("%c ", gameover ? 'x' : '-');
				continue;
			}

			/* not bomb, discovered */
			if (matrix[i][j] == 2) {
				printf("%c ", '+');
				continue;
			}

		}

		printf("\n");
	}
}

// TODO randomize
void randomize_bombs() {
	matrix[0][9] = 1;
	matrix[1][4] = 1;
	matrix[2][8] = 1;
	matrix[3][1] = 1;
	matrix[4][4] = 1;
	matrix[5][0] = 1;
	matrix[6][9] = 1;
	matrix[7][7] = 1;
	matrix[8][15] = 1;
	matrix[9][13] = 1;
	matrix[10][1] = 1;
	matrix[11][14] = 1;
	matrix[12][7] = 1;
	matrix[13][15] = 1;
	matrix[14][8] = 1;
	matrix[15][6] = 1;
}