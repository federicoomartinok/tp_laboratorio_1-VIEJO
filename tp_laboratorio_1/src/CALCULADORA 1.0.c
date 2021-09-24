/*
 ============================================================================
 Name        : TP1.c
 Author      : Federico Martin
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Ansi-style, Calculadora en C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "miBiblioteca.h"

int main(void) {

	setbuf(stdout,NULL);


	int operando1;
	int operando2;


	int salir = 1;


	int flagOperando1 = 0;
	int flagOperando2 = 0;
	int flagOperaciones = 0;

	int respuestaDivision;
	int respuestaFactorialOp1;
	int respuestaFactorialOp2;



	int resultadoSuma;
	int resultadoResta;
	int resultadoMultiplicacion;
	float resultadoDivision;
	long resultadoFactorialOp1;
	long resultadoFactorialOp2;

	do
	{

		switch(menu(operando1,operando2,flagOperando1,flagOperando2))
		{
		case 1:

			if(get_Numero(&operando1,"Ingrese operando A: ","Error, debe ser un numero\n") == 0)
			{
				flagOperando1 = 1;
			}
			else
			{
				flagOperando1 = 0;
			}
			flagOperaciones = 0;

			break;

		case 2:

			if(get_Numero(&operando2,"Ingrese operando B: ","Error, debe ser un numero\n") == 0)
			{
				flagOperando2 = 1;
			}
			else
			{
				flagOperando2 = 0;
			}
			flagOperaciones = 0;

			break;

		case 3:

			if(flagOperando1 && flagOperando2)
			{
				resultadoSuma = sumar(operando1,operando2);
				resultadoResta = restar(operando1,operando2);
				respuestaDivision = dividir(&resultadoDivision, operando1,operando2);
				resultadoMultiplicacion = multiplicar(operando1,operando2);
				respuestaFactorialOp1 = factorial(&resultadoFactorialOp1, operando1);
				respuestaFactorialOp2 = factorial(&resultadoFactorialOp2, operando2);
				flagOperaciones = 1;
				printf("OPERACIONES REALIZADAS CON EXITO!!!\n");
			}
			else
			{
				printf("PRIMERO DEBE INGRESAR AMBOS OPERANDOS!!!\n");
			}

			break;

		case 4:

			if(flagOperaciones)
			{
				printf("El resultado de A+B es: %d\n",resultadoSuma);
				printf("El resultado de A-B es: %d\n",resultadoResta);

				if(respuestaDivision == 0)
				{
					printf("El resultado de A/B es: %.2f\n",resultadoDivision);
				}
				else
				{
					printf("No se puede dividir por 0\n");
				}

				printf("El resultado de A*B es: %d\n",resultadoMultiplicacion);



				if(respuestaFactorialOp1 == 0 && respuestaFactorialOp2 == 0)
				{
					printf("El factorial de A es: %li y El factorial de B es: %li\n",resultadoFactorialOp1,resultadoFactorialOp2);
				}
				else
				{
					if(respuestaFactorialOp1 == -1 && respuestaFactorialOp2 == 0)
					{
						printf("No se puede calcular el factorial del operando A por que el numero ingresado debe ser mayor a 0\n");
						printf("El resultado del factorial del operando B es: %li\n",resultadoFactorialOp2);
					}
					else if(respuestaFactorialOp1 == 0 && respuestaFactorialOp2 == -1)
					{
						printf("El resultado del factorial del operando A es: %li\n",resultadoFactorialOp1);
						printf("No se puede calcular el factorial del operando B por que el numero ingresado debe ser mayor a 0\n");
					}
					else
					{
						printf("No se puede calcular el factorial de A y B por que ambos deben ser mayor a 0\n");
					}
				}

			}
			else
			{
				printf("PRIMERO DEBE CALCULAR LAS OPERACIONES!!!\n");
			}

			break;

		case 5:
			salir = 0;

			break;

		default:
			printf("OPCION INCORRECTA!!!\n");

			break;
		}

	}while(salir);

	return EXIT_SUCCESS;
}
