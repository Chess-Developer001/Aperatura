#include "eval_nnue.h"
#include <fstream>
#include <iostream>

NNUE::NNUE(): loaded(false) {}
NNUE::~NNUE() {}

bool NNUE::load(const std::string &p) {
    // For now simply check the file exists and mark loaded. Real NNUE inference will be added later.
    std::ifstream f(p, std::ios::binary);
    if (!f.good()) {
        std::cerr << "NNUE: failed to open weights file: " << p << "\n";
        loaded = false;
        return false;
    }
    // TODO: parse header/weights and initialize inference engine
    loaded = true;
    path = p;
    std::cerr << "NNUE: loaded weights (stub): " << p << "\n";
    return true;
}

int NNUE::evaluate_simple(const std::string &fen) const {
    // Very simple deterministic placeholder evaluator based on material counts in FEN.
    // Not a real NNUE; used to hook-in during development.
    int score = 0;
    // count piece letters in fen
    for (char c : fen) {
        switch (c) {
            case 'P': score += 100; break;
            case 'N': score += 320; break;
            case 'B': score += 330; break;
            case 'R': score += 500; break;
            case 'Q': score += 900; break;
            case 'p': score -= 100; break;
            case 'n': score -= 320; break;
            case 'b': score -= 330; break;
            case 'r': score -= 500; break;
            case 'q': score -= 900; break;
            default: break;
        }
    }
    return score; // centipawns
}
