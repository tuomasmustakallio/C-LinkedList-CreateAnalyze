/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot:
 * Tekijä: Tuomas Mustakallio
 * Opiskelijanumero: 
 * Päivämäärä: 28.7.2021
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ali1.h"
#include "ali2.h"
#include "HT.h"
 
DATA *lue_ohjelma (char *sourceName, DATA *pDataStart, RESULT *pLocation) {

    FILE *source;
	DATA *pNewData, *ptr; 
	char buffer[LEN];
	ptr = pDataStart;
	
	while (ptr != NULL) {
		pDataStart = ptr->pNextData;
		free(ptr);
		ptr = pDataStart;
	}
	

	if((source = fopen(sourceName, "r")) == NULL){
		perror("Tiedoston avaaminen epäonnistui");
		vapauta(pDataStart, pLocation);
		exit(0);
	}

	fgets(buffer, LEN, source);
	while(fgets(buffer, LEN, source) != NULL){
		pNewData = kasittely_ohjelma(buffer, pDataStart, pLocation);
		if(pDataStart == NULL){
			pDataStart = pNewData;
			ptr = pDataStart;
		} else {
			ptr->pNextData = pNewData;
			ptr = pNewData;
		}
	}
	ptr->pNextData = NULL;

	printf("Tiedosto '%s' luettu.\n\n", sourceName);
	fclose(source);
	return pDataStart;
}

void tulosta_tiedot(RESULT *pResultStart, int pass, char *source, DATA *pDataStart) {

	RESULT *ptr2 = pResultStart;
	FILE *storage;
	char storagename[50];
    char ke;

	printf("Tulosta tiedostoon (k/e): ");
	scanf("%c", &ke);
	getchar();

	if(ke == 'k'){
		tiedostonimi_ohjelma(storagename);
		storage = fopen(storagename, "w");
		if(storage == NULL){
			perror("Tiedoston avaaminen epäonnistui");
			vapauta(pDataStart, pResultStart);
			exit(0);
		}
		fprintf(storage,"Analysoitiin tiedosto '%s'.\n",source);
		fprintf(storage,"Tiedostossa oli yhteensä %d eri nimeä ja ", ptr2->number);
		ptr2 = ptr2->pNextResult;
		fprintf(storage,"yleisin nimi oli '%s', joka oli %d ihmisellä.\n", ptr2->r_name, ptr2->number);
		ptr2 = ptr2->pNextResult;
		fprintf(storage,"Lyhyin nimi oli %d merkkiä pitkä '%s' ja ", ptr2->number, ptr2->r_name);
		ptr2 = ptr2->pNextResult;
		fprintf(storage,"pisin oli %d merkkiä pitkä '%s'.\n", ptr2->number, ptr2->r_name);
		ptr2 = ptr2->pNextResult;
		fprintf(storage,"Nimien keskimääräinen pituus oli %.f merkkiä.\n", ptr2->ka);
		fclose(storage);
		printf("\n");

	} else if(ke == 'e'){
		printf("Analysoitiin tiedosto '%s'.\n",source);
		printf("Tiedostossa oli yhteensä %d eri nimeä ja ", ptr2->number);
		ptr2 = ptr2->pNextResult;
		printf("yleisin nimi oli '%s', joka oli %d ihmisellä.\n", ptr2->r_name, ptr2->number);
		ptr2 = ptr2->pNextResult;
		printf("Lyhyin nimi oli %d merkkiä pitkä '%s' ja ", ptr2->number, ptr2->r_name);
		ptr2 = ptr2->pNextResult;
		printf("pisin oli %d merkkiä pitkä '%s'.\n", ptr2->number, ptr2->r_name);
		ptr2 = ptr2->pNextResult;
		printf("Nimien keskimääräinen pituus oli %.f merkkiä.\n", ptr2->ka);
		printf("\n");
	}

	return;
}
/*******************************************************************/
/* eof */