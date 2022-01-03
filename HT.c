/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot:
 * Tekijä: Tuomas Mustakallio
 * Opiskelijanumero: 
 * Päivämäärä: 28.7.2021
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ali1.h"
#include "ali2.h"
#define LEN 80

int valikko(void) {
    int choice;
    printf("Valitse haluamasi toiminto alla olevasta valikosta:\n");
    printf("1) Lue tiedosto\n");
    printf("2) Analysoi tiedot\n");
    printf("3) Tulosta tulokset\n");
    printf("0) Lopeta\n");
    printf("Anna valintasi: ");
    scanf("%d", &choice);
    getchar();
    return choice;
}

int main(void) {
    char sourceName[LEN];
    DATA *pDataStart = NULL;
    RESULT pResultStart[70];
    RESULT *pLocation = NULL;
	int choice = -1, pass = 0;
    printf("Tämä ohjelma tutkii nimitietoja sisältäviä tiedostoja.\n");
    while (choice != 0){
        choice = valikko();
        if (choice == 1){
            tiedostonimi_ohjelma(sourceName);
            pDataStart = lue_ohjelma(sourceName, pDataStart, pLocation);
            continue;
        }
        if (choice == 2){
            if(pDataStart == NULL){
                printf("Ei analysoitavaa, lue tiedosto ennen analyysiä.\n\n");
            }else{
                pLocation = analysoi_ohjelma(pDataStart, pResultStart);
            }
            continue;
        }
        if (choice == 3){
            if(pLocation == NULL){
		        printf("Ei tulostettavaa, analysoi data ennen tulostusta.\n\n");
	        }else{
                tulosta_tiedot(pLocation, pass, sourceName, pDataStart);
            }
            continue;
        }
        if (choice == 0){
            vapauta(pDataStart, pResultStart);
            printf("Kiitos ohjelman käytöstä.\n\n");
            break;
        }
        else{
            printf("Valintaa ei tunnistettu, yritä uudestaan.\n\n");
            continue;
        }
    }
}

/*******************************************************************/
/* eof */