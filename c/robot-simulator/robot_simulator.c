#include <stdlib.h>
#include "robot_simulator.h"

robot_status_t robot_create(robot_direction_t direction, int x, int y) {
    robot_status_t robot = { .direction = direction, .position = { .x = x, .y = y }};

    return robot;
}

void robot_move(robot_status_t *robot, const char *commands) {
    if (commands == NULL) {
        return;
    }

    int i = 0;
    while (commands[i] != '\0') {
        if (commands[i] == 'R') {
            robot->direction = (robot->direction + 1) % 4;
        } else if (commands[i] == 'L') {
            if (robot->direction == DIRECTION_NORTH) {
                robot->direction = DIRECTION_WEST;
            } else {
                robot->direction -= 1;
            }
        } else {
            if (robot->direction == DIRECTION_NORTH) {
                robot->position.y += 1;
            } else if (robot->direction == DIRECTION_WEST) {
                robot->position.x -= 1;
            } else if (robot->direction == DIRECTION_SOUTH) {
                robot->position.y -= 1;
            } else {
                robot->position.x += 1;
            }
        }

        i++;
    }
}