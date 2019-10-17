#include <string>
#include <iostream>

namespace mmb {
struct GuessResult {
  size_t num_hits;
  size_t num_pseudohits;
  GuessResult() = default;
  GuessResult(size_t &&nh, size_t &&nph) : num_hits(nh), num_pseudohits(nph) {};
};

class MasterMindBot {
 public:
  MasterMindBot() : solution_("RGBY") {
    std::cout << "I'm thinking about '" << solution_ << "'." << std::endl;
  }
  GuessResult CheckInput(const std::string &guess);
 
 private:
  const std::string solution_;
};
}  // namespace mmb