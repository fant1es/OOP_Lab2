module VectorPart;

import std;
import Classes;

void vectorWork()
{
    // Инициализация вектора данными 
    std::vector<Truck> trucks;

    trucks.emplace_back(Truck());
    trucks.emplace_back(Truck("MAN", 7));
    trucks.emplace_back(Truck("Volvo", 11));
    trucks.push_back(Truck("KAMAZ", 5));
    trucks.push_back(Truck("Ford", 6));

    // Вспомогательная функция для печати всего вектора
    auto printAll = [](const std::vector<Truck>& vec, std::string_view title) {
        std::println("=== {} ===", title);

        if (vec.empty()) 
            std::println("  (список пуст)");
        else
        {
            for (std::size_t i = 0; const auto& t : vec) 
            {
                std::print("[{}] ", ++i);
                t.getInfo();
            }
        }

        std::println("");
    };

    // Исходные данные
    printAll(trucks, "Исходный список грузовиков");

    // 1. max_element
    auto maxTruck = std::max_element(trucks.begin(), trucks.end(),
        [](const Truck& left, const Truck& right) 
        { return left.getPayloadCapacity() < right.getPayloadCapacity(); });

    std::println("--- Грузовик с максимальной грузоподъёмностью ---");
    if (maxTruck != trucks.end()) 
    {
        std::print("Самый грузоподъёмный: ");
        maxTruck->getInfo();
    }
    else 
        std::println("Вектор пуст, максимум не определён.");

    std::println("");

    // 2. remove_if (перемещает элементы, не соответствующие условию, в конец)
    auto newEnd = std::remove_if(trucks.begin(), trucks.end(),
        [](const Truck& truck) { return truck.getPayloadCapacity() < 5; });

    // Именно ЗДЕСЬ происходит физическое удаление объектов (стирание)
    // От newEnd до end
    trucks.erase(newEnd, trucks.end());

    printAll(trucks, "После удаления грузовиков с грузоподъёмностью < 5");

    // 3. Transform (создаём новый вектор с изменённой грузоподъёмностью)
    // Используем функтор
    Transform truckTransform(0.1);   
    std::vector<Truck> transformedTrucks;
    std::transform(trucks.begin(), trucks.end(), std::back_inserter(transformedTrucks),
        truckTransform);

    printAll(transformedTrucks, "Трансформированные грузовики (грузоподъёмность * 1.1)");

    // 4. find_if (поиск по модели)
    auto foundTruck = std::find_if(trucks.begin(), trucks.end(),
        [](const Truck& truck) { return truck.getModel() == "MAN"; });

    std::println("--- Поиск грузовика модели 'MAN' ---");
    if (foundTruck != trucks.end()) 
    {
        std::print("Найден: ");
        foundTruck->getInfo();
    }
    else 
        std::println("Грузовик модели 'MAN' не найден.");

    std::println("");

    // 5. sort (сортировка по возрастанию грузоподъёмности)
    std::sort(trucks.begin(), trucks.end(),
        [](const Truck& left, const Truck& right) 
        {
            return left.getPayloadCapacity() < right.getPayloadCapacity();
        });

    printAll(trucks, "После сортировки по возрастанию грузоподъёмности");
}