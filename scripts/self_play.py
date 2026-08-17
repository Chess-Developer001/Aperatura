#!/usr/bin/env python3
"""
Simple self-play harness: launches two copies of Aperatura with different random seeds to generate games.
This is a placeholder harness; for robust matches we use cutechess-cli (already included in scripts/run_matches.sh).
"""
import subprocess
import sys
import os

MY_ENGINE = './build/aperatura'
GAMES = 10

if not os.path.isfile(MY_ENGINE):
    print('Build Aperatura first')
    sys.exit(1)

for g in range(1, GAMES+1):
    print(f"Self-play game {g}/{GAMES} (placeholder)")
    # placeholder: actual self-play requires UCI orchestration or cutechess

print('Self-play harness finished (placeholder). Use scripts/run_matches.sh for real matches with cutechess-cli.')
