/*
** EPITECH PROJECT, 2023
** Global-Game-Jam-
** File description:
** dialog
*/

#include "game.hpp"

string dialog(game **gm, int person)
{
    vector<string> dialog = {"Catherine", "James", "Catherine", "James",
        "Catherine", "James"};

    if (person > dialog.size() - 1)
        return "Err";
    (*gm)->getPlayer(dialog[person]).talk(gm);
    return dialog[person];
}