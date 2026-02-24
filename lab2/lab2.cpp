#include <iostream>
#include <vector>
#include <format>

using namespace std;

class Truck 
{
private:
    string model;
    double payloadCapacity;
public:
    // Конструктор по умолчанию
    Truck()
    {
        model = "MAN";
        payloadCapacity = 2;
    }

    // Параметрический конструктор
    Truck(string m, double pc) : model{ m }, payloadCapacity{ pc } {}

    //Деструктор
    ~Truck() {};

    // Геттеры
    string getModel() const { return model; }
    double getPayloadCapacity() const { return payloadCapacity; }

    // Сеттеры
    void setModel(string newModel) { if (newModel != "") model = newModel; }
    void setPayloadCapacity(double newPayloadCap) { if (newPayloadCap > 0) payloadCapacity = newPayloadCap; }

    // Информация по классу
    void getInfo() const
    {
        std::print(cout, "Грузовик:\n");
        std::print(cout, "Модель:{}\n", getModel());
        std::print(cout, "Грузоподьемность:{}кг\n\n", getPayloadCapacity());
    }
};  


int main()
{
    // Инициализация вектора данными 
    vector<Truck> trucks;

    trucks.emplace_back(Truck());
    trucks.emplace_back(Truck("MAZ", 7));
    trucks.emplace_back(Truck("Volvo", 11));
    trucks.push_back(Truck("KAMAZ", 5));
    trucks.push_back(Truck("Ford", 6));
    
    // Применение алгоритмов
    // 1. max_element
    vector<Truck>::const_iterator maxTruck = std::max_element(trucks.begin(), trucks.end(),
        [](const Truck& left, const Truck& right) {return left.getPayloadCapacity() < right.getPayloadCapacity(); });

    std::print(cout, "Грузовик с максимальной грузоподьемностью:\n");
    maxTruck->getInfo();

    // 2. remove_if
    vector<Truck>::const_iterator newEnd = std::remove_if(trucks.begin(), trucks.end(),
        [](const Truck& truck) {return truck.getPayloadCapacity() < 5; });
    // Именно ЗДЕСЬ происходит удаление обьектов
    trucks.erase(newEnd, trucks.end());
}

