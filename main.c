
#include <pic18f4550.h>
#include "Bits_Configuracion.h"

#define SENSOR_PIR PORTAbits.RA0  /* leemos el sensor Pir (digital)*/
#define PORT_Dir TRISAbits.RA0 


#define LED_movimiento LATD0                      
#define LED_Dir TRISDbits.RD0 

#define buzzer  LATDbits.LATD2
#define buzzer_Dir TRISDbits.RD2

void MSdelay(unsigned int val);

void main(void) 
{
    //SENSOR_PIR = 0;
    ADCON1=0x0F;       
    PORT_Dir = 1;
    buzzer_Dir=0; //configurar como salida
    LED_Dir = 0;       
    LED_movimiento = 0;           
    buzzer=0;
    OSCCON = 0x72;
    while(1)
    {
        //while(SENSOR_PIR)        
          //  LED = 1;   /* LED turn ON if any Human motion is detected */  
        
            //LED = 0;   /* LED turn OFF */    
       if(SENSOR_PIR==0)
       {
           LED_movimiento=1;
           buzzer=1;
       }else
       {
           LED_movimiento=0;
           buzzer=0;
       }    
    }
}
void MSdelay(unsigned int val)
{
     unsigned int i,j;
        for(i=0;i<val;i++)
            for(j=0;j<165;j++);  /*This count Provide delay of 1 ms for 8MHz Frequency */
 }