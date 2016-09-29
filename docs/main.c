#include <16F877A.h>
#fuses HS,NOWDT,PUT,NOPROTECT,NOLVP
#use delay(clock=20000000)

#include<lcd.c>
#include<sht75.c>

void main()
{
 float restemp, truehumid;
 lcd_init();
 sht_init();

 while(1)
 {
  sht_rd (restemp, truehumid);
  lcd_gotoxy(1,1);
  printf(lcd_putc, "Temp : %3.1f %cC   ", restemp, 223);
  printf(lcd_putc, "\nRH   : %3.1f %%   ", truehumid);
  delay_ms(500);        //delay 500 ms between reading to prevent self heating of sensor
 }
}
