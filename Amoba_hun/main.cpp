#include <iostream>
#include <string>
#include <cstdlib>
#include "tabla.h"


using namespace std;



int main() {


	tabla mezo;


	mezo.kezdo();
	mezo.kirajzolas();


	while (!mezo.VEGE) {
		mezo.lepesX();
		if (mezo.VEGE == true) break;
		mezo.lepesO();
		if (mezo.hiba()) {
			mezo.kirajzolas();
			cout << "\nELFOGYTAK A LEHETOSEGEK! NEM NYERT SENKI!\n\n";
			break;
		}
	}


	cout << endl << endl;

	system("pause");



	return 0;
}


