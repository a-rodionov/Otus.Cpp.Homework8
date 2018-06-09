/**
 * 1837. Число Исенбаева
 * Ограничение времени: 0.5 секунды
 * Ограничение памяти: 64 МБ
 * 
 * Владислав Исенбаев — двукратный чемпион Урала по программированию,
 * вице-чемпион TopCoder Open 2009, абсолютный чемпион ACM ICPC 2009.
 * За то время, которое вы потратите на чтение этого условия,
 * Владислав уже решил бы одну задачу. А может, и две…
 * Поскольку Владислав Исенбаев — выпускник СУНЦ УрГУ, неудивительно,
 * что многие из бывших и действующих олимпиадников УрГУ знакомы с
 * ним уже много лет. Некоторые из них с гордостью заявляют, что
 * играли с Владиславом в одной команде. Или играли в команде с
 * бывшими однокомандниками Владислава…
 * Определим число Исенбаева следующим образом. У самого Владислава
 * это число равняется нулю. У тех, кто играл с ним в одной команде,
 * оно равняется единице. У тех, кто играл вместе с однокомандниками
 * Владислава, но не играл с ним самим, это число равняется двум, и
 * так далее. Помогите автоматизировать процесс вычисления чисел
 * Исенбаева, чтобы каждый олимпиадник в УрГУ мог знать, насколько
 * близок он к чемпиону ACM ICPC.
 * 
 * Исходные данные
 * В первой строке записано целое число n — количество команд
 * (1 ≤ n ≤ 100). В каждой из следующих n строк записаны составы этих
 * команд в виде фамилий трёх участников. Фамилия каждого участника —
 * непустая строка, состоящая из английских букв, длиной не более 20
 * символов. Первая буква фамилии — заглавная, все остальные — строчные.
 * Фамилия Владислава — «Isenbaev».
 * 
 * Результат
 * Для каждого участника, представленного во входных данных, выведите
 * в отдельной строке через пробел его фамилию и число Исенбаева.
 * Если это число не определено, выведите вместо него «undefined».
 * Участники должны быть упорядочены по фамилии в лексикографическом
 * порядке.
 * 
 * Пример
 * исходные данные  
 * 7
 * Isenbaev Oparin Toropov
 * Ayzenshteyn Oparin Samsonov
 * Ayzenshteyn Chevdar Samsonov
 * Fominykh Isenbaev Oparin
 * Dublennykh Fominykh Ivankov
 * Burmistrov Dublennykh Kurpilyanskiy
 * Cormen Leiserson Rivest
 * 
 * результат
 * Ayzenshteyn 2
 * Burmistrov 3
 * Chevdar 3
 * Cormen undefined
 * Dublennykh 2
 * Fominykh 1
 * Isenbaev 0
 * Ivankov 2
 * Kurpilyanskiy 3
 * Leiserson undefined
 * Oparin 1
 * Rivest undefined
 * Samsonov 2
 * Toropov 1
 * 
 */

#include <iostream>
#include <list>
#include <map>
#include <algorithm>
#include <iterator>

int main()
{
  int digit;
  std::list<std::list<std::string>> commands;
  std::map<std::string, int> result;
  bool is_Isenbaev_present{false};
  
  // Составление списка команд из списков фамилий.
  // Одновременно идет поиск фамилии "Isenbaev". Если
  // она присутствует, то устанавливается флаг is_Isenbaev_present.
  std::cin >> digit;
  for(decltype(digit) i{0}; i < digit; ++i) {
    std::string surname;
    std::list<std::string> command;
    for(auto j{0}; j < 3; ++j) {
      std::cin >> surname;
      command.push_back(surname);
      if("Isenbaev" == surname)
        is_Isenbaev_present = true;
    }
    commands.push_back(std::move(command));
  }
  
  // Если во входных данных встретилась фамилия "Isenbaev" выполняются действия...
  if(is_Isenbaev_present) {

    // В результирующий map, где хранятся Фамилии с соответствующим числом Исенбаева
    // добавляется первая запись "Isenbaev":"0".
    digit = 0;
    result["Isenbaev"] = digit;

    // Фамилия "Isenbaev"становится отправной точкой для цикла.
    // Для каждой фамилии в результирующем map будет выполнен поиск по списку команд и фамилий.
    // Если фамилия присутствует в команде, то все фамилии из команды добавляются в результирующий map
    // с текущим числом Исенбаева + 1 = (digit+1); команда удаляется из обрабатываемого списка.
    // Если добавляемая фамилия уже присутствует в результирующем map, повторно она добавлена не
    // будет, также не будет изменено соответствубющее число Исенбаева на бОльшее значение.
    // С каждой итерацией цикла число Исенбаева увеличивается на 1.
    auto searching_for = std::cbegin(result);
    do {
      // В каждой команде ведется поиск фамилии для данной итерации цикла "searching_for".
      // Если фамилия найдена, в результирующий map добавляются все фамилии из команды,
      // в которой было найдено совпадение. Команда удаляется их обработки.
      for(auto command = std::cbegin(commands);
        command != std::cend(commands);) {
        if(std::cend(*command) != std::find(std::cbegin(*command),
                                            std::cend(*command),
                                            searching_for->first)) {
          std::transform(std::cbegin(*command),
                         std::cend(*command),
                         std::inserter(result, result.end()),
                         [digit](const auto& surname) {
                             return std::make_pair(surname, digit+1);
                         });
          command = commands.erase(command);
        }
        else
          ++command;
      }

      // Выбирается фамилия для следующей итерации цикла с текущим числом Исенбаева.
      searching_for = std::find_if(++searching_for,
                                   std::cend(result),
                                   [&digit](const auto& item) {
                                       return digit == item.second;
                                   });

      // Если все фамилии с текущим числом Исинбаева обработаны. Число увеличивается на 1.
      // Выбирается фамилия для следующей итерации цикла с новым числом Исенбаева.
      // Если такоф фамилии нет, цикл завершается.
      if(searching_for == std::cend(result)) {
        ++digit;
        searching_for = std::find_if(std::cbegin(result),
                                     std::cend(result),
                                     [&digit](const auto& item) {
                                         return digit == item.second;
                                     });
      }
    } while(searching_for != std::cend(result));
  }
  
  // Фамилии из оставшихся команд добавляются в результирующий map со значениями "Фамилия":"-1".
  for(const auto& command : commands) {
      std::transform(std::cbegin(command),
                      std::cend(command),
                      std::inserter(result, std::end(result)),
                      [](const auto& surname) {
                          return std::make_pair(surname, -1);
                      });
  }

  for(const auto& item : result)
      std::cout << item.first << ' ' << (item.second == -1 ? "undefined" : std::to_string(item.second)) << std::endl;
}
