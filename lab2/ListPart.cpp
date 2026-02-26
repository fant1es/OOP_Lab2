module ListPart;
import std;
import Classes;

void listWork()
{
    // Лямбда для красивого вывода всего списка
    auto printList = [](const std::list<Truck>& lst, std::string_view title)
    {
        std::println("=== {} ===", title);

        if (lst.empty())
            std::println("  (список пуст)");
        else
        {
            int idx = 1;
            for (const Truck& truck : lst)
            {
                std::print("[{}] ", idx++);
                truck.getInfo();
            }
        }

        std::println("");
    };

    // Создаём список
    std::list<Truck> truckList;

    // Заполняем список
    truckList.emplace_back(Truck()); // MAN 2.0                     
    truckList.emplace_back(Truck("Volvo", 11.90));
    truckList.emplace_back(Truck("Mercedes", 7.21));
    truckList.emplace_back(Truck("KAMAZ", 5.42));
    truckList.emplace_back(Truck("Scania", 8.83));

    printList(truckList, "Исходный список грузовиков");

    // 1. find_if – ищем первый грузовик с грузоподъёмностью > 10
    std::list<Truck>::iterator it = std::find_if(truckList.begin(), truckList.end(),
        [](const Truck& truck) { return truck.getPayloadCapacity() > 10; });

    //Если не найдет, то попадет на .end()
    if (it != truckList.end())
    {
        std::println("Найден грузовик с грузоподъёмностью > 10:");
        it->getInfo();

        // Вставляем после него новый элемент (используем std::next для безопасного сдвига)
        truckList.emplace(std::next(it), Truck("Ford", 7.77));
        std::println("После него вставлен грузовик Ford (7.77).");
    }
    else
        std::println("Грузовик с грузоподъёмностью > 10 не найден. Вставка отменена.");

    printList(truckList, "После операции вставки");

    // 2. pop_front – удаляем первый элемент (с проверкой на пустоту)
    if (!truckList.empty())
    {
        truckList.pop_front();
        std::println("Первый элемент удалён.");
    }
    else
        std::println("Список пуст, удалять нечего.");

    printList(truckList, "Итоговое состояние списка");
}