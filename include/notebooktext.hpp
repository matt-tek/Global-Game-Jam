
#pragma once

#include <json/json.h>

#include <iostream>

class notebooktext
{
    public:
        notebooktext();
        ~notebooktext();
        bool loadText(Json::Value root);
        std::string text;
        std::vector<std::string> res;
};