#include<iostream>
#include"algoritmi.h"
#include <windows.h>
#include <shellapi.h>
void switcher()
{
	system("CLS");
	int n = 5;
	std::cout << "1. Najkraci put izmedu cvorova (Djikstra)" << std::endl;
	std::cout << "2. Monoabecedna supstitucija" << std::endl;
	std::cout << "3. Poliabecedna supstitucija (Vigenere)" << std::endl;
	std::cout << "4. Desifriranje kljuceva" << std::endl;
	std::cout << "0. Izlaz" << std::endl;
	std::cout << "Unesite odabir:" << std::endl;
	do{std::cin >> n;} while (n < 0 || n>4);
	std::string recenica;
	std::string kljuc;
	int intkljuc, provjera=0;
	switch (n)
	{
	case 1:
	{
		system("CLS");
		std::cout << "Otvaram web stranicu." << std::endl;
		ShellExecute(0, 0, L"https://graphonline.ru/en/", 0, 0, SW_SHOW);
		std::cout << "Ako zelite nazad na odabir unesite 1." << std::endl;
		std::cin >> provjera;
		if (provjera == 1)
		{
			switcher();
			break;
		}
		else
			break;
	}
	case 2:
	{
		system("CLS");
		std::cout << "Unesite recenicu: (Tekst bez razmaka, Engleski)" << std::endl;
		std::cin >> recenica;
		std::cout << "Unesite kljuc: (Broj bez razmaka)" << std::endl;
		std::cin >> intkljuc;
		for (int i = 0; i < recenica.length(); i++) {
			recenica[i] = MonoAbecednaSupstitucija(recenica[i], intkljuc);
		}
		std::cout << recenica << std::endl;
		std::cout << "Ako zelite nazad na odabir unesite 1." << std::endl;
		std::cin >> provjera;
		if (provjera == 1)
		{
			switcher();
			break;
		}
		else
			break;
	}
	case 3:
	{
		system("CLS");
		std::cout << "Unesite recenicu (Tekst bez razmaka, Hrvatski):" << std::endl;
		std::cin >> recenica;
		std::cout << "Unesite kljuc (Tekst bez razmaka, Hrvatski):" << std::endl;
		std::cin >> kljuc;
		int* Recenica = Convert(recenica);
		int* Kljuc = Convert(kljuc);
		int* rezultat = PoliAbecednaSupstitucija(Recenica, recenica.length(), Kljuc, kljuc.length());
		Hrv_abeceda(rezultat, recenica.length());
		std::cout << "Ako zelite nazad na odabir unesite 1." << std::endl;
		std::cin >> provjera;
		if (provjera == 1)
		{
			switcher();
			break;
		}
		else
			break;
	}
	case 4:
	{
		system("CLS");
		std::cout << "Koliko kljuceva imate?" << std::endl;
		int N;
		std::cin >> N;
		float** kljucevi = (float**)calloc(N, sizeof(float));
		std::cout << "Unesite parove x,y." << std::endl;
		for (int i = 0; i < N; i++) {
			kljucevi[i] = (float*)calloc(2, sizeof(float));
			std::cout << "x =" << std::endl;
			std::cin >> kljucevi[i][0];
			std::cout << "y =" << std::endl;
			std::cin >> kljucevi[i][1];
		}
		float tajna = 0;
		float umnozak;
		for (int i = 0; i < N; i++) {
			umnozak = 1;
			for (int j = 0; j < N; j++) {
				if (i == j) continue;
				umnozak *= kljucevi[j][0] / (kljucevi[j][0] - kljucevi[i][0]);
			}
			tajna += umnozak * kljucevi[i][1];
		}
		std::cout << "Tajna je: " << tajna << std::endl;
		std::cout << "Ako zelite nazad na odabir unesite 1." << std::endl;
		std::cin >> provjera;
		if (provjera == 1)
		{
			switcher();
			break;
		}
		else
			break;
	}
	case 0:
	{
		break;
	}
}
}
int main()
{
	switcher();
	return 0;
}