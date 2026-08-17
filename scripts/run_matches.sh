#!/usr/bin/env bash
# Run a small engine-vs-engine match using cutechess-cli (must be installed separately)
# This script assumes the engines are available under tools/stockfish_18/stockfish (or similar) and tools/reckless/reckless
set -e

# paths
MY_ENGINE=./build/aperatura
STOCKFISH=./tools/stockfish_18/stockfish
RECKLESS=./tools/reckless/reckless

GAMES=40
TC="40+0"
CONCURRENCY=4
LOG_DIR=logs
mkdir -p $LOG_DIR

if [ ! -x "$MY_ENGINE" ]; then
  echo "Build Aperatura first: cmake -S . -B build && cmake --build build"
  exit 1
fi

if [ ! -x "$STOCKFISH" ]; then
  echo "Stockfish binary not found or not executable at $STOCKFISH"
fi
if [ ! -x "$RECKLESS" ]; then
  echo "Reckless binary not found or not executable at $RECKLESS"
fi

# Example: Aperatura vs Stockfish (if stockfish exists)
if [ -x "$STOCKFISH" ]; then
  cutechess-cli -engine cmd="$MY_ENGINE" name=Aperatura -engine cmd="$STOCKFISH" name=Stockfish -each tc=$TC -games $GAMES -repeat -concurrency $CONCURRENCY -log $LOG_DIR/aperatura_vs_stockfish.log || true
fi

# Example: Aperatura vs Reckless
if [ -x "$RECKLESS" ]; then
  cutechess-cli -engine cmd="$MY_ENGINE" name=Aperatura -engine cmd="$RECKLESS" name=Reckless -each tc=$TC -games $GAMES -repeat -concurrency $CONCURRENCY -log $LOG_DIR/aperatura_vs_reckless.log || true
fi

echo "Matches finished (or skipped if binaries not found). Logs in $LOG_DIR if runs executed."
