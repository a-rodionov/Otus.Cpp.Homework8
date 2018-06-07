#include <iostream>
#include <set>

int main()
{
  std::size_t count;
  std::string participant;
  std::set<std::string> participants;
  std::set<std::string> spammers;

  std::cin >> count;
  for(decltype(count) i{0}; i < count; ++i) {
    std::cin >> participant;
    if(participants.count(participant))
      spammers.insert(participant);
    else
      participants.insert(participant);
  }

  for (const auto& spammer : spammers)
    std::cout << spammer << std::endl;

  return 0;
}
