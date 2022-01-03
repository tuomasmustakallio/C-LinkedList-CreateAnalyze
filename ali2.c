/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot:
 * Tekijä: Tuomas Mustakallio
 * Opiskelijanumero: 
 * Päivämäärä: 28.7.2021
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/

#include "ali1.h"
#include "ali2.h"
#include "HT.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


DATA *kasittely_ohjelma(char buffer[], DATA *pDataStart, RESULT *pLocation) {

	char *p1, *p2;
	int num = 0;
	DATA *pNewData;

	if ((pNewData = (DATA*)malloc(sizeof(DATA))) == NULL ){
			perror("Muistin varaus epäonnistui\n");
			vapauta(pDataStart, pLocation);
			exit(0);
	}

	p1 = strtok(buffer, ";");
	strcpy(pNewData->d_name, p1);
	p2 = strtok(NULL, ";");
	num = atoi(p2);
	pNewData->d_amount = num;

	return pNewData;
}

RESULT *analysoi_ohjelma(DATA *pDataStart, RESULT *pResultStart){

	DATA *ptr, *ptrPopular, *ptrLongest, *ptrShortest;
	
	if(ptrShortest != NULL){
		free(ptrShortest);
	}
	if(ptrPopular != NULL){
		free(ptrPopular);
	}
	if(ptrLongest != NULL){
		free(ptrLongest);
	}

	RESULT *ptr2, *ptrNewResult;
	ptr2 = pResultStart;

	if(ptr2->pNextResult != NULL){
		while (ptr2 != NULL) {
			pResultStart = ptr2->pNextResult;
			free(ptr2);
			ptr2 = pResultStart;
		}
	}

	int fame = 0, longest = 0, nameAmount = 0, shortest = 100;
	int shortfame = 0, longfame = 0;
	int length = 0;
	double avg = 0, sum = 0;

	ptr = pDataStart;
	while(ptr != NULL){
		if(ptr->d_amount > fame){
			fame = ptr->d_amount;
			ptrPopular = ptr;
		}
		length=strlen(ptr->d_name);
		if(length>=longest){
			if(longest == length && ptr->d_amount > longfame){
				longest = length;
				ptrLongest = ptr;
				longfame = ptr->d_amount;
			}else if(length >longest){
			longest = length;
			ptrLongest = ptr;
			longfame = ptr->d_amount;
			}
		}
		if(length<=shortest){
			if(shortest == length && ptr->d_amount > shortfame){
				shortest = length;
				ptrShortest = ptr;
				shortfame = ptr->d_amount;
			}else if(length < shortest){
				shortest = length;
				ptrShortest = ptr;
				shortfame = ptr->d_amount;
			}
		}
		sum = sum + length;
		nameAmount = nameAmount + 1;
		ptr = ptr->pNextData;
	}
	avg = sum/nameAmount;

	if ((ptrNewResult = (RESULT*)malloc(sizeof(RESULT))) == NULL ){
			perror("Muistin varaus epäonnistui\n");
			vapauta(pDataStart, pResultStart);
			exit(0);
	}
	RESULT *pLocation = ptrNewResult;
	ptrNewResult->number = nameAmount;
	ptrNewResult->pNextResult = NULL;
	if (pResultStart == NULL) {
		pResultStart = ptrNewResult;
	} else {
		ptr2 = pResultStart;
		while (ptr2->pNextResult != NULL)
			ptr2 = ptr2->pNextResult;
		ptr2->pNextResult = ptrNewResult;
	}

	if ((ptrNewResult = (RESULT*)malloc(sizeof(RESULT))) == NULL ){
			perror("Muistin varaus epäonnistui\n");
			vapauta(pDataStart, pResultStart);
			exit(0);
	}
	strcpy(ptrNewResult->r_name, ptrPopular->d_name);
	ptrNewResult->number = ptrPopular->d_amount;
	ptrNewResult->pNextResult = NULL;
	if (pResultStart == NULL) {
		pResultStart = ptrNewResult;
	} else {
		ptr2 = pResultStart;
		while (ptr2->pNextResult != NULL)
			ptr2 = ptr2->pNextResult;
		ptr2->pNextResult = ptrNewResult;
	}

	if ((ptrNewResult = (RESULT*)malloc(sizeof(RESULT))) == NULL ){
			perror("Muistin varaus epäonnistui\n");
			vapauta(pDataStart, pResultStart);
			exit(0);
	}
	strcpy(ptrNewResult->r_name, ptrShortest->d_name);
	ptrNewResult->number = shortest;
	ptrNewResult->pNextResult = NULL;
	if (pResultStart == NULL) {
		pResultStart = ptrNewResult;
	} else {
		ptr2 = pResultStart;
		while (ptr2->pNextResult != NULL)
			ptr2 = ptr2->pNextResult;
		ptr2->pNextResult = ptrNewResult;
	}

	if ((ptrNewResult = (RESULT*)malloc(sizeof(RESULT))) == NULL ){
			perror("Muistin varaus epäonnistui\n");
			vapauta(pDataStart, pResultStart);
			exit(0);
	}
	strcpy(ptrNewResult->r_name, ptrLongest->d_name);
	ptrNewResult->number = longest;
	ptrNewResult->pNextResult = NULL;
	if (pResultStart == NULL) {
		pResultStart = ptrNewResult;
	} else {
		ptr2 = pResultStart;
		while (ptr2->pNextResult != NULL)
			ptr2 = ptr2->pNextResult;
		ptr2->pNextResult = ptrNewResult;
	}

	if ((ptrNewResult = (RESULT*)malloc(sizeof(RESULT))) == NULL ){
			perror("Muistin varaus epäonnistui\n");
			vapauta(pDataStart, pResultStart);
			exit(0);
	}

	ptrNewResult->ka = avg;
	ptrNewResult->pNextResult = NULL;
	if (pResultStart == NULL) {
		pResultStart = ptrNewResult;
	} else {
		ptr2 = pResultStart;
		while (ptr2->pNextResult != NULL)
			ptr2 = ptr2->pNextResult;
		ptr2->pNextResult = ptrNewResult;
	}
	printf("Analysoitiin %d tietuetta.\n\n",nameAmount);
	return pLocation;
}

void vapauta(DATA *pData, RESULT *pResult) {

	DATA *ptr;
	if(pData != NULL){
		while(ptr != NULL){
			ptr = pData->pNextData;
			free(pData);
			pData = ptr;
		}
	}

	RESULT *ptr2;
	if(pResult != NULL){
		while(ptr2 != NULL){
			ptr2 = pResult->pNextResult;
			free(pResult);
			pResult = ptr2;
		}
	}
}

void tiedostonimi_ohjelma(char *sourceName) {
    printf("Anna tiedoston nimi: ");
    fgets(sourceName, LEN, stdin);
	sourceName[strlen(sourceName)-1] = '\0';
}

/*******************************************************************/
/* eof */