.PHONY: clean all


object = build/main.o build/snake_ncurses.o build/snake.o 
objectWin = build/mainWin.o build/snakeWin.o build/snake_ncursesWin.o
CFLUG = -s -O2 -Os -Wl,--gc-sections -lncursesw #-static -DNCURSES_STATIC -ltinfo
CFLUGwin = -I ./ncurses_mingw64/include -L ./ncurses_mingw64/lib -s -O2 -Os -Wl,--gc-sections -static -DNCURSES_STATIC -lncursesw

all : snake snake.exe

snake : $(object)
	gcc $(object) -o $@ $(CFLUG)

build/snake.o : snake_core/snake.c
	gcc -c $< -o $@ $(CFLUG)

build/snake_ncurses.o : snake_ncurses.c
	gcc -c $< -o $@ $(CFLUG)

build/main.o : main.c
	gcc -c $< -o $@ $(CFLUG)

snake.exe : $(objectWin)
	x86_64-w64-mingw32-gcc $(objectWin) -o $@ $(CFLUGwin)

build/snakeWin.o : snake_core/snake.c
	x86_64-w64-mingw32-gcc -c $< -o $@ $(CFLUGwin) 

build/snake_ncursesWin.o : snake_ncurses.c
	x86_64-w64-mingw32-gcc -c $< -o $@ $(CFLUGwin)

build/mainWin.o : main.c
	x86_64-w64-mingw32-gcc $(CFLUG) -c $< -o $@ $(CFLUGwin)



clean :
	rm -rf build/* main main.exe snake snake.exe

