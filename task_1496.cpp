/**
 * 1496. Спамер
 * Ограничение времени: 1.0 секунды
 * Ограничение памяти: 64 МБ
 * 
 * Среди наших знакомых есть известный спамер.
 * В конце каждого контеста он сабмитит свои неправильные решения
 * со скоростью пулемёта. Кроме того, он ещё и ведёт нечестную игру,
 * всегда используя по несколько отладочных аккаунтов. Жюри
 * наконец-то решило дисквалифицировать спамера. Для этого они
 * сначала хотят определить все его отладочные аккаунты. Известно,
 * какие команды сабмитили свои решения в последние 10 минут
 * контеста. Ваша задача — найти все отладочные аккаунты спамера.
 * Жюри считает аккаунтами спамера всех, кто сабмитил решения
 * больше одного раза в последние 10 минут.
 * 
 * Исходные данные
 * В первой строке записано число N — количество сабмитов в
 * последние 10 минут (0 ≤ N ≤ 100). Следующие N строк содержат
 * названия команд, сабмитивших решения. Названия состоят только
 * из строчных латинских букв и цифр. Длина названий не превосходит
 * 30 символов.
 * 
 * Результат
 * Выведите все аккаунты, под которыми, по мнению жюри, играет спамер.
 * Порядок вывода не важен.
 * 
 * Пример
 * исходные данные  
 * 11
 * naucoder
 * iceman
 * abikbaev
 * abikbaev
 * petr
 * abikbaev
 * abikbaev
 * x
 * abikbaev
 * acrush
 * x
 *  
 * результат
 * x
 * abikbaev
 */

#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

int main()
{
  std::size_t count;
  std::string participant;
  std::set<std::string> participants;
  std::set<std::string> spammers;

  std::ios::sync_with_stdio(false);

  std::cin >> count;
  for(decltype(count) i{0}; i < count; ++i) {
    std::cin >> participant;
    if(participants.count(participant))
      spammers.insert(participant);
    else
      participants.insert(participant);
  }

  std::copy(std::cbegin(spammers),
            std::cend(spammers),
            std::ostream_iterator<std::string>(std::cout, "\n"));

  return 0;
}
