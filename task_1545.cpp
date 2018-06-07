#include <iostream>
#include <map>

int main()
{
  std::size_t count;
  std::string word;
  std::multimap<char, char> dictionary;
  
  std::cin >> count;
  for(decltype(count) i{0}; i < count; ++i) {
    std::cin >> word;
    dictionary.insert(std::make_pair(word[0], word[1]));
  }

  std::cin >> word;
  auto range = dictionary.equal_range(word[0]);
  for (auto item = range.first; item != range.second; ++item)
    std::cout << item->first << item->second << std::endl;
  
  return 0;
}
