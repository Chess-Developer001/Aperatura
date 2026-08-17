#include "uci.h"
#include "engine.h"
#include <string>
#include <iostream>

void UCI::loop() {
    Engine engine;
    std::string line;
    while (std::getline(std::cin, line)) {
        if (line == "uci") {
            std::cout << "id name Aperatura\n";
            std::cout << "id author Chess-Developer001\n";
            std::cout << "uciok\n";
        } else if (line == "isready") {
            std::cout << "readyok\n";
        } else if (line.rfind("position", 0) == 0) {
            // support: position startpos | position fen <fen>
            if (line.find("startpos") != std::string::npos) {
                engine.set_startpos();
            } else {
                // rudimentary: no full fen parsing yet
                size_t pos = line.find("fen ");
                if (pos != std::string::npos) {
                    std::string fen = line.substr(pos + 4);
                    engine.set_fen(fen);
                }
            }
        } else if (line.rfind("go", 0) == 0) {
            std::string best = engine.go();
            std::cout << "bestmove " << best << "\n";
        } else if (line == "quit") {
            break;
        }
    }
}
