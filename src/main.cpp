#include <iostream>

#include "master_mind_bot.h"

enum class Flag{kQuit, kNewGame, kPrintHelp, kNotAFlag};
Flag HandleFlags(const std::string &input, mmb::MasterMindBot &bot);
void PrintHelp();

int main() {
  PrintHelp();
  using namespace mmb;
  MasterMindBot bot;
  do {
    std::string in;
    std::cin >> in;
    switch(HandleFlags(in, bot)) {
      case Flag::kNewGame:    { break; }
      case Flag::kPrintHelp:  { break; }
      case Flag::kQuit:       { return 0; }
      case Flag::kNotAFlag:   {
        auto guess_result = bot.CheckInput(in);
        std::cout << "Hits: " << guess_result.num_hits
                  << ", Pseudohits: " << guess_result.num_pseudohits
                  << std::endl;
      }
    }
  } while (true);
  return 0;
}

Flag HandleFlags(const std::string &input, mmb::MasterMindBot &bot) {
  if (input == "q" || input == "Q") return Flag::kQuit;
  if (input == "help" || input == "h" || input == "H") {
    PrintHelp();
    return Flag::kPrintHelp;
  }
  if (input == "new_game") { 
    bot.NewGame();
    return Flag::kNewGame;
  }
  return Flag::kNotAFlag;
}

void PrintHelp() {
  std::cout <<
      "Hello! This is the MasterMind game."
      "q/Q      - quit game"
      "h/H      - print this message"
      "new_game - reset bot's solution and start a new game"
  << std::endl;
}