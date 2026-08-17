#!/usr/bin/env bash
set -e
mkdir -p build
cmake -S . -B build
cmake --build build

# run basic smoke test
./build/aperatura <<'EOF'
uci
isready
position startpos
go
quit
EOF
