#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  unsigned long count;
  unsigned long year;
  std::vector<unsigned long> teachers;
  
  // По условию список уже отсортирован и заранее известен его размер,
  // поэтому выбран std::vector и вызван метод reserve.
  scanf("%lu",&count);
  teachers.reserve(count);

  // По условию 1 ≤ count ≤ 15000, поэтому 1 элемент гарантированно есть.
  scanf("%lu",&year);
  teachers.push_back(year);

  for(decltype(count) i{1}; i < count; ++i) {
    scanf("%lu",&year);
    // Могут быть повторения дат. Исключить дубликаты можно, сравнивая с последним
    // добавленным значением поскольку значения идут в отсортированном порядке.
    if(year != teachers.back())
      teachers.push_back(year);
  }
  
  unsigned long intersections{0};
  scanf("%lu",&count);
  for(decltype(count) i{0}; i < count; ++i) {
    scanf("%lu",&year);
    if(std::binary_search(std::cbegin(teachers), std::cend(teachers), year))
      ++intersections;
  }
  
  std::cout << intersections;
  return 0;
}
