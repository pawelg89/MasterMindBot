#include "master_mind_bot.h"

#include <algorithm>
#include <map>

namespace mmb {
GuessResult MasterMindBot::CheckInput(const std::string &guess) {
  if (guess.size() != solution_.size()) throw std::invalid_argument("'" + guess + "'");
  size_t hits = 0; size_t pseudohits = 0;
  std::map<char, size_t> sol_colors{{'B', 0}, {'G', 0}, {'R', 0}, {'Y', 0}};
  std::map<char, size_t> gss_colors{{'B', 0}, {'G', 0}, {'R', 0}, {'Y', 0}};
  for (size_t i = 0; i < guess.size(); ++i) {
    if (guess[i] == solution_[i]) { //hit
      ++hits;
    } else { //check for pseudo hits
      ++sol_colors[solution_[i]]; // if we don't have a hit we save info about what color it is
      ++gss_colors[guess[i]]; // also note 
    }
  }
  for (const auto &pair : sol_colors) {
    pseudohits += std::min(pair.second, gss_colors[pair.first]);
  }
  return GuessResult(std::move(hits), std::move(pseudohits));
}
}  // namespace mmb