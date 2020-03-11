#include<stdio.h>

int main(){
	char opcion;
	
	printf("Virtual-life\t Bienvenido al menu opciones: ");
	printf("Seleccione la opcion:\n a)Iniciar sesion\n b)Registrarse\n c)Introducciones\n d)Salir\n");
	scanf("%c",&opcion);
	
	switch(opcion)
	{
		case 'a': printf("Introduce usuario");
				break;
			
		case 'b':printf("Crea un usuario");
				break;
			
		case 'c':printf("Intrudcciones:");
				break;
			
		case 'd':printf("Adios");
				break;
	}
}
