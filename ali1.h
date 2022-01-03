/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot:
 * Tekijä: Tuomas Mustakallio
 * Opiskelijanumero: 
 * Päivämäärä: 28.7.2021
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/

#ifndef ali1
#define ali1
#define LEN 80
#define MAX 30

typedef struct data {
	char d_name[MAX];
	int d_amount;
	struct data *pNextData;
}DATA;


typedef struct results {
	char r_name[MAX];
	int number;
	float ka;
	struct results *pNextResult;
}RESULT;

DATA *lue_ohjelma (char *sourceName, DATA *pDataStart, RESULT *pLocation);
void tulosta_tiedot(RESULT *pResultStart, int luku, char *source, DATA *pDataStart);

#endif
/*******************************************************************/
/* eof */