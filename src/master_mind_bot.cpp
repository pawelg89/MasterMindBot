#include "master_mind_bot.h"

#include <algorithm>
#include <chrono>
#include <map>

namespace mmb {
GuessResult MasterMindBot::CheckInput(const std::string &guess) {
  if (guess.size() != solution_.size())
    throw std::invalid_argument("'" + guess + "'");
  size_t hits = 0; size_t pseudohits = 0;
  std::map<char, size_t> sol_colors{{'B', 0}, {'G', 0}, {'R', 0}, {'Y', 0}};
  std::map<char, size_t> gss_colors{{'B', 0}, {'G', 0}, {'R', 0}, {'Y', 0}};
  for (size_t i = 0; i < guess.size(); ++i) {
    if (guess[i] == solution_[i]) {
      ++hits;
    } else {
      ++sol_colors[solution_[i]]; // if we don't have a hit we save info about
                                  // what color it is
      ++gss_colors[guess[i]]; // also note 
    }
  }
  for (const auto &pair : sol_colors) {
    pseudohits += std::min(pair.second, gss_colors[pair.first]);
  }
  ++num_guesses_;
  if (hits == sol_size) PrintCongrats();
  return GuessResult(std::move(hits), std::move(pseudohits));
}

void MasterMindBot::NewGame() {
  solution_ = RollSolution();
  std::cout << "Picking new solution for you to guess." << std::endl;
}

std::string MasterMindBot::RollSolution() {
  num_guesses_ = 0;
  std::string result;
  for (size_t i = 0; i < sol_size; i++)
    result += kLegalColors[std::chrono::high_resolution_clock::now()
        .time_since_epoch().count() % std::rand() % kLegalColors.size()];
  return result;
}

void MasterMindBot::PrintCongrats() {
  std::cout << "!!! CONGRATULATIONS !!!\nYou guessed my pick '" << solution_ 
      << "' in " << num_guesses_ << " guesses. Wanna play again?"
      << "\nType 'new_game' to restart." << std::endl;
}

}  // namespace mmb