#include "dec_fun"/*
#include "dec_dat"*/
#include <stdio.h>

int main(){
int curr;
int n;


fa();
printf("%s","Introduzca un numero: \n");
scanf("%i",&n);
curr = 2;

printf("%s","Sus factores primos son: \n");
etiqueta2:;int temp4;
temp4 = curr <= n;

if(!temp4)goto etiqueta3;

{
int d;

int temp5;
temp5 = n / curr;
d = temp5;

int temp6;
temp6 = d * curr;
int temp7;
temp7 = temp6 == n;
if(!temp7)goto etiqueta5;

{
printf("%d",curr);
printf("%s"," ");
int temp8;
temp8 = n / curr;
n = temp8;

}
goto etiqueta4;

etiqueta5:

{
int temp9;
temp9 = curr + 1;
int temp10;
temp10 = temp9 - 1;
int temp11;
temp11 = temp10 + 1;
curr = temp11;

}
etiqueta4:
;}
goto etiqueta2;
etiqueta3:

printf("%s","1\n");
return 0;
}
