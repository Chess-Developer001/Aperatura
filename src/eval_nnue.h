# NNUE evaluator stub and loader (CPU inference placeholder)

#pragma once
#include <string>

class NNUE {
public:
    NNUE();
    ~NNUE();
    bool load(const std::string &path); // load a .nnue file (stubbed)
    int evaluate_simple(const std::string &fen) const; // return centipawn eval (stub)
private:
    bool loaded;
    std::string path;
};
