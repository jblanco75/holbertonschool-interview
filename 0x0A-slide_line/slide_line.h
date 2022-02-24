#ifndef SLIDE_LINE_H_
#define SLIDE_LINE_H_

#include <stdlib.h>

#define SLIDE_LEFT 1
#define SLIDE_RIGHT 0

int slide_line(int *line, size_t size, int direction);
int slide_to_the_left(int *line, size_t size);
int slide_to_the_right(int *line, size_t size);

#endif
