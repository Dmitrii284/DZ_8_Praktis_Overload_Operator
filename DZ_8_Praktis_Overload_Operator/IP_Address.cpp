#include "IP_Address.h"



IpAdress::IpAdress(uint8_t ip_octet1, uint8_t ip_octet2, uint8_t ip_octet3, uint8_t ip_octet4) :
	_ip_octet1{ip_octet1}, _ip_octet2{ip_octet2}, _ip_octet3{ip_octet3}, _ip_octet4{ip_octet4} { }

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

void IpAdress::readFromInput(uint8_t _ip_octet1, uint8_t _ip_octet2, uint8_t _ip_octet3, uint8_t _ip_octet4)
{
	std::cout << " Enter an IP- address in the format: XXX.XXX.XXX.XXX ->";
	std::string ipString;
	std::cin >> ipString;
	// Разделяем строку на октеты по символу точки и строковые значения _ip_octet переводим в числовые stoi
	std::size_t pos = ipString.find('.');
	_ip_octet1 = std::stoi(ipString.substr(0, pos));
	ipString = ipString.substr(pos + 1);
	pos = ipString.find('.');
	_ip_octet2 = std::stoi(ipString.substr(0, pos));
	ipString = ipString.substr(pos + 1);
	pos = ipString.find('.');
	_ip_octet3 = std::stoi(ipString.substr(0, pos));
	ipString = ipString.substr(pos + 1);
	_ip_octet4 = std::stoi(ipString);
}


bool IpAdress::ValidAddress()
{	
	
	if (_ip_octet1 < 0 || _ip_octet1 > 255 || 
		_ip_octet2 < 0 || _ip_octet2 > 255 ||
		_ip_octet3 < 0 || _ip_octet3 > 255 ||
		_ip_octet4 < 0 || _ip_octet4 > 255) {
		std::cout << "Введенный IP-адрес является валидным." << std::endl;
		return true;
	}
	std::cout << "Введенный IP-адрес не является валидным." << std::endl;
	return false;
}
