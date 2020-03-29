#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "Tamagotchi.h"
using namespace std;


void AfficheLeCombat(string nomJA, string nomJE, int JEdegats, int JEenergie);

int main()
{
	string nomJ1, typeJ1;
	int choix;
	string reponse;
	bool partie = true;
	string nomJ2;
	string terrainJ2;
	int randomNom;

	//Création terrains
	Terrain Ju("Jungle", "Terrain Jungle");
	Terrain Fe("Feu", "Terrain Feu");
	Terrain Ea("Eau", "Terrain d'eau");
	Terrain Te("Terre", "Terrain de terre");

	cout << "Bonjour bienvenue dans le jeux Tamagotchi avec de vrai combats dedans ;) \n";

	//Création Tamagotchi J1
	cout << "Comment s'appelle votre tamagotchi ? \n";
	cin >> nomJ1;
	cout << "Quel est sont type : Feu, Eau, Terre, Jungle \n";
	cin >> typeJ1;

	Tamagotchi J1(nomJ1, typeJ1);

	//Création Joueur 2 
	srand(time(NULL));
	randomNom = rand() % 4 + 1;
	switch (randomNom)
	{
	case 1:
		nomJ2 = "Pika";
		terrainJ2 = "Terre";
		break;
	case 2:
		nomJ2 = "Salame";
		terrainJ2 = "Feu";
		break;
	case 3:
		nomJ2 = "Bulbi";
		terrainJ2 = "Jungle";
		break;
	case 4:
		nomJ2 = "Cara";
		terrainJ2 = "Eau";
	}
	Tamagotchi J2(nomJ2, terrainJ2);
	

	cout << J1.afficheCara();
	cout << J2.afficheCara();
	
	//Menu
	while (partie != false) { 
		cout << "\n\n Que voulez vous faire ? \n 1. Combatre ? \n 2. Entrainement ? \n 3. Nourrir ? \n 4. Jouer avec lui ? \n 5. Dormir ? \n 6. Quitter le jeux ? \n";
		cin >> choix;

		int combatant;
		int typeTerrain;
		int Paschance;		

		switch (choix)
		{
		case 1:
			//Combattre

			//Choisir le terrain
			cout << "==== Initialisation du terrain ==== \n";
			typeTerrain = rand() % 4 + 1;
			switch (typeTerrain)
			{
			case 1: //Jungle
				cout << "Vous êtes sur le " + Ju.nomTerrain + "\n";
				J1.Bonus_Terrain(Ju.typeTerrain);
				J2.Bonus_Terrain(Ju.typeTerrain);
				break;
			case 2: //Feu
				cout << "Vous êtes sur le " + Fe.nomTerrain + "\n";
				J1.Bonus_Terrain(Fe.typeTerrain);
				J2.Bonus_Terrain(Fe.typeTerrain);
				
				break;
			case 3: //Eau
				cout << "Vous êtes sur le " + Ea.nomTerrain + "\n";
				J1.Bonus_Terrain(Ea.typeTerrain);
				J2.Bonus_Terrain(Ea.typeTerrain);
				
				break;
			case 4: //Terre
				cout << "Vous êtes sur le " + Te.nomTerrain + "\n";
				J1.Bonus_Terrain(Te.typeTerrain);
				J2.Bonus_Terrain(Te.typeTerrain);
				
				
			}

			//Combat
			while ((J1.energie > 0) && (J2.energie > 0))
			{
				
				//défini le premier joueur à attaquer
				combatant = rand() % 2 + 1;

				//Malus de précision
				Paschance = rand() % 2;

				if (combatant == 1) { //Joueur 1
					if (J2.energie > 0) { 
						if (Paschance > J1.precision)
						{
							cout << J1.nom + " rate son attaque ! \n";
							J1.rate_son_attaque();
							
						}
						else if (Paschance <= J1.precision) {
							J2 = J1.combattre(J2);
							AfficheLeCombat(J1.nom, J2.nom, J2.nb_degats, J2.energie);
						}

					}
					if (J2.energie <= 0)
					{
						cout << J2.nom << " est KO ! \n" << J1.nom << " a gagné ! \n";
						if (J1.humeur > 100) {
							J1.humeur = 100;
						}
						else {
							J1.humeur += 30;
						}
												
						if (J1.faim < 0)
						{
							J1.faim = 0;
						}
						else {
							J1.faim -= 30;
						}
						
						
					}

				}

				else if (combatant==2){//J2 - Bot
					if (J1.energie > 0) {
						if (Paschance > J2.precision)
						{
							cout << J2.nom + " rate son attaque ! \n";
							J2.rate_son_attaque();
						}
						else if (Paschance <= J2.precision)
						{
							J1 = J2.combattre(J1);
							AfficheLeCombat(J2.nom, J1.nom, J1.nb_degats, J1.energie);
						}
						
					}
					if (J1.energie <= 0)
					{
						cout << J1.nom << " est KO ! \n" << J2.nom << " a gagné ! \n";
						// Modification de l'humeur
						if (J1.humeur < 0) {
							J1.humeur = 0;
						}
						else {
							J1.humeur -= 50;
						}
						// Modification de la faim
						if (J1.faim < 0) {
							J1.faim = 0;
						}
						else {
							J1.faim -= 50;
						}
						
					}
				}

			}
			J2.energie = 100;
		
		break;

		case 2: //Entrainement
			if (J1.precision > 99) {
				cout << J1.nom << "est le plus précis de tous ^^ \n\n";
			}
			else {
				J1.entrainement();
				cout << J1.nom << " c'est bien entrainer \n\n";
			}
			break;

		case 3://Nourir
			if (J1.faim > 100)
			{
				cout << J1.nom << " n'a plus faim !!";
			}
			else if (J1.faim < 100) {
				J1.manger();
				cout << J1.nom << "à bien manger \n\n";
			}
			break;

		case 4: //Jouer
			if (J1.humeur > 99)
			{
				cout << J1.nom << " ne veut pas jouer ! \n\n";
			}
			else {
				J1.jouer();
				cout << J1.nom << "à bien jouer \n\n";
			}
			break;

		case 5: //Dormir
			if (J1.energie > 99)
			{
				cout << J1.nom << " ne veux pas dormir, il réclame une histoire d'abord !!\n";
			}
			else {
				J1.dormir();
				cout << J1.nom << "à bien dormi \n";
			}
			break;
		case 6:
			partie = false;
			break;

		default:
			cout << "Je ne comprends pas votre choix !!";
		}

		if (choix != 6) {
			cout << J1.afficheCara();
		}
		
	}

	cout << "A bientôt !";	
}


void AfficheLeCombat(string nomJA, string nomJE, int JEdegats, int JEenergie)
{
	cout << nomJA << " attaque ! \n";
	cout << nomJE + " perd " + to_string(JEdegats) + " points \n il lui reste point : " + to_string(JEenergie) + "\n\n";
}