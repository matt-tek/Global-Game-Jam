#include "notebooktext.hpp"

notebooktext::notebooktext()
{
}

notebooktext::~notebooktext()
{
}

bool notebooktext::loadText(Json::Value root)
{
    try {
        this->text = root["text"].asString();
        for (auto &it : root["res"]) {
            this->res.push_back(it.asString());
        }
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return (false);
    }
    return (true);
}