#include "snake_ncurses.h"

#define FRAMETIME 500000

int draw();

int main(int argc,char *argv[]){

GAMESTART:
	srand((unsigned)time(NULL));
	initHeadPos(3,3,'>');
	genfood();

	initscr();
	curs_set(0);
	raw();
	noecho();
	cbreak();
	keypad(stdscr,TRUE);
	nodelay(stdscr, true);

	draw();

	long long nextTime = 0,nowTime = 0;
	int ch = 0,prech = 0;

	while(1){
		ch=EOF;
		nextTime = timeInUseconds()+FRAMETIME;

		while((prech = getch()) != EOF)
			ch = prech;
		if (ch == 'q')
			break;

		dealInput(ch);

		switch (change()){
			case 1:
				clear();
				printw("\
#----------------#\n\
|                |\n\
|                |\n\
|                |\n\
|    gameover    |\n\
|                |\n\
|                |\n\
|                |\n\
|                |\n\
#----------------#\n\
						");
				goto GAMEOVER;
			case 2:
				clear();
				printw("\
#----------------#\n\
|                |\n\
|                |\n\
|                |\n\
|      win       |\n\
|                |\n\
|                |\n\
|                |\n\
|                |\n\
#----------------#\n\
						");
				goto GAMEOVER;
		}

		nowTime = timeInUseconds();
		draw();
		usleep(waitTime(nextTime,nowTime));
	}

GAMEOVER:
	refresh();
	nodelay(stdscr, FALSE);
	getch();
	endwin();
	return 0;
}

int draw(){
	clear();
	printw("%c",'#');
	for(int y=0;y<MAPSIZE;y++)
		printw("--");
	printw("%c\n",'#');
	for(int y=0;y<MAPSIZE;y++){
		printw("|");
		for(int x=0;x<MAPSIZE;x++){
			switch (map[x][y]){
				case  0 :
					printw("  ");
					break;
				case '@':
					printw("@@");
					break;
				default:
					printw("%c%c",map[x][y],map[x][y]);
			}
		}
		printw("|\n");
	}
	printw("%c",'#');
	for(int y=0;y<MAPSIZE;y++)
		printw("--");
	printw("%c\n",'#');

	refresh();
	return 0;
}

