#ifndef DARTS_H
#define DARTS_H

typedef struct {
    float x;
    float y;
} coordinate_t;

float distance_to_center(coordinate_t pos);
int score(coordinate_t pos);

#endif
