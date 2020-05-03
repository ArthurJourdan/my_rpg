/*
** EPITECH PROJECT, 2020
** goto.c
** File description:
** pos1 go to pos2
*/

#include "my_rpg.h"
#include "sfml_tools.h"

UNSD static float rotation(sfVector2f dir)
{
    float radian = acos(dir.x / (sqrt((pow(dir.y, 2) + pow(dir.x, 2)))));
    float angle = radian * 180.0 / M_PI;
    float result = ((dir.y > 0) ? angle : (-angle));

    return result;
}

static sfVector2f direction(sfVector2f pos, sfVector2f end)
{
    sfVector2f dist = sfV2F{(end.x - pos.x), (end.y - pos.y)};
    float max = MAX(ABS(dist.x), ABS(dist.y));
    sfVector2f dir = sfV2F{dist.x / max, dist.y / max};

    return dir;
}

sfVector2f my_goto(sfVector2f *pos, sfVector2f start,
sfVector2f target, float speed)
{
    sfVector2f dir = direction(*pos, target);

    if (ABS((target.x - pos->x)) <= speed &&
        ABS((target.y - pos->y)) <= speed) {
        pos->x = start.x;
        pos->y = start.y;
    }
    pos->x += dir.x * speed;
    pos->y += dir.y * speed;
    return dir;
}
