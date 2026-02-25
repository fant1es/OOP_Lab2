export module Classes;
import std;

using namespace std;

export class Truck
{
private:
    string model;
    double payloadCapacity;
public:
    // Конструктор по умолчанию
    Truck()
    {
        model = "MAX";
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
        std::print(cout, "Грузовик: \n");
        std::print(cout, "Модель: {}\n", getModel());
        std::print(cout, "Грузоподьемность: {}кг\n\n", getPayloadCapacity());
    }
};

// Функтор для трансформации
export class Transform
{
private:
    double coef;
public:
    // Конструктор функтора
    Transform(double c) : coef{ c } {}

    // Сам метод для определения 
    Truck operator()(const Truck& truck) const
    {
        return Truck(truck.getModel(), truck.getPayloadCapacity() * (coef+1));
    }
};