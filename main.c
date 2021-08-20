#include<18f4550.h>
#fuses hs,nowdt
#use delay(clock=4000000)
#include<lcd.c>
#include<kbd1.c>

int X=0;
int Y=0;
float A=0;
float B=0;
float C=0;

void main()
{
   char K;
   int T;
   lcd_init();
   kbd_init();
   port_b_pullups(true);
   
   do
   {
      K=kbd_getc();
      T=k-48;
      if((K!=0)&&(K!='D')&&(k!='*')&&(k!='A')&&(k!='B')&&(k!='C')&&(k!='#'))
      {
         A=(A*10)+T;
         X++;
         lcd_gotoxy(X,1);
         printf(lcd_putc,"%d",T);
         delay_ms(5);
      }
      
      if(K=='*')
      {
         X=0;
         A=0;
         B=0;
         C=0;
         printf(lcd_putc,"\f");
      }
      
      
      
      //suma//
      
      if(K=='D')
      {
         X++;
         Y=1;
         printf(lcd_putc,"+");
         
         do
         {
            K=kbd_getc();
            T=K-48;
            if((K!=0)&&(K!='D')&&(k!='*')&&(k!='A')&&(k!='B')&&(k!='C')&&(k!='#'))
            {
               B=(B*10)+T;
               X++;
               lcd_gotoxy(X,1);
               printf(lcd_putc,"%d",T);
               delay_ms(5);
            }
            
            if(K=='#')
            {
               C=A+B;
               lcd_gotoxy(1,2);
               printf(lcd_putc,"%f",C);
               delay_ms(5);
            }
            
            
            if(K=='*')
            {
               Y=0;
               X=0;
               A=0;
               B=0;
               C=0;
               printf(lcd_putc,"\f");
      }
            
         }while(Y==1);
      }
      
      
      
      //resta //
      
      if(K=='C')
      {
         X++;
         Y=1;
         printf(lcd_putc,"-");
         
         do
         {
            K=kbd_getc();
            T=K-48;
            if((K!=0)&&(K!='D')&&(k!='*')&&(k!='A')&&(k!='B')&&(k!='C')&&(k!='#'))
            {
               B=(B*10)+T;
               X++;
               lcd_gotoxy(X,1);
               printf(lcd_putc,"%d",T);
               delay_ms(5);
            }
            
            if(K=='#')
            {
               C=A-B;
               lcd_gotoxy(1,2);
               printf(lcd_putc,"%f",C);
               delay_ms(5);
            }
            
            
            if(K=='*')
            {
               Y=0;
               X=0;
               A=0;
               B=0;
               C=0;
               printf(lcd_putc,"\f");
      }
            
         }while(Y==1);
      }
      
      //multiplicacion//
      
      
      
      
      if(K=='B')
      {
         X++;
         Y=1;
         printf(lcd_putc,"x");
         
         do
         {
            K=kbd_getc();
            T=K-48;
            if((K!=0)&&(K!='D')&&(k!='*')&&(k!='A')&&(k!='B')&&(k!='C')&&(k!='#'))
            {
               B=(B*10)+T;
               X++;
               lcd_gotoxy(X,1);
               printf(lcd_putc,"%d",T);
               delay_ms(5);
            }
            
            if(K=='#')
            {
               C=A*B;
               lcd_gotoxy(1,2);
               printf(lcd_putc,"%f",C);
               delay_ms(5);
            }
            
            
            if(K=='*')
            {
               Y=0;
               X=0;
               A=0;
               B=0;
               C=0;
               printf(lcd_putc,"\f");
      }
            
         }while(Y==1);
      }
      
      
      //divicion//
      
      
      if(K=='A')
      {
         X++;
         Y=1;
         printf(lcd_putc,"/");
         
         do
         {
            K=kbd_getc();
            T=K-48;
            if((K!=0)&&(K!='D')&&(k!='*')&&(k!='A')&&(k!='B')&&(k!='C')&&(k!='#'))
            {
               B=(B*10)+T;
               X++;
               lcd_gotoxy(X,1);
               printf(lcd_putc,"%d",T);
               delay_ms(5);
            }
            
            if(K=='#')
            {
               C=A/B;
               lcd_gotoxy(1,2);
               printf(lcd_putc,"%.2f",C);
               delay_ms(5);
            }
            
            
            if(K=='*')
            {
               Y=0;
               X=0;
               A=0;
               B=0;
               C=0;
               printf(lcd_putc,"\f");
      }
            
         }while(Y==1);
      }
      
      
      
   }while(true);
   
}
