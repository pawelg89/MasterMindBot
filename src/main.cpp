#include <iostream>

#include "master_mind_bot.h"

int main() {
  using namespace mmb;
  MasterMindBot bot;
  do {
    std::string in;
    std::cin >> in;
    if (in == "q" || in == "Q") break;
    auto guess_result = bot.CheckInput(in);
    std::cout << "Hits: " << guess_result.num_hits
              << ", Pseudohits: " << guess_result.num_pseudohits << std::endl;
  } while (true);
  return 0;
}