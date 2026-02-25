export module Classes;
import std;

export class Truck
{
private:
    std::string model;          
    double payloadCapacity;

public:
    // Конструкторы
    Truck() : model("MAX"), payloadCapacity(2) {}
    Truck(std::string m, double pc) : model{ std::move(m) }, payloadCapacity{ pc } {}

    // Деструктор
    ~Truck() = default;

    // Геттеры
    std::string getModel() const { return model; }
    double getPayloadCapacity() const { return payloadCapacity; }
    // Сеттеры
    void setModel(std::string newModel) { if (!newModel.empty()) model = std::move(newModel); }
    void setPayloadCapacity(double newPayloadCap) { if (newPayloadCap > 0) payloadCapacity = newPayloadCap; }

    void getInfo() const
    {
        std::print(std::cout, "Грузовик: \n");          
        std::print(std::cout, "Модель: {}\n", getModel());
        std::print(std::cout, "Грузоподъемность: {}т\n\n", getPayloadCapacity());
    }
};

// Функтор
export class Transform
{
private:
    double coef;
public:
    // Конструктор
    Transform(double c) : coef{ c } {}
    // Сама операция функтора
    Truck operator()(const Truck& truck) const
    {
        return Truck(truck.getModel(), truck.getPayloadCapacity() * (coef + 1));
    }
};