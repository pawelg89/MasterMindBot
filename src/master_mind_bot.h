#include <array>
#include <iostream>
#include <string>

namespace mmb {
/**
 * @brief Holds list of all available colors.
 */
constexpr std::array<char, 4> kLegalColors = {'B', 'G', 'R', 'Y'};

/**
 * @brief Structure that represents a guess result.
 * Holds number of direct hits and pseudohits.
 */
struct GuessResult {
  size_t num_hits;
  size_t num_pseudohits;
  GuessResult() = default;
  GuessResult(size_t &&nh, size_t &&nph) : num_hits(nh), num_pseudohits(nph) {};
};

/**
 * @brief Implements a bot that knows how to play MasterMind.
 * Currently supports only the dealer side. Bot picks a color and you guess.
 */
class MasterMindBot {
 public:
  /**
   * @brief Construct bot with initial random state to guess.
   */
  MasterMindBot() : solution_(RollSolution()) {}

  /**
   * @brief Checks how many hits and pseudohits guess have relative to solution.
   * @param guess your guess, eg "RRGG".
   * @return GuessResult @see GuessResult.
   */
  GuessResult CheckInput(const std::string &guess);

  /**
   * @brief Reset solution_ to a new random state.
   */
  void NewGame();
 
  /// Number of colors in the solution.
  const size_t sol_size = 4;

 private:
  /**
   * @brief Generate a random color combination with repetitions.
   * @return Random solution in form of "RGBY" string.
   */
  std::string RollSolution();

  /**
   * @brief Print a congrats message with a bunch of statistics.
   * Give number of guesses it took to win.
   */
  void PrintCongrats();

  /// Holds a set of colors that player is guessing.
  std::string solution_;
  /// Holds number of guesses, increases with each call to CheckInput.
  size_t num_guesses_; 
};
}  // namespace mmb