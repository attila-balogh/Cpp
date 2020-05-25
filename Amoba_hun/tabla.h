#pragma once
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class tabla {
public:
	tabla();
	void kezdo();
	void kirajzolas();
	void lepesX();
	void lepesO();
	bool VEGE = false;
	bool hiba();


private:
	bool XVizsgal();
	bool OVizsgal();
	void setXAllas();
	void setOAllas();
	string mezo[11][11];			//MAGA A TABLA (plusz sornev, oszlopnev)
	bool XAllas[11][11];			//MELYIK MEZON VAN X
	bool OAllas[11][11];			//MELYIK MEZON VAN O
};

void tabla::kezdo() {

	cout << "                                                                                                                                   \n";
	cout << "         ******             ********             ********            ******          *************               ******            \n";
	cout << "         ******              *** ***             *** ***         **************       ***       ***              ******            \n";
	cout << "        ***  ***             ***  ***           ***  ***       ****         ****      ***        ***            ***  ***           \n";
	cout << "       ***    ***            ***   ***         ***   ***      ***             ***     ***        ***           ***    ***          \n";
	cout << "      ***      ***           ***    ***       ***    ***      ***             ***     *************           ***      ***         \n";
	cout << "     **************          ***     ***     ***     ***      ***             ***     *************          **************        \n";
	cout << "    ****************         ***      ***   ***      ***      ***             ***     ***        ***        ****************       \n";
	cout << "   ***            ***        ***       *** ***       ***       ****         ****      ***         ***      ***            ***      \n";
	cout << "  ***              ***       ***        *****        ***         **************       ***        ***      ***              ***     \n";
	cout << " *****             *****    *****       *****       *****            ******          **************     *****              *****   \n";
	cout << endl << endl << endl;
	cout << "\t\t\t\t\t*****************************************************\n";
	cout << "\t\t\t\t\t*                                                   *\n";
	cout << "\t\t\t\t\t*                       AMOBA                       *\n";
	cout << "\t\t\t\t\t*                                                   *\n";
	cout << "\t\t\t\t\t* Az nyer, aki elobb tesz le 4 pontot egymas melle! *\n";
	cout << "\t\t\t\t\t*                                                   *\n";
	cout << "\t\t\t\t\t*****************************************************\n";
	cout << "\n\n\n";

}

tabla::tabla() {

	setXAllas();
	setOAllas();

	for (int sor = 0; sor < 11; sor++) {
		for (int oszlop = 0; oszlop < 11; oszlop++) {
			if (sor == 0) {
				switch (oszlop) {
				case 0: mezo[sor][oszlop] = "   ";
					break;
				case 1: mezo[sor][oszlop] = "A ";
					break;
				case 2: mezo[sor][oszlop] = "B ";
					break;
				case 3: mezo[sor][oszlop] = "C ";
					break;
				case 4: mezo[sor][oszlop] = "D ";
					break;
				case 5: mezo[sor][oszlop] = "E ";
					break;
				case 6: mezo[sor][oszlop] = "F ";
					break;
				case 7: mezo[sor][oszlop] = "G ";
					break;
				case 8: mezo[sor][oszlop] = "H ";
					break;
				case 9: mezo[sor][oszlop] = "I ";
					break;
				case 10: mezo[sor][oszlop] = "J ";
					break;
				}
			}
			else mezo[sor][oszlop] = ". ";
			if (oszlop == 0) {
				switch (sor) {
				case 1: mezo[sor][oszlop] = "01 ";
					break;
				case 2: mezo[sor][oszlop] = "02 ";
					break;
				case 3: mezo[sor][oszlop] = "03 ";
					break;
				case 4: mezo[sor][oszlop] = "04 ";
					break;
				case 5: mezo[sor][oszlop] = "05 ";
					break;
				case 6: mezo[sor][oszlop] = "06 ";
					break;
				case 7: mezo[sor][oszlop] = "07 ";
					break;
				case 8: mezo[sor][oszlop] = "08 ";
					break;
				case 9: mezo[sor][oszlop] = "09 ";
					break;
				case 10: mezo[sor][oszlop] = "10 ";
					break;
				}
			}

		}
	}
}

void tabla::kirajzolas() {
	for (int sor = 0; sor < 11; sor++) {
		cout << "\t\t\t\t\t\t\t";
		for (int oszlop = 0; oszlop < 11; oszlop++) {
			cout << mezo[sor][oszlop];
		}
		cout << endl;
	}
	cout << endl;
}

void tabla::setXAllas() {
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			XAllas[i][j] = false;
		}
	}
}

void tabla::setOAllas() {
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			OAllas[i][j] = false;
		}
	}
}

void tabla::lepesX() {
	system("CLS");
	kezdo();
	kirajzolas();
	char c;
	int i;
	bool OK = false;
	while (OK != true) {
		cout << "\t\t\t\t\tX kovetkezik!" << endl << endl;
		cout << "\n\t\t\t\t\tOszlop:\t\t";
		cin >> c;
		cout << "\t\t\t\t\tSor:\t\t";
		cin >> i;
		cout << endl;
		if (((c - 64) > 0) && ((c - 64) < 11) && (i > 0) && (i < 11)) {		//CSAK AKKOR GONDOLKOZZON EL RAJTA, HA SZABALYOS MEZOERTEKET ADTUNK MEG!!!
			if (mezo[i][c - 64] == ". ") {									//CSAK AKKOR RAJZOLJA AT, HA NINCS RAJTA MAS ERTEK!!!
				mezo[i][c - 64] = "X ";
				XAllas[i][c - 64] = true;
				//kirajzolas();
				OK = true;
				cout << endl;
			}
			else cout << "\t\t\t\tSzabalytalan lepes, ott mar van jeloles!\n";
			cout << endl;
		}
		else cout << "\t\t\t\tSzabalytalan lepes, nincs ilyen mezo!\n";
		cout << endl;
	}
	if (XVizsgal()) {
		system("CLS");
		kezdo();
		kirajzolas();
		cout << endl << endl;
		cout << "\t\t\t\t\t\t     ****************************\n";
		cout << "\t\t\t\t\t\t     *                          *\n";
		cout << "\t\t\t\t\t\t     * VEGE A JATEKNAK! X NYERT *\n";
		cout << "\t\t\t\t\t\t     *                          *\n";
		cout << "\t\t\t\t\t\t     ****************************\n";
		VEGE = true;
	}
}


void tabla::lepesO() {
	system("CLS");
	kezdo();
	kirajzolas();
	char c;
	int i;
	bool OK = false;
	while (OK != true) {
		cout << "\t\t\t\t\tO kovetkezik!" << endl << endl;
		cout << "\n\t\t\t\t\tOszlop:\t\t";
		cin >> c;
		cout << "\t\t\t\t\tSor:\t\t";
		cin >> i;
		cout << endl;
		if (((c - 64) > 0) && ((c - 64) < 11) && (i > 0) && (i < 11)) {		//CSAK AKKOR GONDOLKOZZON EL RAJTA, HA SZABALYOS MEZOERTEKET ADTUNK MEG!!!
			if (mezo[i][c - 64] == ". ") {									//CSAK AKKOR RAJZOLJA AT, HA NINCS RAJTA MAS ERTEK!!!
				mezo[i][c - 64] = "O ";
				OAllas[i][c - 64] = true;
				//kirajzolas();
				OK = true;
				cout << endl;
			}
			else cout << "\t\t\t\tSzabalytalan lepes, ott mar van jeloles!\n";
			cout << endl;
		}
		else cout << "\t\t\t\tSzabalytalan lepes, nincs ilyen mezo!\n";
		cout << endl;
	}
	if (OVizsgal()) {
		system("CLS");
		kezdo();
		kirajzolas();
		cout << endl << endl;
		cout << "\t\t\t\t\t\t     ****************************\n";
		cout << "\t\t\t\t\t\t     *                          *\n";
		cout << "\t\t\t\t\t\t     * VEGE A JATEKNAK! O NYERT *\n";
		cout << "\t\t\t\t\t\t     *                          *\n";
		cout << "\t\t\t\t\t\t     ****************************\n";
		VEGE = true;
	}
}

bool tabla::XVizsgal() {
	bool ok = false;
	for (int i = 0; i < 11; i++) {									//VIZSZINTES TALALAT
		for (int j = 0; j < 8; j++) {
			ok = XAllas[i][j] * XAllas[i][j + 1] * XAllas[i][j + 2] * XAllas[i][j + 3];
			if (ok == true) return ok;
		}
	}
	for (int i = 0; i < 8; i++) {									//FUGGOLEGES TALALAT
		for (int j = 0; j < 11; j++) {
			ok = XAllas[i][j] * XAllas[i + 1][j] * XAllas[i + 2][j] * XAllas[i + 3][j];
			if (ok == true) return ok;
		}
	}
	for (int i = 0; i < 8; i++) {									//ATLOS TALALAT 1
		for (int j = 0; j < 8; j++) {
			ok = XAllas[i][j] * XAllas[i + 1][j + 1] * XAllas[i + 2][j + 2] * XAllas[i + 3][j + 3];
			if (ok == true) return ok;
		}
	}
	for (int i = 0; i < 8; i++) {									//ATLOS TALALAT 2
		for (int j = 4; j < 11; j++) {
			ok = XAllas[i][j] * XAllas[i + 1][j - 1] * XAllas[i + 2][j - 2] * XAllas[i + 3][j - 3];
			if (ok == true) return ok;
		}
	}
	return ok;
}

bool tabla::OVizsgal() {
	bool ok = false;
	for (int i = 0; i < 11; i++) {									//VIZSZINTES TALALAT
		for (int j = 0; j < 8; j++) {
			ok = OAllas[i][j] * OAllas[i][j + 1] * OAllas[i][j + 2] * OAllas[i][j + 3];
			if (ok == true) return ok;
		}
	}
	for (int i = 0; i < 8; i++) {									//FUGGOLEGES TALALAT
		for (int j = 0; j < 11; j++) {
			ok = OAllas[i][j] * OAllas[i + 1][j] * OAllas[i + 2][j] * OAllas[i + 3][j];
			if (ok == true) return ok;
		}
	}
	for (int i = 0; i < 8; i++) {									//ATLOS TALALAT 1
		for (int j = 0; j < 8; j++) {
			ok = OAllas[i][j] * OAllas[i + 1][j + 1] * OAllas[i + 2][j + 2] * OAllas[i + 3][j + 3];
			if (ok == true) return ok;
		}
	}
	for (int i = 0; i < 8; i++) {									//ATLOS TALALAT 2
		for (int j = 4; j < 11; j++) {
			ok = OAllas[i][j] * OAllas[i + 1][j - 1] * OAllas[i + 2][j - 2] * OAllas[i + 3][j - 3];
			if (ok == true) return ok;
		}
	}
	return ok;
}

bool tabla::hiba() {
	bool hiba = true;
	int i, j;
	for (i = 1; i < 11; i++) {
		for (j = 1; j < 11; j++) {
			if (mezo[i][j] == ". ") {
				hiba = false;
				break;
			}
		}
	}
	return hiba;
}
