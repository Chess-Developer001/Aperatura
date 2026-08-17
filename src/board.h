#pragma once
#include <string>
#include <vector>

struct Move {
    int from;
    int to;
    int promo; // 0 = none, 1=knight,2=bishop,3=rook,4=queen
    std::string to_uci() const;
};

class Board {
public:
    Board();
    void set_start_position();
    void set_fen(const std::string &fen);
    std::vector<Move> generate_legal_moves() const; // placeholder
private:
    // internal board representation (simple 8x8 array for now)
    int pieces[64];
};
