# Aperatura

Aperatura is a chess engine project. This repository contains an initial C++ skeleton (UCI loop, build, CI) and a roadmap to implement a strong engine using an NNUE-style evaluation and modern alpha-beta search.

This is the initial commit. The engine currently implements a UCI skeleton and a simple random-move player; it's intended as a starting point for implementing search, NNUE, and optimizations in follow-up commits.

Roadmap (next milestones):
- Implement full bitboard-based move generation and perft tests
- Alpha-beta search with iterative deepening, transposition table, move ordering, LMR
- NNUE evaluator integration (loadable .nnue weights, optimized inference)
- Multi-threaded search and time management
- Opening book and Syzygy tablebase support
- Self-play harness and Elo tracking (cutechess-cli integration)

Build:
mkdir build && cd build
cmake ..
cmake --build .

Run (UCI):
./aperatura

Contributing: open issues or PRs for features or improvements.
