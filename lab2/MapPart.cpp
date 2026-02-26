module MapPart;
import std;

void mapWork()
{
    // Вспомогательная лямбда для красивого вывода словаря
    auto printMap = [](const auto& m, std::string_view title)
    {
        std::println("{}", title);

        if (m.empty())
            std::println("  (словарь пуст)");
        else
        {
            for (const auto& [city, cost] : m)
            {
                std::println("{:20} : {:8.2f} руб.", city, cost);
            }
        }

        std::println("");
    };

    // Создаём и заполняем словарь стоимостью доставки
    std::map<std::string, double> deliveryCost;
    deliveryCost["Минск"] = 200;
    deliveryCost["Москва"] = 500;
    deliveryCost["Санкт-Петербург"] = 450;
    deliveryCost["Краков"] = 340;
    deliveryCost["Калининград"] = 678;

    printMap(deliveryCost, "=== Исходный словарь стоимости доставки ===");

    // 1. find_if – ищем город "Москва"
    auto find_it = std::find_if(deliveryCost.begin(), deliveryCost.end(),
        [](const auto& pair) { return pair.first == "Москва"; });

    if (find_it != deliveryCost.end()) {
        std::println("Найден город 'Москва': текущая стоимость = {:.2f} руб.", find_it->second);
        // Увеличиваем стоимость на 10%
        find_it->second *= 1.1;
        std::println("После увеличения на 10%: {:.2f} руб.\n", find_it->second);
    }
    else 
        std::println("Город 'Москва' не найден, увеличение не выполнено.\n");

    printMap(deliveryCost, "=== После изменения ===");

    // 2. min_element – находим элемент с минимальной стоимостью
    auto min_it = std::min_element(deliveryCost.begin(), deliveryCost.end(),
        [](const auto& left, const auto& right) {
            return left.second < right.second;
        });

    // Здесь его удаляем через erase()
    if (min_it != deliveryCost.end()) 
    {
        std::println("Элемент с минимальной стоимостью: {} = {:.2f} руб.",
            min_it->first, min_it->second);

        deliveryCost.erase(min_it);
        std::println("Минимальный элемент удалён.\n");
    }
    else 
        std::println("Словарь пуст, удаление невозможно.\n");

    printMap(deliveryCost, "=== Итоговый словарь после удаления минимума ===");
}