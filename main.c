#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "light_ws2812.h"
#include <stdio.h>
#include <string.h>

void setLetter(struct cRGB*, char);
void clearArray(struct cRGB*);
void fillColumn(struct cRGB*, struct cRGB*, int, int);

struct cRGB colors[64];

int main(void)
{
	//char greeting[] = "áãóèð êñèñ âìñèñ";
	char greeting[] = "ççç";
	struct cRGB letterOne[64];
	struct cRGB letterTwo[64];
	int i, j, k, colFilled, colToFill, flag;
	int length = strlen(greeting);
	while(1) {
		for(i = 0; i < length; i++) {
			if(i == length-1) {
				j = 0;
			} else {
				j = i + 1;
			}
			clearArray(letterOne);
			clearArray(letterTwo);
			setLetter(letterOne, greeting[i]);
			setLetter(letterTwo, greeting[j]);
			for(k = 0; k < 8; k++) {
				colToFill = k;
				ws2812_setleds(colors, 64);
				for(colFilled = 0; colFilled < 8; colFilled++) {
					if(colToFill >= 8) {
						fillColumn(colors, letterTwo, colFilled, colToFill-8);
						colToFill += 1;
					} else {
						fillColumn(colors, letterOne, colFilled, colToFill);
						colToFill += 1;
					}
				}
				_delay_ms(80);
			}
		}
	}
}

void setLetter(struct cRGB* letterArr, char letter)
{
	switch(letter) {
		case 'à': {
			letterArr[10].r=190; letterArr[10].g=15; letterArr[10].b=209;
			letterArr[11].r=190; letterArr[11].g=15; letterArr[11].b=209;
			letterArr[12].r=190; letterArr[12].g=15; letterArr[12].b=209;
			letterArr[13].r=190; letterArr[13].g=15; letterArr[13].b=209;
			letterArr[14].r=190; letterArr[14].g=15; letterArr[14].b=209;
			letterArr[15].r=190; letterArr[15].g=15; letterArr[15].b=209;
			letterArr[17].r=190; letterArr[17].g=15; letterArr[17].b=209;
			letterArr[20].r=190; letterArr[20].g=15; letterArr[20].b=209;
			letterArr[24].r=190; letterArr[24].g=15; letterArr[24].b=209;
			letterArr[28].r=190; letterArr[28].g=15; letterArr[28].b=209;
			letterArr[32].r=190; letterArr[32].g=15; letterArr[32].b=209;
			letterArr[36].r=190; letterArr[36].g=15; letterArr[36].b=209;
			letterArr[40].r=190; letterArr[40].g=15; letterArr[40].b=209;
			letterArr[44].r=190; letterArr[44].g=15; letterArr[44].b=209;
			letterArr[49].r=190; letterArr[49].g=15; letterArr[49].b=209;
			letterArr[50].r=190; letterArr[50].g=15; letterArr[50].b=209;
			letterArr[51].r=190; letterArr[51].g=15; letterArr[51].b=209;
			letterArr[52].r=190; letterArr[52].g=15; letterArr[52].b=209;
			letterArr[53].r=190; letterArr[53].g=15; letterArr[53].b=209;
			letterArr[54].r=190; letterArr[54].g=15; letterArr[54].b=209;
			letterArr[55].r=190; letterArr[55].g=15; letterArr[55].b=209;
			break;
		}
		case 'á': {
			letterArr[8].r=190;  letterArr[8].g=15;  letterArr[8].b=209;
			letterArr[9].r=190;  letterArr[9].g=15;  letterArr[9].b=209;
			letterArr[10].r=190; letterArr[10].g=15; letterArr[10].b=209;
			letterArr[11].r=190; letterArr[11].g=15; letterArr[11].b=209;
			letterArr[12].r=190; letterArr[12].g=15; letterArr[12].b=209;
			letterArr[13].r=190; letterArr[13].g=15; letterArr[13].b=209;
			letterArr[14].r=190; letterArr[14].g=15; letterArr[14].b=209;
			letterArr[15].r=190; letterArr[15].g=15; letterArr[15].b=209;
			letterArr[16].r=190; letterArr[16].g=15; letterArr[16].b=209;
			letterArr[19].r=190; letterArr[19].g=15; letterArr[19].b=209;
			letterArr[23].r=190; letterArr[23].g=15; letterArr[23].b=209;
			letterArr[24].r=190; letterArr[24].g=15; letterArr[24].b=209;
			letterArr[27].r=190; letterArr[27].g=15; letterArr[27].b=209;
			letterArr[31].r=190; letterArr[31].g=15; letterArr[31].b=209;
			letterArr[32].r=190; letterArr[32].g=15; letterArr[32].b=209;
			letterArr[35].r=190; letterArr[35].g=15; letterArr[35].b=209;
			letterArr[39].r=190; letterArr[39].g=15; letterArr[39].b=209;
			letterArr[40].r=190; letterArr[40].g=15; letterArr[40].b=209;
			letterArr[43].r=190; letterArr[43].g=15; letterArr[43].b=209;
			letterArr[47].r=190; letterArr[47].g=15; letterArr[47].b=209;
			letterArr[48].r=190; letterArr[48].g=15; letterArr[48].b=209;
			letterArr[52].r=190; letterArr[52].g=15; letterArr[52].b=209;
			letterArr[53].r=190; letterArr[53].g=15; letterArr[53].b=209;
			letterArr[54].r=190; letterArr[54].g=15; letterArr[54].b=209;
			break;
		}
		case 'â': {
			letterArr[8].r=190;  letterArr[8].g=15;  letterArr[8].b=209;
			letterArr[9].r=190;  letterArr[9].g=15;  letterArr[9].b=209;
			letterArr[10].r=190; letterArr[10].g=15; letterArr[10].b=209;
			letterArr[11].r=190; letterArr[11].g=15; letterArr[11].b=209;
			letterArr[12].r=190; letterArr[12].g=15; letterArr[12].b=209;
			letterArr[13].r=190; letterArr[13].g=15; letterArr[13].b=209;
			letterArr[14].r=190; letterArr[14].g=15; letterArr[14].b=209;
			letterArr[15].r=190; letterArr[15].g=15; letterArr[15].b=209;
			letterArr[16].r=190; letterArr[16].g=15; letterArr[16].b=209;
			letterArr[19].r=190; letterArr[19].g=15; letterArr[19].b=209;
			letterArr[23].r=190; letterArr[23].g=15; letterArr[23].b=209;
			letterArr[24].r=190; letterArr[24].g=15; letterArr[24].b=209;
			letterArr[27].r=190; letterArr[27].g=15; letterArr[27].b=209;
			letterArr[31].r=190; letterArr[31].g=15; letterArr[31].b=209;
			letterArr[32].r=190; letterArr[32].g=15; letterArr[32].b=209;
			letterArr[35].r=190; letterArr[35].g=15; letterArr[35].b=209;
			letterArr[39].r=190; letterArr[39].g=15; letterArr[39].b=209;
			letterArr[40].r=190; letterArr[40].g=15; letterArr[40].b=209;
			letterArr[43].r=190; letterArr[43].g=15; letterArr[43].b=209;
			letterArr[47].r=190; letterArr[47].g=15; letterArr[47].b=209;
			letterArr[49].r=190; letterArr[49].g=15; letterArr[49].b=209;
			letterArr[50].r=190; letterArr[50].g=15; letterArr[50].b=209;
			letterArr[52].r=190; letterArr[52].g=15; letterArr[52].b=209;
			letterArr[53].r=190; letterArr[53].g=15; letterArr[53].b=209;
			letterArr[54].r=190; letterArr[54].g=15; letterArr[54].b=209;
			break;
		}
		case 'ã': {
			letterArr[8].r=190;  letterArr[8].g=15;  letterArr[8].b=209;
			letterArr[9].r=190;  letterArr[9].g=15;  letterArr[9].b=209;
			letterArr[10].r=190; letterArr[10].g=15; letterArr[10].b=209;
			letterArr[11].r=190; letterArr[11].g=15; letterArr[11].b=209;
			letterArr[12].r=190; letterArr[12].g=15; letterArr[12].b=209;
			letterArr[13].r=190; letterArr[13].g=15; letterArr[13].b=209;
			letterArr[14].r=190; letterArr[14].g=15; letterArr[14].b=209;
			letterArr[15].r=190; letterArr[15].g=15; letterArr[15].b=209;
			letterArr[16].r=190; letterArr[16].g=15; letterArr[16].b=209;
			letterArr[24].r=190; letterArr[24].g=15; letterArr[24].b=209;
			letterArr[32].r=190; letterArr[32].g=15; letterArr[32].b=209;
			letterArr[40].r=190; letterArr[40].g=15; letterArr[40].b=209;
			letterArr[48].r=190; letterArr[48].g=15; letterArr[48].b=209;
			break;
		}
		case 'ä': {
			letterArr[14].r=190; letterArr[14].g=15; letterArr[14].b=209;
			letterArr[15].r=190; letterArr[15].g=15; letterArr[15].b=209;
			letterArr[17].r=190; letterArr[17].g=15; letterArr[17].b=209;
			letterArr[18].r=190; letterArr[18].g=15; letterArr[18].b=209;
			letterArr[19].r=190; letterArr[19].g=15; letterArr[19].b=209;
			letterArr[20].r=190; letterArr[20].g=15; letterArr[20].b=209;
			letterArr[21].r=190; letterArr[21].g=15; letterArr[21].b=209;
			letterArr[22].r=190; letterArr[22].g=15; letterArr[22].b=209;
			letterArr[24].r=190; letterArr[24].g=15; letterArr[24].b=209;
			letterArr[30].r=190; letterArr[30].g=15; letterArr[30].b=209;
			letterArr[32].r=190; letterArr[32].g=15; letterArr[32].b=209;
			letterArr[38].r=190; letterArr[38].g=15; letterArr[38].b=209;
			letterArr[41].r=190; letterArr[41].g=15; letterArr[41].b=209;
			letterArr[42].r=190; letterArr[42].g=15; letterArr[42].b=209;
			letterArr[43].r=190; letterArr[43].g=15; letterArr[43].b=209;
			letterArr[44].r=190; letterArr[44].g=15; letterArr[44].b=209;
			letterArr[45].r=190; letterArr[45].g=15; letterArr[45].b=209;
			letterArr[46].r=190; letterArr[46].g=15; letterArr[46].b=209;
			letterArr[54].r=190; letterArr[54].g=15; letterArr[54].b=209;
			letterArr[55].r=190; letterArr[55].g=15; letterArr[55].b=209;
			break;
		}
		case 'å': {
			letterArr[8].r=190;  letterArr[8].g=15;  letterArr[8].b=209;
			letterArr[9].r=190;  letterArr[9].g=15;  letterArr[9].b=209;
			letterArr[10].r=190; letterArr[10].g=15; letterArr[10].b=209;
			letterArr[11].r=190; letterArr[11].g=15; letterArr[11].b=209;
			letterArr[12].r=190; letterArr[12].g=15; letterArr[12].b=209;
			letterArr[13].r=190; letterArr[13].g=15; letterArr[13].b=209;
			letterArr[14].r=190; letterArr[14].g=15; letterArr[14].b=209;
			letterArr[15].r=190; letterArr[15].g=15; letterArr[15].b=209;
			letterArr[16].r=190; letterArr[16].g=15; letterArr[16].b=209;
			letterArr[19].r=190; letterArr[19].g=15; letterArr[19].b=209;
			letterArr[23].r=190; letterArr[23].g=15; letterArr[23].b=209;
			letterArr[24].r=190; letterArr[24].g=15; letterArr[24].b=209;
			letterArr[27].r=190; letterArr[27].g=15; letterArr[27].b=209;
			letterArr[31].r=190; letterArr[31].g=15; letterArr[31].b=209;
			letterArr[32].r=190; letterArr[32].g=15; letterArr[32].b=209;
			letterArr[35].r=190; letterArr[35].g=15; letterArr[35].b=209;
			letterArr[39].r=190; letterArr[39].g=15; letterArr[39].b=209;
			letterArr[40].r=190; letterArr[40].g=15; letterArr[40].b=209;
			letterArr[43].r=190; letterArr[43].g=15; letterArr[43].b=209;
			letterArr[47].r=190; letterArr[47].g=15; letterArr[47].b=209;
			letterArr[48].r=190; letterArr[48].g=15; letterArr[48].b=209;
			letterArr[55].r=190; letterArr[55].g=15; letterArr[55].b=209;
			break;
		}
		case 'æ': {
			letterArr[0].r=190; letterArr[0].g=15; letterArr[0].b=209;
			letterArr[1].r=190; letterArr[1].g=15; letterArr[1].b=209;
			letterArr[5].r=190; letterArr[5].g=15; letterArr[5].b=209;
			letterArr[6].r=190; letterArr[6].g=15; letterArr[6].b=209;
			letterArr[7].r=190; letterArr[7].g=15; letterArr[7].b=209;
			letterArr[10].r=190; letterArr[10].g=15; letterArr[10].b=209;
			letterArr[12].r=190; letterArr[12].g=15; letterArr[12].b=209;
			letterArr[19].r=190; letterArr[19].g=15; letterArr[19].b=209;
			letterArr[24].r=190; letterArr[24].g=15; letterArr[24].b=209;
			letterArr[27].r=190; letterArr[27].g=15; letterArr[27].b=209;
			letterArr[31].r=190; letterArr[31].g=15; letterArr[31].b=209;
			letterArr[32].r=190; letterArr[32].g=15; letterArr[32].b=209;
			letterArr[35].r=190; letterArr[35].g=15; letterArr[35].b=209;
			letterArr[39].r=190; letterArr[39].g=15; letterArr[39].b=209;
			letterArr[40].r=190; letterArr[40].g=15; letterArr[40].b=209;
			letterArr[43].r=190; letterArr[43].g=15; letterArr[43].b=209;
			letterArr[47].r=190; letterArr[47].g=15; letterArr[47].b=209;
			letterArr[48].r=190; letterArr[48].g=15; letterArr[48].b=209;
			letterArr[55].r=190; letterArr[55].g=15; letterArr[55].b=209;
			break;
		}
		case 'è': {
			letterArr[8].r=190;  letterArr[8].g=15;  letterArr[8].b=209;
			letterArr[9].r=190;  letterArr[9].g=15;  letterArr[9].b=209;
			letterArr[10].r=190; letterArr[10].g=15; letterArr[10].b=209;
			letterArr[11].r=190; letterArr[11].g=15; letterArr[11].b=209;
			letterArr[12].r=190; letterArr[12].g=15; letterArr[12].b=209;
			letterArr[13].r=190; letterArr[13].g=15; letterArr[13].b=209;
			letterArr[14].r=190; letterArr[14].g=15; letterArr[14].b=209;
			letterArr[15].r=190; letterArr[15].g=15; letterArr[15].b=209;
			letterArr[21].r=190; letterArr[21].g=15; letterArr[21].b=209;
			letterArr[28].r=190; letterArr[28].g=15; letterArr[28].b=209;
			letterArr[35].r=190; letterArr[35].g=15; letterArr[35].b=209;
			letterArr[42].r=190; letterArr[42].g=15; letterArr[42].b=209;
			letterArr[48].r=190; letterArr[48].g=15; letterArr[48].b=209;
			letterArr[49].r=190; letterArr[49].g=15; letterArr[49].b=209;
			letterArr[50].r=190; letterArr[50].g=15; letterArr[50].b=209;
			letterArr[51].r=190; letterArr[51].g=15; letterArr[51].b=209;
			letterArr[52].r=190; letterArr[52].g=15; letterArr[52].b=209;
			letterArr[53].r=190; letterArr[53].g=15; letterArr[53].b=209;
			letterArr[54].r=190; letterArr[54].g=15; letterArr[54].b=209;
			letterArr[55].r=190; letterArr[55].g=15; letterArr[55].b=209;
			break;
		}
		case 'é': {
			letterArr[9].r=190;  letterArr[9].g=15;  letterArr[9].b=209;
			letterArr[10].r=190; letterArr[10].g=15; letterArr[10].b=209;
			letterArr[11].r=190; letterArr[11].g=15; letterArr[11].b=209;
			letterArr[12].r=190; letterArr[12].g=15; letterArr[12].b=209;
			letterArr[13].r=190; letterArr[13].g=15; letterArr[13].b=209;
			letterArr[14].r=190; letterArr[14].g=15; letterArr[14].b=209;
			letterArr[15].r=190; letterArr[15].g=15; letterArr[15].b=209;
			letterArr[21].r=190; letterArr[21].g=15; letterArr[21].b=209;
			letterArr[24].r=190; letterArr[24].g=15; letterArr[24].b=209;
			letterArr[28].r=190; letterArr[28].g=15; letterArr[28].b=209;
			letterArr[32].r=190; letterArr[32].g=15; letterArr[32].b=209;
			letterArr[35].r=190; letterArr[35].g=15; letterArr[35].b=209;
			letterArr[42].r=190; letterArr[42].g=15; letterArr[42].b=209;
			letterArr[49].r=190; letterArr[49].g=15; letterArr[49].b=209;
			letterArr[50].r=190; letterArr[50].g=15; letterArr[50].b=209;
			letterArr[51].r=190; letterArr[51].g=15; letterArr[51].b=209;
			letterArr[52].r=190; letterArr[52].g=15; letterArr[52].b=209;
			letterArr[53].r=190; letterArr[53].g=15; letterArr[53].b=209;
			letterArr[54].r=190; letterArr[54].g=15; letterArr[54].b=209;
			letterArr[55].r=190; letterArr[55].g=15; letterArr[55].b=209;
			break;
		}
		case 'ê': {
			letterArr[8].r=190;  letterArr[8].g=15;  letterArr[8].b=209;
			letterArr[9].r=190;  letterArr[9].g=15;  letterArr[9].b=209;
			letterArr[10].r=190; letterArr[10].g=15; letterArr[10].b=209;
			letterArr[11].r=190; letterArr[11].g=15; letterArr[11].b=209;
			letterArr[12].r=190; letterArr[12].g=15; letterArr[12].b=209;
			letterArr[13].r=190; letterArr[13].g=15; letterArr[13].b=209;
			letterArr[14].r=190; letterArr[14].g=15; letterArr[14].b=209;
			letterArr[15].r=190; letterArr[15].g=15; letterArr[15].b=209;
			letterArr[19].r=190; letterArr[19].g=15; letterArr[19].b=209;
			letterArr[27].r=190; letterArr[27].g=15; letterArr[27].b=209;
			letterArr[28].r=190; letterArr[28].g=15; letterArr[28].b=209;
			letterArr[34].r=190; letterArr[34].g=15; letterArr[34].b=209;
			letterArr[37].r=190; letterArr[37].g=15; letterArr[37].b=209;
			letterArr[41].r=190; letterArr[41].g=15; letterArr[41].b=209;
			letterArr[46].r=190; letterArr[46].g=15; letterArr[46].b=209;
			letterArr[48].r=190; letterArr[48].g=15; letterArr[48].b=209;
			letterArr[55].r=190; letterArr[55].g=15; letterArr[55].b=209;
			break;
		}
		case 'ì': {
			letterArr[8].r=190;  letterArr[8].g=15;  letterArr[8].b=209;
			letterArr[9].r=190;  letterArr[9].g=15;  letterArr[9].b=209;
			letterArr[10].r=190; letterArr[10].g=15; letterArr[10].b=209;
			letterArr[11].r=190; letterArr[11].g=15; letterArr[11].b=209;
			letterArr[12].r=190; letterArr[12].g=15; letterArr[12].b=209;
			letterArr[13].r=190; letterArr[13].g=15; letterArr[13].b=209;
			letterArr[14].r=190; letterArr[14].g=15; letterArr[14].b=209;
			letterArr[15].r=190; letterArr[15].g=15; letterArr[15].b=209;
			letterArr[18].r=190; letterArr[18].g=15; letterArr[18].b=209;
			letterArr[27].r=190; letterArr[27].g=15; letterArr[27].b=209;
			letterArr[35].r=190; letterArr[35].g=15; letterArr[35].b=209;
			letterArr[42].r=190; letterArr[42].g=15; letterArr[42].b=209;
			letterArr[48].r=190; letterArr[48].g=15; letterArr[48].b=209;
			letterArr[49].r=190; letterArr[49].g=15; letterArr[49].b=209;
			letterArr[50].r=190; letterArr[50].g=15; letterArr[50].b=209;
			letterArr[51].r=190; letterArr[51].g=15; letterArr[51].b=209;
			letterArr[52].r=190; letterArr[52].g=15; letterArr[52].b=209;
			letterArr[53].r=190; letterArr[53].g=15; letterArr[53].b=209;
			letterArr[54].r=190; letterArr[54].g=15; letterArr[54].b=209;
			letterArr[55].r=190; letterArr[55].g=15; letterArr[55].b=209;
			break;
		}
		case 'î': {
			letterArr[9].r=190;  letterArr[9].g=15;  letterArr[9].b=209;
			letterArr[10].r=190; letterArr[10].g=15; letterArr[10].b=209;
			letterArr[11].r=190; letterArr[11].g=15; letterArr[11].b=209;
			letterArr[12].r=190; letterArr[12].g=15; letterArr[12].b=209;
			letterArr[13].r=190; letterArr[13].g=15; letterArr[13].b=209;
			letterArr[14].r=190; letterArr[14].g=15; letterArr[14].b=209;
			letterArr[16].r=190; letterArr[16].g=15; letterArr[16].b=209;
			letterArr[23].r=190; letterArr[23].g=15; letterArr[23].b=209;
			letterArr[24].r=190; letterArr[24].g=15; letterArr[24].b=209;
			letterArr[31].r=190; letterArr[31].g=15; letterArr[31].b=209;
			letterArr[32].r=190; letterArr[32].g=15; letterArr[32].b=209;
			letterArr[39].r=190; letterArr[39].g=15; letterArr[39].b=209;
			letterArr[40].r=190; letterArr[40].g=15; letterArr[40].b=209;
			letterArr[47].r=190; letterArr[47].g=15; letterArr[47].b=209;
			letterArr[49].r=190; letterArr[49].g=15; letterArr[49].b=209;
			letterArr[50].r=190; letterArr[50].g=15; letterArr[50].b=209;
			letterArr[51].r=190; letterArr[51].g=15; letterArr[51].b=209;
			letterArr[52].r=190; letterArr[52].g=15; letterArr[52].b=209;
			letterArr[53].r=190; letterArr[53].g=15; letterArr[53].b=209;
			letterArr[54].r=190; letterArr[54].g=15; letterArr[54].b=209;
			break;

		}
		case 'ð': {
			letterArr[8].r=190;  letterArr[8].g=15;  letterArr[8].b=209;
			letterArr[9].r=190;  letterArr[9].g=15;  letterArr[9].b=209;
			letterArr[10].r=190; letterArr[10].g=15; letterArr[10].b=209;
			letterArr[11].r=190; letterArr[11].g=15; letterArr[11].b=209;
			letterArr[12].r=190; letterArr[12].g=15; letterArr[12].b=209;
			letterArr[13].r=190; letterArr[13].g=15; letterArr[13].b=209;
			letterArr[14].r=190; letterArr[14].g=15; letterArr[14].b=209;
			letterArr[15].r=190; letterArr[15].g=15; letterArr[15].b=209;
			letterArr[16].r=190; letterArr[16].g=15; letterArr[16].b=209;
			letterArr[20].r=190; letterArr[20].g=15; letterArr[20].b=209;
			letterArr[24].r=190; letterArr[24].g=15; letterArr[24].b=209;
			letterArr[28].r=190; letterArr[28].g=15; letterArr[28].b=209;
			letterArr[32].r=190; letterArr[32].g=15; letterArr[32].b=209;
			letterArr[36].r=190; letterArr[36].g=15; letterArr[36].b=209;
			letterArr[40].r=190; letterArr[40].g=15; letterArr[40].b=209;
			letterArr[44].r=190; letterArr[44].g=15; letterArr[44].b=209;
			letterArr[49].r=190; letterArr[49].g=15; letterArr[49].b=209;
			letterArr[50].r=190; letterArr[50].g=15; letterArr[50].b=209;
			letterArr[51].r=190; letterArr[51].g=15; letterArr[51].b=209;
			break;
		}
		case 'ñ': {
			letterArr[9].r=190;  letterArr[9].g=15;  letterArr[9].b=209;
			letterArr[10].r=190; letterArr[10].g=15; letterArr[10].b=209;
			letterArr[11].r=190; letterArr[11].g=15; letterArr[11].b=209;
			letterArr[12].r=190; letterArr[12].g=15; letterArr[12].b=209;
			letterArr[13].r=190; letterArr[13].g=15; letterArr[13].b=209;
			letterArr[14].r=190; letterArr[14].g=15; letterArr[14].b=209;
			letterArr[16].r=190; letterArr[16].g=15; letterArr[16].b=209;
			letterArr[23].r=190; letterArr[23].g=15; letterArr[23].b=209;
			letterArr[24].r=190; letterArr[24].g=15; letterArr[24].b=209;
			letterArr[31].r=190; letterArr[31].g=15; letterArr[31].b=209;
			letterArr[32].r=190; letterArr[32].g=15; letterArr[32].b=209;
			letterArr[39].r=190; letterArr[39].g=15; letterArr[39].b=209;
			letterArr[40].r=190; letterArr[40].g=15; letterArr[40].b=209;
			letterArr[47].r=190; letterArr[47].g=15; letterArr[47].b=209;
			letterArr[48].r=190; letterArr[48].g=15; letterArr[48].b=209;
			letterArr[55].r=190; letterArr[55].g=15; letterArr[55].b=209;
			break;
		}
		case 'ó': {
			letterArr[8].r=190;  letterArr[8].g=15;  letterArr[8].b=209;
			letterArr[9].r=190;  letterArr[9].g=15;  letterArr[9].b=209;
			letterArr[10].r=190; letterArr[10].g=15; letterArr[10].b=209;
			letterArr[15].r=190; letterArr[15].g=15; letterArr[15].b=209;
			letterArr[19].r=190; letterArr[19].g=15; letterArr[19].b=209;
			letterArr[23].r=190; letterArr[23].g=15; letterArr[23].b=209;
			letterArr[27].r=190; letterArr[27].g=15; letterArr[27].b=209;
			letterArr[31].r=190; letterArr[31].g=15; letterArr[31].b=209;
			letterArr[35].r=190; letterArr[35].g=15; letterArr[35].b=209;
			letterArr[39].r=190; letterArr[39].g=15; letterArr[39].b=209;
			letterArr[43].r=190; letterArr[43].g=15; letterArr[43].b=209;
			letterArr[47].r=190; letterArr[47].g=15; letterArr[47].b=209;
			letterArr[48].r=190; letterArr[48].g=15; letterArr[48].b=209;
			letterArr[49].r=190; letterArr[49].g=15; letterArr[49].b=209;
			letterArr[50].r=190; letterArr[50].g=15; letterArr[50].b=209;
			letterArr[51].r=190; letterArr[51].g=15; letterArr[51].b=209;
			letterArr[52].r=190; letterArr[52].g=15; letterArr[52].b=209;
			letterArr[53].r=190; letterArr[53].g=15; letterArr[53].b=209;
			letterArr[54].r=190; letterArr[54].g=15; letterArr[54].b=209;
			break;
		}
		case 'õ': {
			letterArr[8].r=190;	 letterArr[8].g=15;  letterArr[8].b=209;
			letterArr[9].r=190;  letterArr[9].g=15;  letterArr[9].b=209;
			letterArr[13].r=190; letterArr[13].g=15; letterArr[13].b=209;
			letterArr[14].r=190; letterArr[14].g=15; letterArr[14].b=209;
			letterArr[15].r=190; letterArr[15].g=15; letterArr[15].b=209;
			letterArr[18].r=190; letterArr[18].g=15; letterArr[18].b=209;
			letterArr[20].r=190; letterArr[20].g=15; letterArr[20].b=209;
			letterArr[27].r=190; letterArr[27].g=15; letterArr[27].b=209;
			letterArr[35].r=190; letterArr[35].g=15; letterArr[35].b=209;
			letterArr[42].r=190; letterArr[42].g=15; letterArr[42].b=209;
			letterArr[44].r=190; letterArr[44].g=15; letterArr[44].b=209;
			letterArr[48].r=190; letterArr[48].g=15; letterArr[48].b=209;
			letterArr[49].r=190; letterArr[49].g=15; letterArr[49].b=209;
			letterArr[53].r=190; letterArr[53].g=15; letterArr[53].b=209;
			letterArr[54].r=190; letterArr[54].g=15; letterArr[54].b=209;
			letterArr[55].r=190; letterArr[55].g=15; letterArr[55].b=209;
			break;
		}
		default: {
			/*letterArr[8].r=190;  letterArr[8].g=15;  letterArr[8].b=209;
			letterArr[55].r=190;  letterArr[55].g=15;  letterArr[55].b=209;*/
			letterArr[0].r=202; letterArr[0].g=22; letterArr[0].b=22;
			letterArr[1].r=135; letterArr[1].g=89; letterArr[1].b=19;//red
			letterArr[2].r=232; letterArr[2].g=169; letterArr[2].b=44;//orange
			letterArr[3].r=225; letterArr[3].g=255; letterArr[3].b=000;//yellow
			letterArr[4].r=44; letterArr[4].g=232; letterArr[4].b=50;//green
			letterArr[5].r=44; letterArr[5].g=232; letterArr[5].b=132;//light blue
			letterArr[6].r=33; letterArr[6].g=110; letterArr[6].b=178;//blue
			letterArr[7].r=33; letterArr[7].g=47; letterArr[7].b=178;//violet
			letterArr[8].r=134; letterArr[8].g=33; letterArr[8].b=178;//blue
			letterArr[9].r=190; letterArr[9].g=15; letterArr[9].b=209;//violet

			letterArr[10].r=202; letterArr[10].g=22; letterArr[10].b=22;
			letterArr[11].r=135; letterArr[11].g=89; letterArr[11].b=19;//red
			letterArr[12].r=232; letterArr[12].g=169; letterArr[12].b=44;//orange
			letterArr[13].r=225; letterArr[13].g=255; letterArr[13].b=000;//yellow
			letterArr[14].r=44; letterArr[14].g=232; letterArr[14].b=50;//green
			letterArr[15].r=44; letterArr[15].g=232; letterArr[15].b=132;//light blue
			letterArr[16].r=33; letterArr[16].g=110; letterArr[16].b=178;//blue
			letterArr[17].r=33; letterArr[17].g=47; letterArr[17].b=178;//violet
			letterArr[18].r=134; letterArr[18].g=33; letterArr[18].b=178;//blue
			letterArr[19].r=190; letterArr[19].g=15; letterArr[19].b=209;//violet

			letterArr[20].r=202; letterArr[20].g=22; letterArr[20].b=22;
			letterArr[21].r=135; letterArr[21].g=89; letterArr[21].b=19;//red
			letterArr[22].r=232; letterArr[22].g=169; letterArr[22].b=44;//orange
			letterArr[23].r=225; letterArr[23].g=255; letterArr[23].b=000;//yellow
			letterArr[24].r=44; letterArr[24].g=232; letterArr[24].b=50;//green
			letterArr[25].r=44; letterArr[25].g=232; letterArr[25].b=132;//light blue
			letterArr[26].r=33; letterArr[26].g=110; letterArr[26].b=178;//blue
			letterArr[27].r=33; letterArr[27].g=47; letterArr[27].b=178;//violet
			letterArr[28].r=134; letterArr[28].g=33; letterArr[28].b=178;//blue
			letterArr[29].r=190; letterArr[29].g=15; letterArr[29].b=209;//violet

			letterArr[30].r=202; letterArr[30].g=22; letterArr[30].b=22;
			letterArr[31].r=135; letterArr[31].g=89; letterArr[31].b=19;//red
			letterArr[32].r=232; letterArr[32].g=169; letterArr[32].b=44;//orange
			letterArr[33].r=225; letterArr[33].g=255; letterArr[33].b=000;//yellow
			letterArr[34].r=44; letterArr[34].g=232; letterArr[34].b=50;//green
			letterArr[35].r=44; letterArr[35].g=232; letterArr[35].b=132;//light blue
			letterArr[36].r=33; letterArr[36].g=110; letterArr[36].b=178;//blue
			letterArr[37].r=33; letterArr[37].g=47; letterArr[37].b=178;//violet
			letterArr[38].r=134; letterArr[38].g=33; letterArr[38].b=178;//blue
			letterArr[39].r=190; letterArr[39].g=15; letterArr[39].b=209;//violet

			letterArr[40].r=202; letterArr[40].g=22; letterArr[40].b=22;
			letterArr[41].r=135; letterArr[41].g=89; letterArr[41].b=19;//red
			letterArr[42].r=232; letterArr[42].g=169; letterArr[42].b=44;//orange
			letterArr[43].r=225; letterArr[43].g=255; letterArr[43].b=000;//yellow
			letterArr[44].r=44; letterArr[44].g=232; letterArr[44].b=50;//green
			letterArr[45].r=44; letterArr[45].g=232; letterArr[45].b=132;//light blue
			letterArr[46].r=33; letterArr[46].g=110; letterArr[46].b=178;//blue
			letterArr[47].r=33; letterArr[47].g=47; letterArr[47].b=178;//violet
			letterArr[48].r=134; letterArr[48].g=33; letterArr[48].b=178;//blue
			letterArr[49].r=190; letterArr[49].g=15; letterArr[49].b=209;//violet

			letterArr[50].r=202; letterArr[50].g=22; letterArr[50].b=22;
			letterArr[51].r=135; letterArr[51].g=89; letterArr[51].b=19;//red
			letterArr[52].r=232; letterArr[52].g=169; letterArr[52].b=44;//orange
			letterArr[53].r=225; letterArr[53].g=255; letterArr[53].b=000;//yellow
			letterArr[54].r=44; letterArr[54].g=232; letterArr[54].b=50;//green
			letterArr[55].r=44; letterArr[55].g=232; letterArr[55].b=132;//light blue
			letterArr[56].r=33; letterArr[56].g=110; letterArr[56].b=178;//blue
			letterArr[57].r=33; letterArr[57].g=47; letterArr[57].b=178;//violet
			letterArr[58].r=134; letterArr[58].g=33; letterArr[58].b=178;//blue
			letterArr[59].r=190; letterArr[59].g=15; letterArr[59].b=209;//violet

			letterArr[60].r=202; letterArr[60].g=22; letterArr[60].b=22;
			letterArr[61].r=135; letterArr[61].g=89; letterArr[61].b=19;//red
			letterArr[62].r=232; letterArr[62].g=169; letterArr[62].b=44;//orange
			letterArr[63].r=225; letterArr[63].g=255; letterArr[63].b=000;//yellow
			break;
		}
	}
	return;
}

void clearArray(struct cRGB* letterArr) {
	int i;
	for(i = 0; i < 64; i++) {
		letterArr[i].r=0;	 letterArr[i].g=0;  letterArr[i].b=0;
	}
	return;
}

void fillColumn(struct cRGB* colors, struct cRGB* letterArr, int colorsCol, int letterCol) {
	colorsCol = 8 * colorsCol;
	letterCol = 8 * letterCol;
	colors[colorsCol].r=letterArr[letterCol].r; colors[colorsCol].g=letterArr[letterCol].g; colors[colorsCol].b=letterArr[letterCol].b;
	colors[colorsCol+1].r=letterArr[letterCol+1].r; colors[colorsCol+1].g=letterArr[letterCol+1].g; colors[colorsCol+1].b=letterArr[letterCol+1].b;
	colors[colorsCol+2].r=letterArr[letterCol+2].r; colors[colorsCol+2].g=letterArr[letterCol+2].g; colors[colorsCol+2].b=letterArr[letterCol+2].b;
	colors[colorsCol+3].r=letterArr[letterCol+3].r; colors[colorsCol+3].g=letterArr[letterCol+3].g; colors[colorsCol+3].b=letterArr[letterCol+3].b;
	colors[colorsCol+4].r=letterArr[letterCol+4].r; colors[colorsCol+4].g=letterArr[letterCol+4].g; colors[colorsCol+4].b=letterArr[letterCol+4].b;
	colors[colorsCol+5].r=letterArr[letterCol+5].r; colors[colorsCol+5].g=letterArr[letterCol+5].g; colors[colorsCol+5].b=letterArr[letterCol+5].b;
	colors[colorsCol+6].r=letterArr[letterCol+6].r; colors[colorsCol+6].g=letterArr[letterCol+6].g; colors[colorsCol+6].b=letterArr[letterCol+6].b;
	colors[colorsCol+7].r=letterArr[letterCol+7].r; colors[colorsCol+7].g=letterArr[letterCol+7].g; colors[colorsCol+7].b=letterArr[letterCol+7].b;
	return;
}