/*
** EPITECH PROJECT, 2019
** main
** File description:
** generic main
*/

#include "my.h"
#include "print.h"

#include "global.h"
#include "gui.h"
#include "xml_parser.h"
#include "sfml_tools.h"

void test_loop(global_t *global)
{
    while (sfRenderWindow_isOpen(GW)) {
        display_images(GW, SC_I);
        display_buttons(GW, SC_B);
        display_texts(GW, SC_T);
        sfRenderWindow_display(GW);
    }
}

int main(int ac, char **av)
{
    global_t *global = NULL;

    if (!error_msg(ac, av))
        return EXIT_FAILURE;
    global = xml_parser(av[1]);
    if (!global)
        return EXIT_FAILURE;
    test_loop(global);
    return EXIT_SUCCESS;
}
