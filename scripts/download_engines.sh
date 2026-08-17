#!/usr/bin/env bash
# Download Stockfish 18 and Reckless latest release into tools/ for testing
set -e
mkdir -p tools
cd tools

# Stockfish 18 release (Linux x64) - try GitHub release assets
SF_URL="https://github.com/official-stockfish/stockfish/releases/download/sf18/stockfish_18_linux_x64_avx2.zip"
RECKLESS_URL="https://github.com/niklasf/reckless/releases/latest/download/reckless-linux.zip"

echo "Downloading Stockfish 18 (attempting known URL) ..."
if [ ! -f stockfish_18.zip ]; then
  curl -L -o stockfish_18.zip "$SF_URL" || echo "Stockfish URL failed, please download manually and place in tools/"
fi

echo "Downloading Reckless (latest) ..."
if [ ! -f reckless.zip ]; then
  curl -L -o reckless.zip "$RECKLESS_URL" || echo "Reckless download failed, please download manually and place in tools/"
fi

# Unzip if present
if [ -f stockfish_18.zip ]; then
  unzip -o stockfish_18.zip -d stockfish_18 || true
fi
if [ -f reckless.zip ]; then
  unzip -o reckless.zip -d reckless || true
fi

echo "Download step finished. Check tools/stockfish_18 and tools/reckless directories for binaries."
