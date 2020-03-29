#pragma once
class ExtraTerrestre
{

public:

	int energie;
	int humeur;
	int faim;

	ExtraTerrestre() {
		energie = 100;
		humeur = 100;
		faim = 100;
	}

	void manger() {
		// remise 
		faim = 100;
		
		if (humeur < 0) //si l'humeur est inferieur à 0 ont la met à 10 directement, pour ne pas avoir de chiffre négatif
		{
			humeur = 10;
		}
		else if (humeur > 100) // si l'humeur est suppérieur à 100 ou la remet à 100 pour ne pas avoir de chiffre à + de 100
		{
			humeur = 100;
		}
		else {
			humeur += 10;
		}
	
		
		if (energie < 0) {
			energie = 50;
		}
		else if(energie > 100){
			energie = 100;
		}
		else {
			energie += 50;
		}

		
	}

	void dormir() {
		energie = 100;
				
		if (faim < 0)
		{
			faim = 0;
		}
		else if (faim > 100) {
			faim = 100;
		}
		else {
			faim -= 50;
		}
		
		
		if (humeur < 0) {
			humeur = 0;
		}
		else if (humeur > 100) {
			humeur = 100;
		}
		else {
			humeur -= 30;
		}
	}

	void jouer() {
		humeur = 100; 

		
		if (faim < 0)
		{
			faim = 0;
		}
		else if(faim > 100){
			faim = 100;
		}
		else {
			faim -= 30;
		}
		
		
		if (energie < 0) {
			energie = 0;
		}
		else if (energie > 100) {
			energie = 100;
		}
		else {
			energie -= 50;
		}
	}
};

