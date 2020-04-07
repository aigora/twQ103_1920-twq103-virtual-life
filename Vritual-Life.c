#include<stdio.h>
#include<string.h>//Funciones de las cadenas
#define MAX_USUARIOS 100

struct usuario{

	char nombreUsuario[100];
	char contrasena[200];
	char genero[1];
};

int main(){
	char info;
	int i,igual=0;
	int nusuario=0;
	char opcion;
	char usuarioInicio[100];
	char contrasenaInicio[200];
	char generoInicio[1];
	FILE * vpfichero;
	struct usuario datos[MAX_USUARIOS];

	do{
	
	//system("cls");//Borrar pantalla	
	printf("VIRTUAL-LIFE\n Bienvenido al menu opciones:\n ");
	printf("Introduce la opcion:\n");
	printf("-----------------------\n");
	printf("a-Iniciar sesion para jugar\n");
	printf("b-Registrarse\n");
	printf("c-Intrucciones\n");
	printf("d-Salir\n");
	printf("-----------------------\n");
	fflush(stdin);
	scanf("%c",&opcion);
		
		switch(opcion)
		{
			case 'a': printf("INICIAR SESION\n");
					
					//Primero abrir el fichero
					vpfichero= fopen("usuarios.txt","r");//Modo lectura
					
					//Comprueba si encuentra el fichero si no lo siguiente no va
					if(vpfichero==NULL){
					printf("No se ha podido encontrar el fichero\n");
					return 0;
					}
					
					//Miremos cuantos usuarios ya hay en ese fichero
					i=0;
					while(fscanf(vpfichero,"%s %s %s",&datos[i].nombreUsuario ,&datos[i].contrasena ,&datos[i].genero )!=EOF){
						nusuario++;
						i++;
					}
					printf("Hay %d usuarios dados de alta\n",nusuario);
				
					//Pedir los datos de iniciar sesion al usuario
				do{
					
					printf("Introduzca  nombre de usuario:\n");
					fflush(stdin);
					scanf("%s",usuarioInicio);
					printf("Introduzca contrasena:\n");
					fflush(stdin);
					scanf("%s",contrasenaInicio);
					
					//Tenemos que ver que efectivamente existe ese usuario y contraseña.
					for(i=0;i<nusuario;i++){
							if(strcmp(usuarioInicio,datos[i].nombreUsuario)==0 && strcmp(contrasenaInicio,datos[i].contrasena)==0){
								igual=1;
								break;
							}else{
								igual=0;
							}
						}
						
						if(igual==0){
							printf("Usuario o contrasena son incorrectos.\n");
						}else{
							printf("Usuario valido\n");
						}
					}while(igual==0);//Eso es que serían diferentes y no vuelve a preguntar.
					
					
					//Tercer paso es siempre cerrar el fichero al final
					fclose(vpfichero);
					
					//COMENZAMOS CON EL JUEGO
					
					
					break;
			
			case 'b': printf("CREA UN USUARIO\nSigue las instrucciones\n");
					vpfichero=fopen("usuarios.txt","a");
					//Esto es para crear el fichero la primera vez que entras al juego.
					
					fclose(vpfichero);
				
					//Primero abrir el fichero
					vpfichero= fopen("usuarios.txt","r");//Modo lectura para ver usuarios
					 
					
					//Comprobación por si acaso de que existe una vez creado
					if(vpfichero==NULL){
					printf("No se ha podido encontrar el fichero\n");
					return 0;
					}
					
					//Miremos cuantos usuarios ya hay en ese fichero
					i=0;
					while(fscanf(vpfichero,"%s %s %s",&datos[i].nombreUsuario ,&datos[i].contrasena ,&datos[i].genero )!=EOF){
						nusuario++;
						i++;
					}
					printf("Hay %d usuarios dados de alta\n",nusuario);
					
					//Tercer paso cerrar el fichero
					fclose(vpfichero);
					
					//Primero abrir el fichero
					vpfichero= fopen("usuarios.txt","a");//Si no existe se crea
					
					//Pedir los datos al usuario
		
					//Ahora tenemos que comprobar si el usuario es correcto y no se parece a otro.
					do{
						printf("Introduzca  nombre de usuario:\n");
						fflush(stdin);
						scanf("%s",usuarioInicio);
						for(i=0;i<nusuario;i++){
							if(strcmp(usuarioInicio,datos[i].nombreUsuario)==0){
								igual=1;
								break;
							}else{
								igual=0;
							}
						}
						if(igual==1){
							printf("Ya existe ese usuario.Prueba de nuevo\n");
						}
					}while(igual==1);
					
					printf("Introduzca contrasena:\n");
					fflush(stdin);
					scanf("%s",contrasenaInicio);
					printf("Introduce genero(H-Hombre o M-Mujer):\n");
					fflush(stdin);
					scanf("%s",generoInicio);
					
				
					//Ahora lo imprimo al fichero añado estos datos.
				
					fprintf(vpfichero,"%s\n%s\n%s\n",usuarioInicio,contrasenaInicio,generoInicio);
				
					
					//Tercer paso cerrar el fichero
					fclose(vpfichero);

					break;
		
			case 'c':printf("INSTRUCCIONES:\n");
			
					printf("En este juego recorreras las distintas etapas de tu vida virtual. Comenzaras siendo un\n bebe y mediante la toma de decisiones iras creciendo a lo largo del tiempo. Hay\n distintos tipos de decisiones, unos te haran ganar puntos de vida que te serviran\n para poder seguir adelante cuando tengas que tomar una decision importante.\nTambien estan los puntos de muerte que te seran utiles a la hora del juicio final para\n determinar donde ira tu alma.\n");
					
				do{
					
					printf("Para mas informacion pulse:\n");
					printf("-----------------------\n");
					printf("a-Tipos de decisiones\n");
					printf("b-Tipos de puntos\n");
					printf("c-Salir de este menu\n");
					printf("-----------------------\n");
					fflush(stdin);
					scanf("%c",&info);
					
						if(info=='a'){
							printf("TIPOS DE DECISIONES\n");
							printf("Decisiones simples: segun las respondas te sumaran puntos a puntos de vida y puntos de muerte\n");
							printf("Decisiones importantes: saltara un aviso cuando aparezcan en el juego\ny necesitaras un minimo de puntos de vida para superarlas.\n");
							printf("Ejemplo: sale una decision importante con dos opciones a o b.\nCada una requiere un minimo de puntos de vida para avanzar, solo que el usuario no lo sabe.\nEntonces si no tienes los puntos necesarios mueres.Es cuestion de SUERTE\n");
						}else if(info=='b'){
							printf("TIPOS DE PUNTOS\n");
							printf("Puntos de vida: puntos obtenidos por tus decisiones realizadas.\nTambien seran necesarios para superar las decisiones importantes\n");
							printf("Puntos de muerte: puntos que se iran acumulando segun tus decisiones y en el caso de morir deciden tu destino final\n");
						}else if(info=='c'){
							break; 
						}else{
							printf("Opción no disponible\n");
						}
				}while(info!='c');
			
					break;
					
			case 'd':printf("Adios");
					break;
		
			default: 
					printf("Opcion incorrecta\n");
					break;
		}
	}while(opcion!='d');
}

