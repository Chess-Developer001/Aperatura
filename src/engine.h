#pragma once
#include <string>

class Engine {
public:
    Engine();
    void set_startpos();
    void set_fen(const std::string &fen);
    std::string go(); // returns bestmove in UCI format
};
