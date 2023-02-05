/*
** EPITECH PROJECT, 2023
** Global-Game-Jam-
** File description:
** dialog
*/

#include "game.hpp"

vector<string> introduction = {{"Catherine", "James", "Catherine", "James",
    "Catherine", "James"}};

vector<string> breakfast = {{"Julia", "Catherine", "James", "Agathe", "Catherine", "Agathe", "Catherine", "Agathe", "Catherine" ,"Julia", "Elize" ,"Elize", "Julia", "Elize", "Julia", "Elize"}};


vector<vector<string>> history = {introduction, breakfast};

string dialog(game **gm)
{
    cout << (*gm)->currentScene << endl;
    if ((*gm)->person > history[(*gm)->currentScene].size() - 1) {
        if ((*gm)->currentScene >= history.size() - 1) {
            (*gm)->getWindow()->getWindow()->close();
            return "End of scenario";
        }
        (*gm)->currentScene += 1;
        (*gm)->person = -1;
        return "Transition";
    }
    (*gm)->getPlayer(history[(*gm)->currentScene][(*gm)->person]).talk(gm);
    return history[(*gm)->currentScene][(*gm)->person];
}