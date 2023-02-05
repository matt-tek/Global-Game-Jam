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

vector<string> diner = {{"Elize", "Julia", "Victor", "Elize", "Catherine", "Diego", "Agathe", "Elize", "Carlos", "Pablo", "Victor"}};

vector<string> cousin_meet = {{"James", "Diego", "James", "Diego", "James", "Diego", "James"}};

vector<string> bad_meet = {{"Carlos", "Sebastian", "Carlos", "Sebastian", "Carlos"}};

vector<string> bar_meet = {{"Sebastian", "Julia", "Sebastian", "Sebastian", "Elize", "Sebastian", "Elize", "Sebastian", "Elize", "Sebastian"}};

vector<string> murder = {{"Elize", "James", "Elize"}};

vector <string> bonus = {{"Pablo", "Carlos", "Pablo", "Carlos", "Pablo", "Carlos", "Pablo", "Carlos"}};

vector<string> bgs = {"./assets/sprites/salon.jpg",
    "./assets/sprites/kwizine.png", "./assets/sprites/dining_2.jpg",
    "./assets/sprites/garden.jpg", "./assets/sprites/billiard.jpg",
    "./assets/sprites/night_club.jpg", "./assets/sprites/room.jpg"};

vector<vector<string>> history = {introduction, breakfast, diner, cousin_meet,
    bad_meet, bar_meet, murder, bonus};

string dialog(game **gm)
{
    /* (*gm)->correct == true
    (*gm)->correct = false; */

    setlocale(LC_ALL, "");
    cout << (*gm)->currentScene << endl;
    if ((*gm)->person > history[(*gm)->currentScene].size() - 1) {
        if ((*gm)->currentScene >= history.size() - 1) {
            (*gm)->getWindow()->getWindow()->close();
            return "End of scenario";
        }
        if ((*gm)->correct == false)
            return "Err";
        (*gm)->correct = false;
        (*gm)->currentScene += 1;

        (*gm)->texture.loadFromFile(bgs[(*gm)->currentScene]);
        (*gm)->bg.setTexture((*gm)->texture);
        (*gm)->bg.setScale(sf::Vector2f(1.71, 1.71));

        (*gm)->person = -1;
        return "Transition";
    }
    (*gm)->getPlayer(history[(*gm)->currentScene][(*gm)->person]).talk(gm);
    return history[(*gm)->currentScene][(*gm)->person];
}