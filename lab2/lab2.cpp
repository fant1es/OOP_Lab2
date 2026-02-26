// Включение библиотек в соответствии с C++/23
import std;
//Включение модулей 
import VectorPart;
import ListPart;
import MapPart;

int main()
{
	//Все задания в соответствующих модулях
	std::println(std::cout, "====== Задача с std::vector ======");
	vectorWork();

	std::println(std::cout, "\n\n====== Задача с std::list======");
	listWork();

	std::println(std::cout, "\n\n====== Задача с std::map ======");
	mapWork();

}

