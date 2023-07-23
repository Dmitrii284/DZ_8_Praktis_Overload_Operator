#include"IP_Address.h"
#include"Functions.h"
#include"mask.h"



uint8_t main()
{
	setlocale(LC_ALL, "Rus");

	IpAdress ip;
	ip.readFromInput(254,220,2,1);
	ip.ValidAddress();


	return 0;
}