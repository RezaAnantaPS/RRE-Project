#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void printMenu();	//menampilkan main menu
int startGame();	//menghubungkan antar modul dalam game
void chooseRival();	//menampilkan pilihan rival
void help();		//menampilkan help/how to play
void scoreboard();	//menampilkan riwayat score dari pemain
void entryName1();	//menginputkan nama untuk pemain vs pemain
void entryName2();	//menginputkan nama untuk pemain vs Computer
void chooseDiff();	//menampilkan pilihan level bot
int botDiff();		//mengolah pilihan level bot yang diinput pemain
void chooseBoard();	//menampilkan pilihan papan
void printBoard();	//menampilkan papan
void resetBoard();	//mengosongkan papan yang akan digunakan
void playGame();	//memproses dalam permain pelayer vs player
int playerInput();	//menginputkan pilihan player
void drawScore();	//menampilkan score secara saat permainan berlangsung
int controlSOS();	//mengecek posisi pada sos
void playGameEasy();//memproses dalam permainan player vs bot easy
void playGameNormal();//memproses dalam permainan player vs bot normal
void moveComp();	//memproses bagaimana bot bergerak
int checkSpace();	//memeriksa apakah masih ada ruang kosong dalam board
int checkWinner();	//memeriksa pemenang
void drawResultPvP();	//menampilkan pemenang
void drawResultCom();
void drawWinP1();
void drawWinP2();
void drawLose();
void drawDraw();

int scores[2] = { 0,0 }; // save players scores
int currentPlayer = 0; // save current player, can be 0 or 1
char sos[9][9]; // save S and O
int sRow, sCol; // save selected row and column
char name[2][20]; // save player nicks
char winner[20];
char SO;
void gotoxy(int x, int y);
int option, board, botdiff, i, j;
int counter = 1; // round counter

int main(){
		system("mode 131, 31");
		system("cls");
		system("color D0");
		
 		printMenu();
  		if(option == 1) {
   			startGame();
		}
		else if (option == 2){
			scoreboard();
		}
		else if (option == 3){
			help();
		}
}

int startGame(){
	int rival;
	chooseRival();
   				gotoxy(17,6);scanf("%d",&rival);
				if(rival == 1) {
	   				entryName1();
	   					chooseBoard();
                           menuboard:
                           	switch(board){
                                case 1 :
                                    board = 3;
                                    resetBoard(board);
									playGame();
									break;
                                case 2 :
                                    board = 7;
                                    resetBoard(board);
									playGame();
									break;
                                case 3 :
                                    board = 9;
                                    resetBoard(board);
									playGame();
									break;
                                default :
                                    printf("\nWRONG INPUT NUMBER.\n");
                                    system("pause");
                                    goto menuboard;
                            } 
                            drawResultPvP();
	  			}else if(rival == 2){
	  				entryName2();
                        chooseBoard();
                           	switch(board){
                                case 1 :
                                    board = 3;
                                    chooseDiff();break;
                                case 2 :
                                    board = 7;
                                    chooseDiff();break;
                                case 3 :
                                    board = 9;
                                    chooseDiff();break;
                                default :
                                    printf("\nWRONG INPUT NUMBER.\n");
                                    system("pause");
                            }
                      }drawResultCom();
        printf("\nPress any key to main menu... ");
        getch();
        main();
}

void printMenu(){
	system ("cls");
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("\n%c        %c%c%c %c%c%c %c%c%c         %c",186,201,205,205,201,205,187,201,205,205,186);
    printf("\n%c        %c%c%c %c %c %c%c%c         %c",186,200,205,187,186,186,200,205,187,186);
    printf("\n%c        %c%c%c %c%c%c %c%c%c         %c",186,205,205,188,200,205,188,205,205,188,186);
    printf("\n%c               RRE-Project  %c",186,186);
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
    printf("\n%c  1. Start Game             %c",186,186);
    printf("\n%c  2. Scoreboard             %c",186,186);
    printf("\n%c  3. Help                   %c",186,186);
    printf("\n%c  4. Exit Game              %c",186,186);
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
    printf("\n%c Enter Command :            %c",186,186);
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    gotoxy(17,12);scanf("%d",&option);
}

void chooseRival(){
	system ("cls");
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("\n%c    Choose Your Rival       %c",186,186);
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
    printf("\n%c 1.PvP       %c 2.Vs Bot     %c",186,186,186);
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
    printf("\n%c Enter Command :            %c",186,186);
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
}

void entryName1(){
	system ("cls");
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("\n%c      Input Nickname        %c",186,186);
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
    printf("\n%c Player 1    %c Player 2     %c",186,186,186);
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
    printf("\n%c             %c              %c",186,186,186);
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    gotoxy(2,6);scanf("%s", &name[0][0]);
    gotoxy(16,6);scanf("%s", &name[1][0]);
}

void entryName2(){
	system("cls");
	printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("\n%c      Input Nickname        %c",186,186);
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
	printf("\n%c Player 1 :                 %c",186,186);
	printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
	gotoxy(13,4);scanf("%s", &name[0][0]);
	strcpy(name[1], "Computer");
}

void chooseBoard(){
	system ("cls");
	menuboard:
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("\n%c        Choose Board        %c",186,186);
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,205,205,185);
    printf("\n%c 1.3x3  %c 2.7x7   %c 3.9x9   %c",186,186,186,186);
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,185);
    printf("\n%c Enter Command :            %c",186,186);
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    gotoxy(17,6);scanf("%d",&board);
    
}

void printBoard(){
		// top line
		for (i = 1; i < (board + 2) * 6 + 2; i++) {
			printf("\xdb");
		}
		printf("\n\xdb\xdb ");
		for (i = 0; i <=  board; i++) {
			if (!i) printf("\xda\xc4\xc4\xc4\xc4\xc4\xc2");
			else if (i == board) printf("\xc4\xc4\xc4\xc4\xc4\xbf");
			else printf("\xc4\xc4\xc4\xc4\xc4\xc2");
		}
		// gameboard
		printf(" \xdb\xdb");
		for (i = 0; i <= board; i++) {
			printf("\n\xdb\xdb ");
			for (j = 0; j <= board; j++) {
				if (!i && !j) printf("\xb3     ");
				else if (!i && j == board) printf("\xb3 %2d  \xb3 ", j);
				else if (!i) printf("\xb3 %2d  ", j);
				else if (!j) printf("\xb3 %2d  \xb3 ", i);
				else if (sRow && sCol && sRow == i && sCol == j) printf("\xdb\xdb  \xb3 ");
				else if (sos[i - 1][j - 1] == 'S' || sos[i - 1][j - 1] == 'O') printf(" %c  \xb3 ", sos[i - 1][j - 1]);
				else printf("  %c \xb3 ", sos[i - 1][j - 1]);
			}
			printf("\xdb\xdb\n\xdb\xdb ");
			for (j = 0; j <= board; j++) {
				if (i == board && !j) printf("\xc0\xc4\xc4\xc4\xc4\xc4");
				else if (i == board) printf("\xc1\xc4\xc4\xc4\xc4\xc4");
				else if (!j) printf("\xc3\xc4\xc4\xc4\xc4\xc4");
				else printf("\xc5\xc4\xc4\xc4\xc4\xc4");
				if (i == board && j == board) printf("\xd9");
				else if (j == board) printf("\xb4");
			}
			printf(" \xdb\xdb");
		}
		// bottom line
		printf("\n");
		for (i = 1; i < (board + 2) * 6 + 2; i++) {
			printf("\xdb");
		}
}

void playGame(){
	while (counter <= board * board) {
		system("cls");
		sRow = 0; sCol = 0;
		drawScore();
		printBoard();
		int input = playerInput();
		if (input) 
		{
			int point = controlSOS();
			if (!point) {
				printf("\xaf\xaf\xaf You didn't get point! Another player's turn!");
				getch();
				currentPlayer = (currentPlayer + 1) % 2;
			}
			else {
				scores[currentPlayer] = scores[currentPlayer] + 1;
				printf("\xaf\xaf\xaf Yeay, you take point! Keep it up!");
				getch();
			}
			counter++;
		}
	}
}

int playerInput(){
	do{
		fflush(stdin);
		printf("\n\n\xaf Player turn: %s\n", name[currentPlayer]);
		printf("\xaf Row: ");
		scanf("%d", &sRow);
		printf("\xaf Column: ");
		scanf("%d", &sCol);
		if (!(sRow > 0 && sRow <= board && sCol > 0 && sCol <= board)) {
			printf("\n\n\xaf\xaf Invalid position!!\n\xaf\xaf Press any key to continue!!");
			getch();
		}
	}while(!(sRow > 0 && sRow <= board && sCol > 0 && sCol <= board));
	
	switch (sos[sRow - 1][sCol - 1]) {

	case 'S':
	case 'O':   printf("\xaf\xaf Invalid position!!\n\xaf\xaf Press any key to continue!!");
		getch();
		return 0;

	default:
		system("cls");
		drawScore();
		printBoard();
		printf("\n\n\xaf Player turn: %s\n\xaf Row: %d\n\xaf Column: %d\n\xaf\xaf S/O? ", name[currentPlayer], sRow, sCol);
		char ch;
		scanf(" %c", &ch);
		switch (ch) {
		case 's':
		case 'S': sos[sRow - 1][sCol - 1] = 'S'; return 1;
		case 'o':
		case 'O': sos[sRow - 1][sCol - 1] = 'O'; return 1;
		}

		printf("\xaf\xaf Invalid letter!!\n\xaf\xaf Press any key to continue!!");
		getch();
		return 0;
	}
}

int controlSOS() {
	if (sos[sRow - 1][sCol - 1] == 'S') {
		if (sos[sRow - 3][sCol - 3] == 'S' && sos[sRow - 2][sCol - 2] == 'O') return 1;
		if (sos[sRow - 3][sCol - 1] == 'S' && sos[sRow - 2][sCol - 1] == 'O') return 1;
		if (sos[sRow - 3][sCol + 1] == 'S' && sos[sRow - 2][sCol] == 'O') return 1;
		if (sos[sRow - 1][sCol - 3] == 'S' && sos[sRow - 1][sCol - 2] == 'O') return 1;
		if (sos[sRow - 1][sCol + 1] == 'S' && sos[sRow - 1][sCol] == 'O') return 1;
		if (sos[sRow + 1][sCol - 3] == 'S' && sos[sRow][sCol - 2] == 'O') return 1;
		if (sos[sRow + 1][sCol - 1] == 'S' && sos[sRow][sCol - 1] == 'O') return 1;
		if (sos[sRow + 1][sCol + 1] == 'S' && sos[sRow][sCol] == 'O') return 1;
	}
	else {
		if (sos[sRow - 2][sCol - 2] == 'S' && sos[sRow][sCol] == 'S') return 1;
		if (sos[sRow - 2][sCol - 1] == 'S' && sos[sRow][sCol - 1] == 'S') return 1;
		if (sos[sRow - 2][sCol] == 'S' && sos[sRow][sCol - 2] == 'S') return 1;
		if (sos[sRow - 1][sCol - 2] == 'S' && sos[sRow - 1][sCol] == 'S') return 1;
	}
	return 0;
}

void drawScore() {
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	printf("\n%c             %c              %c",186,186,186);
	printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
	printf("\n%c             %c              %c",186,186,186);
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
	gotoxy(2,1);printf("%s\n", name[0]);
	gotoxy(16,1);printf("%s\n", name[1]);
	gotoxy(2,3);printf("%d\n\n", scores[0]);
	gotoxy(16,3);printf("%d\n\n", scores[1]);
}

void chooseDiff(){
	system ("cls");
	
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("\n%c   Choose Bot Difficulity   %c",186,186);
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
    printf("\n%c  1. Easy                   %c",186,186);
    printf("\n%c  2. Normal                 %c",186,186);
    printf("\n%c  3. Hard                   %c",186,186);
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
    printf("\n%c Enter Command :            %c",186,186);
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188); 
	botDiff(botdiff);
}

int botDiff(int botdiff){
	gotoxy(18,8);scanf("%d",&botdiff);
	switch (botdiff){
		case 1 :
			resetBoard(board);
			playGameEasy();
			break;
		case 2 :
			resetBoard(board);
			playGameNormal();
			break;
		default :
			printf("\nWRONG INPUT NUMBER.\n");
            system("pause");	
	}
}

void resetBoard(int board){
	for( i=0; i < board; i++){
		for( j=0; j < board; j++){
			sos[i][j] = ' ';
		}
	}
}

int checkSpace(){
	for(sRow = 0; sRow < board; sRow++){
		for(sCol = 0; sCol < board; sCol++){
			if(sos[sRow][sCol] == ' '){
				return 0;
			}
		}
	}
	return 1;
}

void drawResultPvP(){
	system("cls");
	printf("\xaf\xaf Permainan selesai!!!! \xae\xae\n\n");
	if (scores[0] > scores[1]){
		drawWinP1();
	}
	else if (scores[0] < scores[1]){
		drawWinP2();
	}
	else 
	drawDraw();
}

void drawResultCom(){
	system("cls");
	printf("\xaf\xaf Permainan selesai!!!! \xae\xae\n\n");
	if (scores[0] > scores[1]){
		drawWinP1();
	}
	else if (scores[0] < scores[1]){
		drawLose();
	}
	else 
	drawDraw();
}

void drawLose(){
	system("cls");
	
	printf("\n|||       |||||||||  |||||||||  |||||||||     /\\     /\\");
	printf("\n|||       |||   |||  |||        |||          //\\\\   //\\\\");
	printf("\n|||       |||   |||  |||||||||  |||||||||   //  \\\\ //  \\\\");
	printf("\n|||       |||   |||        |||  |||          ___________");
	printf("\n||||||||| |||||||||  |||||||||  |||||||||  //           \\\\");
	printf("\n\n        Don't be sad, you can try again....");
	
}

void drawWinP1(){
	system("cls");
	
	printf("\n||| ||| |||  |||  |||   |||  |||   ||| |||||||||  |||||||||   **||||*||||**");
	printf("\n||| ||| |||  |||  ||||  |||  ||||  ||| |||        |||   |||   *||  1st  ||*");
	printf("\n||| ||| |||  |||  ||||| |||  ||||| ||| |||||||||  |||||||||   || You Are ||");
	printf("\n||| ||| |||  |||  |||  ||||  ||| ||||| |||        ||| |||     *|| Great ||*");
	printf("\n|||||||||||  |||  |||   |||  |||   ||| |||||||||  |||   |||   **||||_||||**");
	printf("\n\n     Congratulation, you are the winner of the game %s won with %d point!!", name[0], scores[0]);
}

void drawWinP2(){
	system("cls");
	
	printf("\n||| ||| |||  |||  |||   |||  |||   ||| |||||||||  |||||||||   **||||*||||**");
	printf("\n||| ||| |||  |||  ||||  |||  ||||  ||| |||        |||   |||   *||  1st  ||*");
	printf("\n||| ||| |||  |||  ||||| |||  ||||| ||| |||||||||  |||||||||   || You Are ||");
	printf("\n||| ||| |||  |||  |||  ||||  ||| ||||| |||        ||| |||     *|| Great ||*");
	printf("\n|||||||||||  |||  |||   |||  |||   ||| |||||||||  |||   |||   **||||_||||**");
	printf("\n\n     Congratulation, you are the winner of the game %s won with %d point!!", name[1], scores[1]);
}

void drawDraw(){
	system("cls");
	
	printf("\n                                               _____      _____");
	printf("\n||||||||| |||||||||  |||||||||  ||| ||| |||   /     \\    /     \\");
	printf("\n|||   ||| |||   |||  |||   |||  ||| ||| |||  (       )--(       )");
	printf("\n|||   ||  |||||||||  |||||||||  ||| ||| |||   \\_____/    \\_____/");
	printf("\n|||  ||   ||| |||    |||   |||  ||| ||| |||  ");
	printf("\n||||||    |||   |||  |||   |||  |||||||||||     \\\\          //");
	printf("\n                                                 \\\\________//");
	printf("\n\n        Good game, let's beat in the next game...");
	
}

void playGameEasy(){
	while (!checkSpace()){
		system("cls");
		sRow = 0; sCol = 0;
		drawScore();
		printBoard();
		if(currentPlayer == 0){
			int input = playerInput();
			if (input){
				int point = controlSOS();
				if (!point) {
					currentPlayer = (currentPlayer + 1) % 2;
				}
				else {
					scores[currentPlayer] = scores[currentPlayer] + 1;
					printf("\xaf\xaf\xaf Yeay, you take point! Keep it up!");
					getch();
				}
			}			
		}else{
			moveComp();
			int point = controlSOS();
			if(point){
				scores[currentPlayer] = scores[currentPlayer] + 1;
				printf("\n\xaf\xaf\xaf Computer fills %c on [%d][%d]\n", SO, sRow, sCol);
				getch();
				printf("\n\xaf\xaf\xaf Point for Computer");
				getch();
			}else{
				currentPlayer = (currentPlayer + 1) % 2;
				printf("\n\xaf\xaf\xaf Computer fills %c on [%d][%d]", SO, sRow, sCol);
				getch();
			}
		}
	}
	drawResultCom();
}

void playGameNormal(){
	while (!checkSpace()){
		system("cls");
		sRow = 0; sCol = 0;
		drawScore();
		printBoard();
		if(currentPlayer == 0){
			int input = playerInput();
			if (input){
				int point = controlSOS();
				if (!point) {
					currentPlayer = (currentPlayer + 1) % 2;
				}
				else {
					scores[currentPlayer] = scores[currentPlayer] + 1;
					printf("\xaf\xaf\xaf Yeay, you take point! Keep it up!");
					getch();
				}
			}			
		}else{
			moveComp();
			int point = controlSOS();
			if(point){
				scores[currentPlayer] = scores[currentPlayer] + 1;
				printf("\n\xaf\xaf\xaf Computer fills %c on [%d][%d]\n", SO, sRow, sCol);
				getch();
				printf("\n\xaf\xaf\xaf Point for Computer");
				getch();
			}else{
				currentPlayer = (currentPlayer + 1) % 2;
				printf("\n\xaf\xaf\xaf Computer fills %c on [%d][%d]", SO, sRow, sCol);
				getch();
			}
		}
	}
	drawResultCom();
}

int controlBot(){
	/*Untuk Computer menyimpan huruf O pada papan*/
	if(sos[sRow - 1][sCol - 1] == 'S' && sos[sRow - 1][sCol + 1] == 'S'){
		SO = 'O';	//kanan
		return 1;
	}else if(sos[sRow - 1][sCol - 1] == 'S' && sos[sRow - 1][sCol - 3] == 'S'){
		SO = 'O'; //kiri
		return 1;
	}else if(sos[sRow - 1][sCol - 1] == 'S' && sos[sRow + 1][sCol - 1] == 'S'){
		SO = 'O';	//bawah
		return 1;
	}else if(sos[sRow - 1][sCol - 1] == 'S' && sos[sRow - 3][sCol - 1] == 'S'){
		SO = 'O'; //atas
		return 1;
	}else if(sos[sRow - 1][sCol - 1] == 'S' && sos[sRow - 3][sCol + 1] == 'S'){
		SO = 'O'; //serong kanan atas
		return 1;
	}else if(sos[sRow - 1][sCol - 1] == 'S' && sos[sRow + 1][sCol + 1] == 'S'){
		SO = 'O'; //serong kanan bawah
		return 1;
	}else if(sos[sRow - 1][sCol - 1] == 'S' && sos[sRow + 1][sCol - 3] == 'S'){
		SO = 'O'; //serong kiri bawah
		return 1;
	}else if(sos[sRow - 1][sCol - 1] == 'S' && sos[sRow - 3][sCol - 3] == 'S'){
		SO = 'O'; //serong kiri atas
		return 1;
	}
	/*Untuk Computer menyimpan huruf S pada papan*/
	if (sos[sRow - 3][sCol - 3] == 'S' && sos[sRow - 2][sCol - 2] == 'O'){
		SO = 'S';
		return 1;	
	} 
	if (sos[sRow - 3][sCol - 1] == 'S' && sos[sRow - 2][sCol - 1] == 'O'){
		SO = 'S';
		return 1;
	} 
	if (sos[sRow - 3][sCol + 1] == 'S' && sos[sRow - 2][sCol] == 'O'){
		SO = 'S';
		return 1;	
	} 
	if (sos[sRow - 1][sCol - 3] == 'S' && sos[sRow - 1][sCol - 2] == 'O'){
		SO = 'S';
		return 1;
	} 
	if (sos[sRow - 1][sCol + 1] == 'S' && sos[sRow - 1][sCol] == 'O'){
		SO = 'S';
		return 1;	
	}
	if (sos[sRow + 1][sCol - 3] == 'S' && sos[sRow][sCol - 2] == 'O'){
		SO = 'S';
		return 1;
	} 
	if (sos[sRow + 1][sCol - 1] == 'S' && sos[sRow][sCol - 1] == 'O'){
		SO = 'S';
		return 1;
	} 
	if (sos[sRow + 1][sCol + 1] == 'S' && sos[sRow][sCol] == 'O'){
		SO = 'S';
		return 1;
	} 		
	return 0;
}

void moveComp(){
	int x;	//untuk huruf O atau s
	system("cls");
	drawScore();
	printBoard();
	srand(time(NULL));
	
	do{
		//baris kolom
		sRow = (rand() % board) + 1;
		sCol = (rand() % board) + 1;		
	}while(sos[sRow - 1][sCol - 1] != ' ');		
	if(!controlBot()){
		x = rand() % 2;
		if(x == 0){
			SO = 'O';
		}else{
			SO = 'S';
		}			
	}else {
		controlBot();
	}
	sos[sRow-1][sCol-1] = SO;
}

void scoreboard(){
	int input;
	system("cls");
	printf("\n               SCOREBOARD                   ");
	printf("\n %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,203,205,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,187);
    printf("\n %c  No  %c Tanggal %c Nama Player %c Score %c",186,186,186,186,186);
  	printf("\n %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",204,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,185);
    printf("\n %c      %c         %c             %c       %c",186,186,186,186,186);
    printf("\n %c      %c         %c             %c       %c",186,186,186,186,186);
	printf("\n %c      %c         %c             %c       %c",186,186,186,186,186);
    printf("\n %c      %c         %c             %c       %c",186,186,186,186,186);
    printf("\n %c      %c         %c             %c       %c",186,186,186,186,186);
    printf("\n %c      %c         %c             %c       %c",186,186,186,186,186);
    printf("\n %c      %c         %c             %c       %c",186,186,186,186,186);
    printf("\n %c      %c         %c             %c       %c",186,186,186,186,186);
    printf("\n %c      %c         %c             %c       %c",186,186,186,186,186);
    printf("\n %c      %c         %c             %c       %c",186,186,186,186,186);
    printf("\n %c      %c         %c             %c       %c",186,186,186,186,186);
    printf("\n %c      %c         %c             %c       %c",186,186,186,186,186);
    printf("\n %c      %c         %c             %c       %c",186,186,186,186,186);
    printf("\n %c      %c         %c             %c       %c",186,186,186,186,186);
    printf("\n %c      %c         %c             %c       %c",186,186,186,186,186);
    printf("\n %c      %c         %c             %c       %c",186,186,186,186,186);
    printf("\n %c      %c         %c             %c       %c",186,186,186,186,186);
    printf("\n %c      %c         %c             %c       %c",186,186,186,186,186);
    printf("\n %c      %c         %c             %c       %c",186,186,186,186,186);
    printf("\n %c      %c         %c             %c       %c",186,186,186,186,186);
    printf("\n %c      %c         %c             %c       %c",186,186,186,186,186);
    printf("\n %c      %c         %c             %c       %c",186,186,186,186,186);
    printf("\n %c      %c         %c             %c       %c",186,186,186,186,186);
    printf("\n %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,188);

	
	printf("\nPress any key to main menu... "); 
	getch();
	main();
}

void help(){
	system("cls");
	FILE *help = NULL;
	char input;
	char isianHelp[255];
	
	help = fopen("isianHelp.txt", "r");
	if(help == NULL){
		printf("File Doesn't Exist");
	}else {
		while(fscanf(help,"%[^\n]%*c", isianHelp) == 1){
			printf("%s\n", isianHelp);
		}
	}
	fclose(help);
	printf("\nPress any key to main menu... "); 
	getch();
	main();
}

void gotoxy(int x, int y) {
	//Mencari posisi suatu koordinat pada layar	
  	COORD coord;
  	coord.X = x;
  	coord.Y = y;
  	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


