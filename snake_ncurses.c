#include "snake_ncurses.h"

long long timeInUseconds() {
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return (((long long)tv.tv_sec)*1000000)+(tv.tv_usec);
}

long long waitTime(long long next,long long now){
    long long result = next-now;
    if (result)
		return result;
	return 0;
}

int dealInput(int ch){
	switch(ch){
		case 'W':
		case 'w':
		case KEY_UP:
			return setdirUP();
		case 'A':
		case 'a':
		case KEY_LEFT:
			return setdirLEFT();
		case 'S':
		case 's':
		case KEY_DOWN:
			return setdirDOWN();
		case 'D':
		case 'd':
		case KEY_RIGHT:
			return setdirRIGHT();
	}
}
