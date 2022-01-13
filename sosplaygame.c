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
void playGameHard();//memproses dalam permainan player vs bot hard
int findSOS_Com(int, int, char);//mencari SOS yang terbentuk pada vs computer
int findPosition();//mencari posisi kosong
void moveComp();	//memproses bagaimana bot bergerak
void moveCompHard();//memproses bagaimana bot bergerak pada mode hard
int checkSpace();	//memeriksa apakah masih ada ruang kosong dalam board
int compFindOS(); //mencari OS yang bersebelahan untuk menentukan gerakan computer selanjutnya
int compFindSS(); //mencari SS yang bersebelahan untuk menentukan gerakan computer selanjutnya
void drawResultPvP();	//memeriksa hasil dari permainan pemain vs pemain
void drawResultCom();	//memeriksa hasil dari permainan pemain vs computer
void drawWinP1();	//menampilkan Player 1 sebagai pemenang
void drawWinP2();	//menampilkan Player 2 sebagai pemenang
void drawLose();	//menampilkan apabila pemain kalah
void drawDraw();	//menampilkan apabila score akhir dari kedua pemain sama

int scores[2] = { 0,0 }; // save players scores
int currentPlayer = 0; // save current player, can be 0 or 1
char sos[9][9]; // save S and O
int sRow, sCol; // save selected row and column
char name[2][20]; // save player nicks
char SO; //diisi huruf S/O
void gotoxy(int x, int y);
int option, board, botdiff, i, j, got;
int counter = 1; // round counter

int main(){
		//menghubungkan modul modul pada fitur main menu
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
	//menghubungkan modul modul yang terdapat dalam permainan SOS yang dibuat
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
                    drawResultCom();
                }
        printf("\nPress any key to main menu... ");
        getch();
        main();
}

void printMenu(){
	//menampilkan main menu
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
	//menampilkan pilihan rival
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
	//tampilan input nama untuk pemain vs pemain
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
	//tampilan input nama untuk pemain vs computer
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
	//menampilkan pilihan ukuran board
	system ("cls");
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
		//from github https://github.com/ertrldtcu/sos-game-in-c
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
	//modul untuk memproses permainan pemain vs pemain
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
	//input dari player untuk mode pemain vs pemain 
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
	//mengecek SOS yang terbentuk
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
	//menampilkan live score saat permainan berlangsung
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
	//menampilkan pilihan tingkat kesulitan dalam vs bot
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
	//untuk memproses pilihan kesulitan hasil inputan pemain
	gotoxy(18,8);scanf("%d",&botdiff);
	menubot:
	switch (botdiff){
		case 1 :
			resetBoard(board);
			playGameEasy();
			break;
		case 2 :
			resetBoard(board);
			playGameNormal();
			break;
		case 3 :
			resetBoard(board);
			playGameHard();
			break;
		default :
			printf("\nWRONG INPUT NUMBER.\n");
            system("pause");
            goto menubot;
	}
}

void resetBoard(int board){
	//membuat board kosong sebelum permain dimulai
	for( i=0; i < board; i++){
		for( j=0; j < board; j++){
			sos[i][j] = ' ';
		}
	}
}

int checkSpace(){
	//mengecek kotak kosong pada board
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
	//memeriksa hasil dari permainan pemain vs pemain
	system("cls");
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
	//memeriksa hasil dari permainan pemain vs computer
	system("cls");
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
	//tampilan jika pemain kalah
	system("cls");
	
	printf("\n|||       |||||||||  |||||||||  |||||||||     /\\     /\\");
	printf("\n|||       |||   |||  |||        |||          //\\\\   //\\\\");
	printf("\n|||       |||   |||  |||||||||  |||||||||   //  \\\\ //  \\\\");
	printf("\n|||       |||   |||        |||  |||          ___________");
	printf("\n||||||||| |||||||||  |||||||||  |||||||||  //           \\\\");
	printf("\n\n        Don't be sad, you can try again....");
	
}

void drawWinP1(){
	//tampilan jika player 1 yang menang
	system("cls");
	
	printf("\n||| ||| |||  |||  |||   |||  |||   ||| |||||||||  |||||||||   **||||*||||**");
	printf("\n||| ||| |||  |||  ||||  |||  ||||  ||| |||        |||   |||   *||  1st  ||*");
	printf("\n||| ||| |||  |||  ||||| |||  ||||| ||| |||||||||  |||||||||   || You Are ||");
	printf("\n||| ||| |||  |||  |||  ||||  ||| ||||| |||        ||| |||     *|| Great ||*");
	printf("\n|||||||||||  |||  |||   |||  |||   ||| |||||||||  |||   |||   **||||_||||**");
	printf("\n\n     Congratulation, you are the winner of the game %s won with %d point!!", name[0], scores[0]);
}

void drawWinP2(){
	//tampilan jika player 2 yang menang
	system("cls");
	
	printf("\n||| ||| |||  |||  |||   |||  |||   ||| |||||||||  |||||||||   **||||*||||**");
	printf("\n||| ||| |||  |||  ||||  |||  ||||  ||| |||        |||   |||   *||  1st  ||*");
	printf("\n||| ||| |||  |||  ||||| |||  ||||| ||| |||||||||  |||||||||   || You Are ||");
	printf("\n||| ||| |||  |||  |||  ||||  ||| ||||| |||        ||| |||     *|| Great ||*");
	printf("\n|||||||||||  |||  |||   |||  |||   ||| |||||||||  |||   |||   **||||_||||**");
	printf("\n\n     Congratulation, you are the winner of the game %s won with %d point!!", name[1], scores[1]);
}

void drawDraw(){
	//tampilan jika score antara kedua pemain sama
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
	//memproses dalam permain vs bot easy
	scores[0]=0;
	scores[1]=0;
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
	//memproses dalam permainan vs bot normal
	scores[0]=0;
	scores[1]=0;
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

void playGameHard(){
	//memproses dalam permainan vs bot hard
	scores[0]=0;
	scores[1]=0;
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
			moveCompHard();
			}
		}
	drawResultCom();
}

int controlBot(){
	//Untuk Computer menyimpan huruf O pada papan
	//horizontal
	if(sos[sRow - 1][sCol - 1] == 'S' && sos[sRow - 1][sCol + 1] == 'S'){
		SO = 'O';
		return 1;
	}else if(sos[sRow - 1][sCol - 1] == 'S' && sos[sRow - 1][sCol - 3] == 'S'){
		SO = 'O';
		return 1;
	//vertikal
	}else if(sos[sRow - 1][sCol - 1] == 'S' && sos[sRow + 1][sCol - 1] == 'S'){
		SO = 'O';
		return 1;
	}else if(sos[sRow - 1][sCol - 1] == 'S' && sos[sRow - 3][sCol - 1] == 'S'){
		SO = 'O'; 
		return 1;
	//diagonal
	}else if(sos[sRow - 1][sCol - 1] == 'S' && sos[sRow - 3][sCol + 1] == 'S'){
		SO = 'O';
		return 1;
	}else if(sos[sRow - 1][sCol - 1] == 'S' && sos[sRow + 1][sCol + 1] == 'S'){
		SO = 'O';
		return 1;
	}else if(sos[sRow - 1][sCol - 1] == 'S' && sos[sRow + 1][sCol - 3] == 'S'){
		SO = 'O'; 
		return 1;
	}else if(sos[sRow - 1][sCol - 1] == 'S' && sos[sRow - 3][sCol - 3] == 'S'){
		SO = 'O';
		return 1;
	}
	//Input Computer huruf S
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
	//pergerakan komputer
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

int positionValid(int space){
	//memeriksa posisi yang dapat diisi computer
  	if(space>0 && space<((board*board)+1)){	
		sRow = (space-1)/board;
		sCol = (space-1)%board;

		if (sos[sRow][sCol]==' '){
			return 1;
		}
		else {
			return 0;
		} 
	}
  	else{
		return 0;	
  	}
}


int findPosition(){
	int space;
	
	for (space=1; space<((board*board)+1); space++){
		sRow = (space-1)/board;
		sCol = (space-1)%board;
		if (sos[sRow][sCol] == ' '){
			return space;
		}
	}
	return 0;
}

void moveCompHard(){
	int space;
	char SO;

  	do{
  		system("cls");
  		drawScore();
    	printBoard();
		if(compFindOS()){
			space = compFindOS();
			SO = 'S';
		}
		else if(compFindSS()){
			space = compFindSS();
			SO = 'O';
		}
		else{
			space = findPosition();
			SO = 'S';
		}
		sRow = (space-1)/board;
		sCol = (space-1)%board;
        
   		sos[sRow][sCol] = SO;
   		if(got==0){
   			if(SO == 'S'){
   				printf("\n\xaf\xaf Computer fills %c on [%d][%d] \n", SO, sRow+1, sCol+1);
				system("pause");
			}else if(SO == 'O'){
				printf("\n\xaf\xaf Computer fills %c on [%d][%d] \n", SO, sRow+1, sCol+1);
				system("pause");
			}
		}
		else if(got==1){
			system("cls");
			drawScore();
    		printBoard();
    		if(SO == 'S'){
   				printf("\n\xaf\xaf Computer fills %c on [%d][%d] \n", SO, sRow+1, sCol+1);
   				printf("\xaf\xaf\xaf I get point! \n");
				system("pause");
			}else if(SO == 'O'){
				printf("\n\xaf\xaf Computer fills %c on [%d][%d] \n", SO, sRow+1, sCol+1);
				printf("\xaf\xaf\xaf I get point! \n");
				system("pause");
			}
		}
   }while(findSOS_Com(space, 2, SO) && (!checkSpace()));

   return;
}

int compFindOS(){
	int space;

	for ( i=0; i<board; i++){
		for( j=0; j<board; j++){
		   space = ((i*board) +j)+1;
			if(positionValid(space)){
				if((sos[i][j+1] == 'O') && (sos[i][j+2] == 'S')){
					return space;
				}
                if((sos[i][j-1] == 'O') && (sos[i][j-2] == 'S')){
                    return space;
                        }
				if((sos[i+1][j] == 'O') && (sos[i+2][j] =='S')){
					return space;
				}
                if((sos[i-1][j] == 'O') && (sos[i-2][j] =='S')){
                    return space;
                }
				if((sos[i+1][j+1] == 'O') && (sos[i+2][j+2] == 'S')){
                    return space;
                }
                if((sos[i-1][j-1] == 'O') && (sos[i-2][j-2] == 'S')){
                    return space;
                }
                if((sos[i+1][j-1] == 'O') && (sos[i+2][j-2] == 'S')){
                    return space;
                }
                if((sos[i-1][j+1] == 'O') && (sos[i-2][j+2] == 'S')){
                    return space;
                }
		  	}
		}
	}
	return 0;
}

int compFindSS(){
	int space;
	
    for ( i=0; i<board; i++){
        for( j=0; j<board; j++){  
        
            space = ((i*board) +j)+1;
            if(positionValid(space)){
		        if((sos[i][j+1] == 'S') && (sos[i][j-1] == 'S')){
                    return space;
            	}
                if ((sos[i+1][j] == 'S') && (sos[i-1][j] =='S')){
                    return space;
        		}
                if((sos[i+1][j+1] == 'S') && (sos[i-1][j-1] == 'S')){
                    return space;
                }
                if((sos[i+1][j-1] == 'S') && (sos[i-1][j+1] == 'S')){
                    return space;
                }
            }
		}
    }
	return 0;
}


int findSOS_Com(int space, int player, char SO){
	int get;
	
	sRow = (space-1)/board;
	sCol = (space-1)%board;
	get = 0;
	
  	if(SO == 'S'){
		if ((sos[sRow][sCol-2] == 'S') && (sos[sRow][sCol-1] == 'O')){
			get++;
		}
		if ((sos[sRow][sCol+1]== 'O') && (sos[sRow][sCol+2] == 'S')){
			get++;
		}	
		if((sos[sRow+1][sCol] == 'O') && (sos[sRow+2][sCol] == 'S')){
			get++;
		}
		if((sos[sRow-1][sCol] == 'O') && (sos[sRow-2][sCol] == 'S')){
			get++;
		}
		if((sos[sRow+1][sCol+1] == 'O') && (sos[sRow+2][sCol+2] == 'S')){
			get++;
		}
		if((sos[sRow-1][sCol-1] == 'O') && (sos[sRow-2][sCol-2] == 'S')){
			get++;
		}
		if((sos[sRow+1][sCol-1] == 'O') && (sos[sRow+2][sCol-2] == 'S')){
			get++;
		}
		if((sos[sRow-1][sCol+1] == 'O') && (sos[sRow-2][sCol+2] == 'S')){
			get++;
		}
  	}
  	else if(SO == 'O'){
		if((sos[sRow+1][sCol] == 'S') && (sos[sRow-1][sCol] == 'S')){
			get++;
		}
		if((sos[sRow][sCol+1] == 'S') && (sos[sRow][sCol-1] == 'S')){
			get++;
		}
		if((sos[sRow+1][sCol+1] == 'S') && (sos[sRow-1][sCol-1] == 'S')){
			get++;
		}
		if((sos[sRow+1][sCol-1] == 'S') && (sos[sRow-1][sCol+1] == 'S')){
			get++;
		}
  	}
    scores[currentPlayer] = scores[currentPlayer] + get;

	if(get>0){
		got=1;
		return 1;
	}
	else{
		currentPlayer=0;
		got=0;
		return 0;
	}
}

void scoreboard(){
	//tampilan scoreboard
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
	//tampilan help
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

/*scoreboard untuk pengisian menggunakan file belum tercapai*/
