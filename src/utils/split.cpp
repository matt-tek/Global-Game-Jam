/*
** EPITECH PROJECT, 2023
** Global-Game-Jam-
** File description:
** split
*/

#include "game.hpp"

vector<string> split(const string& str, const string& delimiters) {
  vector<string> tokens;
  string token;
  istringstream tokenStream(str);
  while (getline(tokenStream, token, delimiters[0])) {
    size_t prev = 0, pos;
    while ((pos = token.find_first_of(delimiters, prev)) != string::npos) {
      if (pos > prev)
        tokens.push_back(token.substr(prev, pos - prev));
      prev = pos + 1;
    }
    if (prev < token.length())
      tokens.push_back(token.substr(prev, string::npos));
  }
  return tokens;
}