#include <ncursesw/ncurses.h>
#include "snake_core/snake.h"
#include <unistd.h>
#include <sys/time.h>

extern long long timeInUseconds();

extern long long waitTime(long long next,long long now);

extern int dealInput(int ch);
