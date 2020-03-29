#pragma once
#include <string>
#include "ExtraTerrestre.h"
#include "terrain.h"
#include <cstdlib>
#include <time.h>
using namespace std;

class Tamagotchi : public ExtraTerrestre
{
	
public:

	string nom;
	string typeTama;
	int nb_degats;
	int precision;
	

	Tamagotchi (string nom, string typeTama) {
		this->nom = nom;
		this->typeTama = typeTama;
		nb_degats = 0;
		precision = 0;
	}

	Tamagotchi combattre(Tamagotchi ennemi)
	{
		ennemi.nb_degats = rand() % 30 + 1;
		ennemi.degats();
		return ennemi;
	}

	void degats()
	{
		energie -= nb_degats;
	}

	void entrainement()
	{
		if (precision > 100)
		{
			precision = 100;
		}
		else {
			precision += 10;
		}
		
	}

	void rate_son_attaque()
	{
		humeur -= 10;
		if (precision < 0)
		{
			precision = 0;
		}
		else {
			precision -= 3;
		}

	}

	void Bonus_Terrain(string type)
	{
		if (typeTama == type)
		{
			precision += 10;
		}
	}

	string afficheCara() {
		return "\n=============\n Caractéristiques Tamagotchi \n Nom :" + nom + "\n Type :" + typeTama + "\n Energie:" + to_string(energie) + "\n Précision :" + to_string(precision) + "\n Humeur :" + to_string(humeur)  + "\n Faim :" + to_string(faim)+"\n";
	}

};

