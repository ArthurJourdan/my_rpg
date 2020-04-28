/*
** EPITECH PROJECT, 2019
** main
** File description:
** generic main
*/

#include "my.h"

#include "gui.h"
#include "xml_parser.h"

#include "my_rpg.h"

int main(int ac, char **av)
{
    global_t *global = NULL;

    if (!error_msg(ac, av))
        return EXIT_FAILURE;
    global = xml_parser(av[1]);
    if (!global)
        return EXIT_FAILURE;
    init_game(global);
    rpg_manager(global);
    return EXIT_SUCCESS;
}
