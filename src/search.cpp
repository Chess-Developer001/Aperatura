#include "search.h"
#include <string>
#include <iostream>
#include <random>

// Very small alpha-beta root stub that doesn't parse board properly yet.
// It will pick a pseudo-random legal move via the Engine/Board interfaces.

int alpha_beta_root(const std::string &fen, int max_depth, std::string &bestmove_fen) {
    // Placeholder: bestmove_fen will be a FEN of a child position rather than a UCI move.
    // In future commits this will perform a full search on a proper board.
    // For now, return 0 as evaluation and return the same FEN to indicate no move.
    (void)max_depth;
    bestmove_fen = fen; // no change
    return 0;
}
