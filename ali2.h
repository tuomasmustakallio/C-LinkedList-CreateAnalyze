/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot:
 * Tekijä: Tuomas Mustakallio
 * Opiskelijanumero: 
 * Päivämäärä: 28.7.2021
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/

#ifndef ali2
#define ali2
#include "ali1.h"
#define LEN 80

DATA *kasittely_ohjelma(char buffer[], DATA *pDataStart, RESULT *pLocation);
RESULT *analysoi_ohjelma(DATA *pDataStart, RESULT *pResultStart);
void vapauta(DATA *pData, RESULT *pResult);
void tiedostonimi_ohjelma(char *sourceName);

#endif
/*******************************************************************/
/* eof */
