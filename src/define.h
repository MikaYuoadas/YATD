#ifndef DEFINE
#define DEFINE

#define ROW 16
#define COLUMN 16
#define SQUARE_SIZE 32
#define HEIGHT ROW * SQUARE_SIZE
#define WIDTH COLUMN * SQUARE_SIZE
#define UI_WIDTH 200
#define TIMER_INT 20
#define BASE_SIZE 30
#define BASE_SPEED SQUARE_SIZE * TIMER_INT / 1000

enum move {FLY, CRAWL};

#define FREE 0
#define NORD 1
#define SUD 2
#define EAST 4
#define NE 5
#define SE 6
#define WEST 8
#define NO 9
#define SO 10
#define GOAL 32
#define DIRT 64

#endif
