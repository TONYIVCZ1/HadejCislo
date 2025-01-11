#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[]){
	int nahoda = 0, uzivatel = 0, napoveda = 50, pokusy = 0, max=1000, vid=0;
	FILE *soubor;
	char *vstupinfo, *vstup;

	soubor = fopen("poslednihra.log", "w");
	if(argc > 1){
		for(int a=1; a < argc; a++){
			vstupinfo = strtok(argv[a], "=");
			vstup = strtok(NULL, "=");

			     if(strstr(vstupinfo, "m")){      max = atoi(vstup); fprintf(soubor, "Maximalni hodnota rucne zmenena: %d \n", max); }
			else if(strstr(vstupinfo, "n")){ napoveda = atoi(vstup); fprintf(soubor, "Napoveda manuálně zmenena: %d \n", napoveda); }
			else if(strstr(vstupinfo, "z")){      vid = atoi(vstup); fprintf(soubor, "Nahodne cislo otevreno v terminalu. \n"); }
		}
	}

//	system("clear");
	printf("Vitejte ve hre 'Hadej cislo'. \n");
	printf("Pocitac vygeneruje nahodne cislo mezi 0-%d a vy musite hadat vygenerovane cislo. \n", max);

	srand(time(NULL));
	nahoda = rand() % max;
	if(vid == 1){ printf("Nahodne cislo: %d \n", nahoda); }
	fprintf(soubor, "Nahodne cislo: %d \n", nahoda);

	while (uzivatel != nahoda){
		uzivatel = 0;
		printf("Zadejte cislo: ");
		scanf("%d", &uzivatel);
		pokusy++;

		fprintf(soubor, "%d : ", uzivatel);
		if(uzivatel > max){
			printf("Zadal jste moc velke cislo. Maximalne je %d. \n", max);
			fprintf(soubor, "Zadal jste moc velke cislo. Maximalne je %d. \n", max);
		}
		else if(uzivatel == nahoda){ break; }
		else{
			if( (nahoda-napoveda) <= uzivatel && uzivatel < nahoda  || (nahoda+napoveda) >= uzivatel && uzivatel > nahoda ){
				printf("Blizite se. Tesne o ");
				fprintf(soubor, "Blizite se. Tesne o ");
				if(uzivatel > nahoda){
					printf("%d \n", uzivatel-nahoda);
					fprintf(soubor, "%d \n", uzivatel-nahoda);
				}
				else{
					printf("%d \n", nahoda-uzivatel);
					fprintf(soubor, "%d \n", nahoda-uzivatel);
				}
			}
			else{
				printf("Sama voda. \n");
				fprintf(soubor, "Sama voda. \n");
			}
		}
	}
	printf("GRATULUJU! Vyhral jste. \n");
	fprintf(soubor, "GRATULUJU! Vyhral jste. \n");
	fprintf(soubor, "Pocet pokusu: %d", pokusy);
	fclose(soubor);


	return 0;
}

