#include <iostream>
#include <sstream>

#include "master_mind_bot.h"

enum class Flag{kQuit, kNewGame, kPrintHelp, kPrintRules, kNotAFlag};
Flag HandleFlags(const std::string &input, mmb::MasterMindBot &bot);
void PrintHelp();
void PrintRules(const mmb::MasterMindBot &bot);

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
      case Flag::kPrintRules: { break; }
      case Flag::kQuit:       { return 0; }
      case Flag::kNotAFlag:   {
        auto guess_result = bot.CheckInput(in);
        if (guess_result.num_hits != bot.sol_size)
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
  if (input == "rules") {
    PrintRules(bot);
    return Flag::kPrintRules;
  }
  if (input == "new_game") { 
    bot.NewGame();
    return Flag::kNewGame;
  }
  return Flag::kNotAFlag;
}

void PrintRules(const mmb::MasterMindBot &bot) {
  auto get_colors = []() -> std::string {
    std::stringstream colors;
    for (size_t i = 0; i < mmb::kLegalColors.size(); i++) {
      colors << mmb::kLegalColorsNames[i] << "(" << mmb::kLegalColors[i] << ")";
      if (i < mmb::kLegalColors.size() - 1) colors << ", ";
    }
    return std::string(colors.str());
  };
  std::cout
      << "Game Rules\n"
      << "One player (me) is choosing sequence of " << bot.sol_size << " colors with repetitions.\n"
      << "Available colors: " << get_colors() << " that the other player (you) has to guess.\n"
      << "If you guess a color on correct position you get a 'hit',\n"
      << "If you guess a color but it's in another position (other than hit) you get a 'pseudohit'.\n"
      << "Example: I pick 'RGBY', you guess 'RYGG' and you get 1 hit and 2 pseudohits.\n"
      << "How many guesses do you need to win? ;)"
      << std::endl;
}

void PrintHelp() {
  std::cout <<
      "Hello! This is the MasterMind game.\n"
      "[q|Q]      - quit game\n"
      "[h/H]      - print this message\n"
      "[rules]    - print rules of the game\n"
      "[new_game] - reset bot's solution and start a new game\n"
      "I'm picking a colors combination, you guess. You can take as much time"
      " as you like. Good luck with your guesses!"
  << std::endl;
}