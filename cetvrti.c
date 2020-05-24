
int main()
{
	usartInit(9600);
  	usartPutString("Unesite string\r\n");
 
    char str[64], s1[64], s2[64], ulaz[64];
  while (1) {
    while (!usartAvailable());
    _delay_ms(500);
    usartGetString(ulaz);
    
    int br = atoi(ulaz);
    sprintf(str, "Broj: %d\r\n", br);
    usartPutString(str);
    
    int i = 0, cifra;
    while (br) {
      cifra = br % 16;
      switch (cifra) {
        case 10: s1[i] = 'A'; break;
        case 11: s1[i] = 'B'; break;
        case 12: s1[i] = 'C'; break;
        case 13: s1[i] = 'D'; break;
        case 14: s1[i] = 'E'; break;
        case 15: s1[i] = 'F'; break;
        default: s1[i] = cifra + '0';
      }
      br = br / 16;
      i++;
    }
    s1[i] = '\0';
    int len = strlen(s1);
    i = 0;
    while ( i < len / 2 ) {
      char tmp = s1[len - 1 - i];
      s1[len - 1 - i] = s1[i];
      s1[i] = tmp;
      i++;
    }
    sprintf(s2, "Heksadecimalni broj: 0x%s\r\n", s1);
    usartPutString(s2);
    
      
  }
	return 0;
}