
#include <mega32.h>


#include <alcd.h>
#include <delay.h>


void motorleft(){
PORTD.3 = 1;
PORTD.4 = 0;

}
void motorright(){
PORTD.3 = 0;
PORTD.4 = 1;

}
void motoroff(){
PORTD.3 = 0;
PORTD.4 = 0;

}

void text(){
  lcd_gotoxy(0,0);
 lcd_puts("AUTO CLOTHESLINE");   
 lcd_gotoxy(0,1);
 lcd_puts("================");
}

void hujan(){
text();
     lcd_gotoxy(1,2); 
     PORTD.5=1;
     PORTD.6=0;
      lcd_puts("RAIN DETECTED");
      delay_ms(500);
      
      if(PIND.1 == 0){  
      PORTD.7=1; 
      lcd_gotoxy(4,3);
      lcd_puts("MOTOR ON"); 
      motorleft(); 
      }     
      else{
      PORTD.7=0; 
       lcd_gotoxy(4,3);
      lcd_puts("MOTOR OF");
      motoroff();
      }
     
} 
void cerah(){
 lcd_clear();
   text();
   PORTD.5=0;
   PORTD.6=1;
    lcd_gotoxy(5,2);
     lcd_puts("CLEAR :)"); 
     delay_ms(1000);
    if(PIND.1 == 1){
      PORTD.7=1;  
      lcd_gotoxy(4,3);
      lcd_puts("MOTOR ON"); 
      motorright(); 
      }     
      else{  
      PORTD.7=0;  
      lcd_gotoxy(4,3);
      lcd_puts("MOTOR OF");
      delay_ms(2000);
      motoroff();
      }  
       
}

void main(void)
{
 
DDRA=(0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | (0<<DDA3) | (0<<DDA2) | (0<<DDA1) | (0<<DDA0);
PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);

DDRB=(0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | (0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);
PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);
 
DDRC=(0<<DDC7) | (0<<DDC6) | (0<<DDC5) | (0<<DDC4) | (0<<DDC3) | (0<<DDC2) | (0<<DDC1) | (0<<DDC0);
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);

DDRD=(1<<DDD7) | (1<<DDD6) | (1<<DDD5) | (1<<DDD4) | (1<<DDD3) | (0<<DDD2) | (0<<DDD1) | (0<<DDD0);
PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);

lcd_init(16);
 
text();
while (1)
      {
      if(PIND.0 == 1){
     hujan(); 
      }
      else{
      cerah();
      }
      }
}
