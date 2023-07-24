#include"IP_Address.h"
#include"mask.h"



uint8_t main()
{
	setlocale(LC_ALL, "Rus");

	IpAdress ip;
	std::cin >> ip;	
	//std::cout << ip.operator==(ip);
	/*if(ip.ValidAddress())
	{ 
		std::cout <<"Введенный IP-адрес является валидным."  << std::endl;
	}
	else
	{ 
		std::cout << "Введенный IP-адрес не является валидным." << std::endl;
	}*/


	return 0;
}