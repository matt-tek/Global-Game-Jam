

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>


class text 
{
    public:
        text() : validate(false) {}
        ~text() {}
        std::vector<std::shared_ptr<text>> deps;
        std::string parole;
        bool validate;
        bool isNext(void) {
            int count = 0;
            for (auto &it: this->deps) {
                if (it->validate == true) {
                    count++;
                }
            }
            return (count == this->deps.size() ? true : false);
        }
};
