# Simple smoke test for CI that also validates NNUE loader

set -e
./build/aperatura <<'EOF'
uci
isready
position startpos
go
quit
EOF

# Test NNUE loader (will print message to stderr if weights not present)
./build/aperatura nnue_test ./weights/sample.nnue || true
