compile:
	clang font.c show.c visualization.c window.c main.c -o sort_data `sdl2-config --cflags --libs` -lSDL2 -lSDL2_ttf
run:
	./sort_data
