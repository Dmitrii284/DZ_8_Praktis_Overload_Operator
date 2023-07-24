#include "IP_Address.h"



IpAdress::IpAdress(uint8_t ip_octet1, uint8_t ip_octet2, uint8_t ip_octet3, uint8_t ip_octet4) :
	_ip_octet1{ ip_octet1 }, _ip_octet2{ ip_octet2 }, _ip_octet3{ ip_octet3 }, _ip_octet4{ ip_octet4 } { }

//IpAdress IpAdress::IpStringConstruct()
//{
//	std::vector<std::string>ipAdresses;			//  Создадим вектор
//	std::string ipString;						// 
//	std::stringstream octec{}(readFromInput()); //
//	std::string segment;
//	while (std::getline(octec, segment, '.')) { // Каждыйсегмент вектора поме
//		ipAdresses.push_back(segment);
//	}
//	for (std::string& ip : ipAdresses)
//		std::cout << ip << '.';	
//}

//void IpAdress::readFromInput(uint8_t _ip_octet1, uint8_t _ip_octet2, uint8_t _ip_octet3, uint8_t _ip_octet4)
//{
//	std::cout << " Enter an IP- address in the format: XXX.XXX.XXX.XXX ->";
//	std::string ipString;
//	std::cin >> ipString;
//	// Разделяем строку на октеты по символу точки и строковые значения _ip_octet переводим в числовые stoi
//	std::size_t pos = ipString.find('.');
//	_ip_octet1 = std::stoi(ipString.substr(0, pos));
//	ipString = ipString.substr(pos + 1);
//	pos = ipString.find('.');
//	_ip_octet2 = std::stoi(ipString.substr(0, pos));
//	ipString = ipString.substr(pos + 1);
//	pos = ipString.find('.');
//	_ip_octet3 = std::stoi(ipString.substr(0, pos));
//	ipString = ipString.substr(pos + 1);
//	_ip_octet4 = std::stoi(ipString);
//}


bool IpAdress::ValidAddress()
{
	if ((_ip_octet1 >= 0 && _ip_octet1 <= 255) &&
		(_ip_octet2 >= 0 && _ip_octet2 <= 255) &&
		(_ip_octet3 >= 0 && _ip_octet3 <= 255) &&
		(_ip_octet4 >= 0 && _ip_octet4 <= 255)) {
		return true;
	}
	/*std::cout <<"Введенный IP-адрес является валидным."  << std::endl;*/
	return false;
}

std::istream& operator>>(std::istream& input, IpAdress& obj)
{
	std::cout << " Enter an IP- address in the format: XXX.XXX.XXX.XXX ->";
	std::string ip_str;
	input >> ip_str;
	
	// Разделяем строку на октеты по символу точки и строковые значения _ip_octet переводим в числовые stoi
	//std::size_t pos = ip_str.find('.'); // В переменную pos с определенным размером - (найденного знака (.)) Присваиваем найденную (.)
	//obj._ip_octet1 = std::stoi(ip_str.substr(0, pos));// Присваиваем обект obj класса IpAdress строку переведенную в число до (.)
	//ip_str = ip_str.substr(pos + 1);// Смещаем нашу введенную строку ip_str на позицию (.) тоесть pos на один шаг (pos + 1)
	//std::size_t pos1 = ip_str.find('.'); // Опять ищем (.)  В нашей укороченной строке от следущего знака после 1-й (.)
	//obj._ip_octet2 = std::stoi(ip_str.substr(0, pos1));// Присваиваем  обект obj класса IpAdress строку переведенную в число до (.)
	//ip_str = ip_str.substr(pos1 + 1); // Присваиваем нашей строке оставшиеся символы (pos + 1) после  (.) 
	//std::size_t pos2 = ip_str.find('.');
	//obj._ip_octet3 = std::stoi(ip_str.substr(0, pos2));
	//ip_str = ip_str.substr(pos2 + 1);
	//obj._ip_octet4 = std::stoi(ip_str);
	
	//char point1 = ip_str.find('.') + 1;	// Ищем (.) в нашей введенной строке ip_str
	//obj._ip_octet1 = std::stoi(ip_str.substr(0, point1 - 1));//  вырезаем данные до точки и переводим их в Число., Присваиваем значение первому аргументу _ip_octet1
	//char point2 = ip_str.find('.') + 1;	// Ищем (.) в нашей введенной строке ip_str
	//obj._ip_octet2 = std::stoi(ip_str.substr(0, point2 - 1));//  вырезаем данные до точки и переводим их в Число.
	//char point3 = ip_str.find('.') + 1;	// Ищем (.) в нашей введенной строке ip_str
	//obj._ip_octet3 = std::stoi(ip_str.substr(0, point3 - 1));//  вырезаем данные до точки и переводим их в Число.
	//ip_str = ip_str.substr(point3 + 1);
	//obj._ip_octet4 = std::stoi(ip_str);//  вырезаем данные до точки и переводим их в Число.

	std::vector<int>octet;
	std::size_t point = ip_str.find('.');
	while (point != ip_str.size()) {
		octet.emplace_back(obj. _ip_octet1 = std::stoi(ip_str.substr('.', point+1)));

		point = ip_str.find('.',point +1);
		octet.emplace_back(obj._ip_octet2 = std::stoi(ip_str.substr(point)));

		point = ip_str.find('.', point + 1);
		octet.emplace_back(obj._ip_octet3 = std::stoi(ip_str.substr(point)));

		point = ip_str.find(point + 1);
		octet.emplace_back(obj._ip_octet4 = std::stoi(ip_str.substr(point)));
	}
	for (auto &it : octet) {
		if ((obj._ip_octet1 >= 0 && obj._ip_octet1 <= 255) &&
			(obj._ip_octet2 >= 0 && obj._ip_octet2 <= 255) &&
			(obj._ip_octet3 >= 0 && obj._ip_octet3 <= 255) &&
			(obj._ip_octet4 >= 0 && obj._ip_octet4 <= 255)) {
			std::cout << it << '.' << std::endl;
			std::cout << " Введенный IP - адрес является валидным." << std::endl;
		}
		std::cout << "Введенный IP-адрес не является валидным." << std::endl;		
	}
	
	return input;
}