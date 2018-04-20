#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
void cb(int x[3][3], char y[3][3])/*define a function with two formal arguments to display chessboard*/
{
	int i;/*i is the row number of two-dimensional array*/
	for (i = 0; i < 3; i++){/*print the chessboard row by row*/
		printf("     #     #     \n");
		printf("  %d  #  %d  #  %d   \n", x[i][0], x[i][1], x[i][2]);
		printf("     #     #     \n");
		printf("#################\n");
	}
	printf("\n\n\n");
	for (i = 0; i < 3; i++){
		printf("     #     #     \n");
		printf("  %c  #  %c  #  %c   \n", y[i][0], y[i][1], y[i][2]);
		printf("     #     #     \n");
		printf("#################\n");
	}
}
int main(){
start:system("cls");
	int number[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	char number2[3][3] = { { '\0', '\0', '\0' }, { '\0', '\0', '\0' }, { '\0', '\0', '\0' } };
	int i, j, a1, a2;
	int b = 9;
	char again;
	cb(number, number2);/*use function cb to display chessboard*/
	for (;;){
		printf("player 1 please choose your number:");
		for (;;){
			while (!(scanf("%d", &a1) == 1 && a1 >= 1 && a1 <= 9))/*read in integer for player 1 and test it is a valid value between 1 and 9*/
			{                                                     /*if the integer is invalid, request a new input integer until a valid value is entered*/
				system("cls");/*clear the screen*/
				cb(number, number2);
				printf("Please choose your number again. it was out of range: ");
				fflush(stdin);
			}
			for (i = 0; i < 3; i++){
				for (j = 0; j < 3; j++){
					if (a1 == number[i][j]){
						if (number2[i][j] == '\0'){
							number2[i][j] = 'o';
							goto end1;
						}
						else {
							printf("this number has been chosen!please choose another one:");
						}
					}
				}
			}
			fflush(stdin);
		}
	end1:b--;
		system("cls");
		cb(number, number2);
		if (b == 0){
			goto drawn;
		}
		for (i = 0; i < 3; i++){
			for (j = 0; j < 3; j++){
				if ((number2[i][0] == number2[i][1] && number2[i][1] == number2[i][2] && number2[i][2] == 'o')
					|| (number2[0][j] == number2[1][j] && number2[1][j] == number2[2][j] && number2[2][j] == 'o')
					|| (number2[0][0] == number2[1][1] && number2[1][1] == number2[2][2] && number2[2][2] == 'o')
					|| (number2[0][2] == number2[1][1] && number2[1][1] == number2[2][0] && number2[2][0] == 'o')){
					printf("player 1, you have won this game!\n\n");
					b = 0;
					goto begin;
				}
			}
		}
		fflush(stdin);
		printf("player 2 please choose your number:");
		for (;;){
			while (!(scanf("%d", &a2) == 1 && a2 >= 1 && a2 <= 9))
			{
				system("cls");
				cb(number, number2);
				printf("Please choose your number again. it was out of range: ");
				fflush(stdin);
			}
			for (i = 0; i < 3; i++){
				for (j = 0; j < 3; j++){
					if (a2 == number[i][j]){
						if (number2[i][j] == '\0'){
							number2[i][j] = 'x';
							goto end2;
						}
						else{
							printf("this number have been chosen!please choose another one : ");
						}
					}
					else continue;
				}
			}
			fflush(stdin);
		}
	end2:b--;
		system("cls");
		cb(number, number2);
		for (i = 0; i < 3; i++){
			for (j = 0; j < 3; j++){
				if ((number2[i][0] == number2[i][1] && number2[i][1] == number2[i][2] && number2[i][2] == 'x')
					|| (number2[0][j] == number2[1][j] && number2[1][j] == number2[2][j] && number2[2][j] == 'x')
					|| (number2[0][0] == number2[1][1] && number2[1][1] == number2[2][2] && number2[2][2] == 'x')
					|| (number2[0][2] == number2[1][1] && number2[1][1] == number2[2][0] && number2[2][0] == 'x'))
				{
					printf("player 2, you have won this game!\n\n");
					b = 0;
					goto begin;
				}
			}
		}
	drawn:if (b == 0){ printf("the game is drawn!\n\n"); }
	begin:while (b == 0){
		Sleep(1000);
		printf("do you want to play again? please input 'y' if you want, and input'n'if you don't. ");
		fflush(stdin);
		scanf("%c", &again);
		if (again == 'n'){
			return(0);
		}
		else goto start;
	}
	}
}

