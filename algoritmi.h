#pragma once
#include<iostream>
int Hrv_abeceda(std::string recenica, int broj) {
	if (recenica[broj] >= 'A' && recenica[broj] <= 'C') return (int)recenica[broj] - 65;
	else if (recenica[broj] >= 'a' && recenica[broj] <= 'c') return recenica[broj] - 97;
	else if (recenica[broj] == 'D' || recenica[broj] == 'd') return 5;
	else if (recenica[broj] >= 'E' && recenica[broj] <= 'S') return (recenica[broj] - 65 + 3);
	else if (recenica[broj] >= 'e' && recenica[broj] <= 's') return (recenica[broj] - 97 + 3);
	else if (recenica[broj] >= 'T' && recenica[broj] <= 'Z') return (recenica[broj] - 65 + 4);
	else if (recenica[broj] >= 't' && recenica[broj] <= 'z') return (recenica[broj] - 97 + 4);

	else if (recenica[broj] == -84 || recenica[broj] == -97) return 3;
	else if (recenica[broj] == -113 || recenica[broj] == -122) return 4;
	else if (recenica[broj] == -47 || recenica[broj] == -48) return 6;
	else if (recenica[broj] == -26 || recenica[broj] == -25) return 22;
	else if (recenica[broj] == -90 || recenica[broj] == -89) return 30;

	return (int)recenica[broj];
}

void Hrv_abeceda(int* recenica, int broj) {
	for (int i = 0; i < broj; i++) {
		if (recenica[i] >= 0 && recenica[i] <= 2) std::cout << (char)(recenica[i] + 65);
		else if (recenica[i] == 3) std::cout << (char)-84;
		else if (recenica[i] == 4) std::cout << (char)-113;
		else if (recenica[i] == 5) std::cout << "D";
		else if (recenica[i] == 6) std::cout << (char)-47;
		else if (recenica[i] >= 7 && recenica[i] <= 21) std::cout << (char)(recenica[i] + 65 - 3);
		else if (recenica[i] == 22) std::cout << (char)-26;
		else if (recenica[i] >= 23 && recenica[i] <= 29) std::cout << (char)(recenica[i] + 65 - 4);
		else if (recenica[i] == 30) std::cout << (char)-90;
		else std::cout << "Greška" << std::endl;
	}
	std::cout << std::endl;
}
int* Convert(std:: string recenica) {
	int* ret = (int*)calloc(recenica.length(), sizeof(int));
	for (int i = 0; i < recenica.length(); i++) {
		ret[i] = Hrv_abeceda(recenica, i);
	}
	return ret;
}
int MonoAbecednaSupstitucija(int slovo, int kljuc) {
	return (slovo + kljuc) % 31;
}
int* PoliAbecednaSupstitucija(int* recenica, int recenica_N, int* kljuc, int kljuc_N) {
	int* rezultat = (int*)calloc(recenica_N, sizeof(int));
	for (int i = 0; i < recenica_N; i++) {
		rezultat[i] = MonoAbecednaSupstitucija(recenica[i], kljuc[i % (kljuc_N)]);
		if (recenica[i] == '-1') {
			std::cout<<"Greška"<<std::endl;
			return 0;
		}
	}
	return rezultat;
}
char MonoAbecednaSupstitucija(char slovo, int kljuc) {
	if (slovo > 96 && slovo <= 122) {
		slovo -= 32;
	}
	if ((kljuc + slovo) < 65 || (kljuc + slovo) > 90)
	{
		slovo-=26;
	}
	return (char)(kljuc + slovo);
}