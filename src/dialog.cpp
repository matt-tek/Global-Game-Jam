/*
** EPITECH PROJECT, 2023
** Global-Game-Jam-
** File description:
** dialog
*/

#include "game.hpp"

void dialog(game **gm, int person)
{
    vector<string> dialog = {"Nadia", "Nadia", "Louis"};

    if (person > dialog.size() - 1)
        return;
    (*gm)->getPlayer(dialog[person]).talk(gm);
    return;
}