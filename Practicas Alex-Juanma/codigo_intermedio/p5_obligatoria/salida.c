/*#include "dec_fun"
#include "dec_dat"*/
#include <stdio.h>

int main(){
int curr;
int n;

float prueba;

float temp0;
temp0 = 3.4 * 2.0;
float temp1;
temp1 = temp0 / 5.0;
float temp2;
temp2 = 1.0 - temp1;
prueba = temp2;

printf("%s","Prueba es ");
printf("%f",prueba);
printf("%s","Introduzca un numero: \n");
scanf("%i",&n);
curr = 2;

printf("%s","Sus factores primos son: \n");
etiqueta0:;int temp3;
temp3 = curr <= n;

if(!temp3)goto etiqueta1;

{
int d;

int temp4;
temp4 = n / curr;
d = temp4;

int temp5;
temp5 = d * curr;
int temp6;
temp6 = temp5 == n;
if(!temp6)goto etiqueta3;

{
printf("%d",curr);
printf("%s"," ");
int temp7;
temp7 = n / curr;
n = temp7;

}
goto etiqueta2;

etiqueta3:

{
int temp8;
temp8 = curr + 1;
curr = temp8;

}
etiqueta2:
;}
goto etiqueta0;
etiqueta1:

printf("%s","1\n");
return 0;
}
