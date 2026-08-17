#include "engine.h"
#include "board.h"
#include <random>

Engine::Engine() {
    set_startpos();
}

void Engine::set_startpos() {
    Board b;
    b.set_start_position();
}

void Engine::set_fen(const std::string &fen) {
    Board b;
    b.set_fen(fen);
}

std::string Engine::go() {
    // Very simple placeholder: pick a random legal move
    Board b;
    auto moves = b.generate_legal_moves();
    if (moves.empty()) return "0000";
    static std::mt19937_64 rng(0xC0FFEE);
    std::uniform_int_distribution<size_t> dist(0, moves.size()-1);
    auto mv = moves[dist(rng)];
    return mv.to_uci();
}
