/**
 * 1196. Экзамен по истории
 * Ограничение времени: 1.5 секунды
 * Ограничение памяти: 64 МБ
 * Будем справедливы: сессия ставит задачи не только студентам,
 * но и преподавателям. Любой преподаватель обучает немалое
 * количество студентов, а ведь каждого надо еще и проверить.
 * Поэтому один из преподавателей решил принимать экзамен по
 * истории по такой упрощённой процедуре: студент записывает
 * все известные ему «исторические» даты (достаточно, чтобы он
 * написал только года, но, конечно, мог объяснить, чем
 * замечательна та или иная дата). Преподаватель же держит
 * перед глазами список дат, которые студент должен знать.
 * Для оценки знаний студента преподаватель подсчитывает
 * количество чисел в списке студента, которые также есть в
 * списке преподавателя. В зависимости от полученного числа
 * и выставляется итоговая оценка.
 * Вы должны оказать посильную помощь в автоматизации этого
 * процесса, разработав программу для подсчёта количества
 * совпадений в списках студента и преподавателя.
 * 
 * Исходные данные
 * В первой строке содержится число N — количество записей
 * в списке преподавателя. 1 ≤ N ≤ 15000. Затем идет N строк,
 * содержащих список преподавателя, по одной дате в строке.
 * Записаны только года. Каждый год — целое число в пределах
 * от 1 до 10^9. Даты в этом списке отсортированы по неубыванию.
 * В следующей после списка строке содержится число M —
 * количество записей в списке студента, 1 ≤ M ≤ 10^6.
 * Затем также M строк с датами (записаны только года,
 * каждый год — целое число в пределах от 1 до 10^9).
 * Этот список не отсортирован. В списке как студента,
 * так и преподавателя даты могут повторяться.
 * 
 * Результат
 * Вы должны вывести одно число — количество чисел во втором списке,
 * которые также содержатся в первом.
 * 
 * Пример
 * исходные данные  
 * 2
 * 1054
 * 1492
 * 4
 * 1492
 * 65536
 * 1492
 * 100
 * результат
 * 2
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  unsigned long count;
  unsigned long year;
  std::vector<unsigned long> teachers;

  std::ios::sync_with_stdio(false);
  
  // По условию список уже отсортирован и заранее известен его размер,
  // поэтому выбран std::vector и вызван метод reserve.
  std::cin >> count;
  teachers.reserve(count);

  // По условию 1 ≤ count ≤ 15000, поэтому 1 элемент гарантированно есть.
  std::cin >> year;
  teachers.push_back(year);

  for(decltype(count) i{1}; i < count; ++i) {
    std::cin >> year;
    // Могут быть повторения дат. Исключить дубликаты можно, сравнивая с последним
    // добавленным значением поскольку значения идут в отсортированном порядке.
    if(year != teachers.back())
      teachers.push_back(year);
  }
  
  unsigned long intersections{0};
  std::cin >> count;
  for(decltype(count) i{0}; i < count; ++i) {
    std::cin >> year;
    if(std::binary_search(std::cbegin(teachers), std::cend(teachers), year))
      ++intersections;
  }
  
  std::cout << intersections;
  return 0;
}
