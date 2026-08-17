#include "board.h"
#include <string>

Board::Board() {
    for (int i=0;i<64;i++) pieces[i]=0;
}

void Board::set_start_position() {
    // very simple setup: not fully encoded pieces, just placeholder
    // TODO: implement full piece placement
}

void Board::set_fen(const std::string &fen) {
    // NOT IMPLEMENTED: placeholder
}

std::vector<Move> Board::generate_legal_moves() const {
    // placeholder: return no moves
    return {};
}

std::string Move::to_uci() const {
    char buf[8];
    int f = from;
    int t = to;
    int fc = 'a' + (f % 8);
    int fr = '1' + (f / 8);
    int tc = 'a' + (t % 8);
    int tr = '1' + (t / 8);
    if (promo==0) {
        snprintf(buf, sizeof(buf), "%c%c%c%c", fc, fr, tc, tr);
    } else {
        char p = 'q';
        switch(promo) { case 1: p='n'; break; case 2: p='b'; break; case 3: p='r'; break; case 4: p='q'; break; }
        snprintf(buf, sizeof(buf), "%c%c%c%c%c", fc, fr, tc, tr, p);
    }
    return std::string(buf);
}
