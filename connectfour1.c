#include <stdio.h>
#include <stdlib.h>
#define BOARD_HORIZONTAL 7
#define BOARD_VERTICAL 6
#define BOARD_SIZE 7
int row[] = {1,2,3,4,5,6};
char column[] = {'A','B','C','D','E','F','G','\0'};
char endGame[] = "H";
char result;
initialization(char name1[20],char name2[20]);
acceptInput(char column[],int row[], char endGame[]);
display();
void free(int **board);

int main(){
	
	int** board;
	board = board_intialization();
	char name1[20];
	char name2[20];
	initialization();
	while(){
	player1_accept_input();
	updateState();
	player2_accept_Input();
	updateState();
	teardown();
	}
return 0;
}


//Intitalization
//allcocate space for game baord dynamically allocate the space
int** board_intialization(){  

	int** board = malloc(sizeof *board *BOARD_SIZE);
	int empty_space = 1;
	for(int i = 0; i < BOARD_SIZE; I++){
		board[i]= malloc(sizeof *board[i] * BOARD_SIZE);
		for (int k = 0; k < BOARD_SIZE; k++_{
			board[i][k] = empty_space++;
		}
	}
	return board;
}
	
initialization(char name1[20],char name2[20]){	
	puts("Welcome to Connect 4\n"
		 "Player 1 name:%s\n");
	scanf("%s", name1);
	printf("Player 2 name:%s\n");
	scanf("%s", name2);
	return name1, name2;
}

//ACCEPT INPUT
player1_accept_input(char column[], int row[],char endGame[]){
	
	printf("Enter location to drop disc A to G are columns Left to right\n");
	printf("1 to 6 are rows top to bottom ! To exit enter H ");
	scanf("%s%d%s",column, row , endGame);

	if(column == 'A','B','C','D','E','F','G'){
		printf("%s", column);
	if(row == 1 ,2 ,3 ,4 ,5 ,6){
		printf("%d", row);
}
	else{
		printf("%s", endGame);
		exit(0);
}
	return;
}
player2_accept_input(char column[], int row[],char endGame[]){
	
	printf("Enter location to drop disc A to G are columns Left to right\n");
	printf("1 to 6 are rows top to bottom ! To exit enter H ");
	scanf("%s%d%s",column, row , endGame);

	if(column == 'A','B','C','D','E','F','G'){
		printf("%s", column);
	if(row == 1 ,2 ,3 ,4 ,5 ,6){
		printf("%d", row);
}
	else{
		printf("%s", endGame);
		exit(0);
}
	return;
}
//UPDATE WORLD 
// check each column , end of game , check for win 
updateState(int** board, check_board, check_diagonal, check_rows){

int check_rows(int** board){
	int i;
	
	for (i = 0; i < BOARD_HORIZONTAL; i++){
		if (board[i][0] == board[i][1] && board[i][6] == board[i][7]){
			return 1;
		}
	}
  return 0;
}
int check_columns(int** board){
	int i;
	for (i = 0; i < BOARD_VERTICAL; i++){
		if (board[0][i] == board[1][i] && board[5][i] == board[6][i]) {
			return 1;
			}
		}
		return 0;
}
void check_board(int spot, int** board, int column, int row){
	board[row][column] = spot;
}

int check_diagonal(int** board){
	if (board[0][0] == board[1][1] && board[6][6] == board[7][7]) {
		return 1;
  } else if (board[0][3] == board[1][1] && board[2][0] == board[1][1]) {
	  return 1;
  }
  return 0;
}
int winner(int** board){
	if (check_diagonal(board) || check_rows(board) || check_columns(board)) {
    return 1;
  }
  return 0;
}

//DISPLAY
void display(int **board ,BOARD_HORIZONTAL){
	
	int row,column;
	
	for (row = 0; row < BOARD_HORIZONTAL; row++) {
		printf ("+--+---+---+---+---+---+---+");
		printf ("\n");
		
	for (column = 0; column < BOARD_VERTICAL; column++) {
		printf ("|   ");
		}
    printf("|\n");
  }
  printf ("+---+---+---+---+---+---+---+");
}	

void memory_release(int **board){ //free allocated memory 
	for(int i = 0; i < BOARD_SIZE; ++i){
		free(board[i]);
	}
	free(board);
}

// Teardown 
teardown(){
printf("End of game!");
free(memory_release);
exit(0);
}

