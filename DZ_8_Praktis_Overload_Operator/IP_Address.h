#pragma once
#ifndef _IP_ADDRESS_H_
#define _IP_ADDRESS_H_
#include"mask.h"
#include<iostream>
#include<string>

class IpAdress
{
private:
	uint8_t _ip_octet1;
	uint8_t _ip_octet2;
	uint8_t _ip_octet3;
	uint8_t _ip_octet4;	
public:
	IpAdress() = default;	
	IpAdress(uint8_t ip_octet1, uint8_t ip_octet2, uint8_t ip_octet3, uint8_t ip_octet4);

	//void readFromInput(uint8_t _ip_octet1, uint8_t _ip_octet2, uint8_t _ip_octet3, uint8_t _ip_octet4); // Ввод адреса с консоли
	//void IpStringConstruct(); 
	// Метод - член класса. Проверка адреса (чтобы введенные цифры лежали в диапазоне 0 до 255) и (соответствует формату xxx.xxx.xxx.xxx )
	bool ValidAddress();
	//IpAdress IpStringConstruct();			
	// Разделяем строку на октеты по символу точки

	bool operator==(const IpAdress& other) const
	{
		return _ip_octet1 == other._ip_octet1 && _ip_octet2 == other._ip_octet2 && _ip_octet3 == other._ip_octet3 && _ip_octet4 == other._ip_octet4;
	}

	friend std::istream& operator>>(std::istream& input, IpAdress& obj);
	
};

std::istream& operator>>(std::istream& input, IpAdress& obj);

//
//class IPAddress {
//private:
//    int octet1, octet2, octet3, octet4;
//public:
//    void readFromInput() {
//        std::string ipString;
//        std::cin >> ipString;
//
//        // Разделяем строку на октеты по символу точки
//        std::size_t pos = ipString.find('.');
//        octet1 = std::stoi(ipString.substr(0, pos));
//        ipString = ipString.substr(pos + 1);
//        pos = ipString.find('.');
//        octet2 = std::stoi(ipString.substr(0, pos));
//        ipString = ipString.substr(pos + 1);
//        pos = ipString.find('.');
//        octet3 = std::stoi(ipString.substr(0, pos));
//        ipString = ipString.substr(pos + 1);
//        octet4 = std::stoi(ipString);
//    }
//
//    bool isValid() {
//        if (octet1 < 0 || octet1 > 255 ||
//            octet2 < 0 || octet2 > 255 ||
//            octet3 < 0 || octet3 > 255 ||
//            octet4 < 0 || octet4 > 255) {
//            return false;
//        }
//
//        return true;
//    }
//};
//
//int main() {
//    IPAddress ip;
//    std::cout << "Введите IP-адрес в формате xxx.xxx.xxx.xxx: ";
//    ip.readFromInput();
//
//    if (ip.isValid()) {
//        std::cout << "Введенный IP-адрес является валидным." << std::endl;
//    }
//    else {
//        std::cout << "Введенный IP-адрес не является валидным." << std::endl;
//    }
//
//    return 0;
//}


#endif // !_IP_ADDRESS_H_
