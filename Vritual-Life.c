#include<stdio.h>
#include<string.h>//Funciones de las cadenas
#define MAX_USUARIOS 100

struct usuario{

	char nombreUsuario[100];
	char contrasena[200];
	char genero;
};

int main(){
	char info;
	int longitudUsuario;
	char decision;
	int i,igual=0;
	int nusuario=0;
	char opcion;
	char usuarioInicio[100];
	char contrasenaInicio[200];
	int puntosVida, puntosMuerte;
	FILE * vpfichero;
	struct usuario datos[MAX_USUARIOS];

	do{
	
	system("cls");//Borrar pantalla	
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
					
					//Miremos cuantos usuarios ya hay en ese fichero y guardas en vector
					i=0;
					while(fscanf(vpfichero,"%s %s %c",&datos[i].nombreUsuario ,&datos[i].contrasena ,&datos[i].genero )!=EOF){
						nusuario++;
						i++;
					}
					printf("Hay %d usuarios dados de alta\n",nusuario);
					
					//Tercer paso es siempre cerrar el fichero al final
					fclose(vpfichero);
				
					//Pedir los datos de iniciar sesion al usuario
				do{
					
					printf("Introduzca  nombre de usuario:\n");
					fflush(stdin);
					scanf("%s",usuarioInicio);
					printf("Introduzca contrasena:(con numeros y letras)\n");
					fflush(stdin);
					scanf("%s",contrasenaInicio);
					
					//Tenemos que ver que efectivamente existe ese usuario y contraseÒa.
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
						system("PAUSE");
					}while(igual==0);//Eso es que serÌan diferentes y no vuelve a preguntar.
				
					
					break;
			
			case 'b': printf("CREA UN USUARIO\nSigue las instrucciones\n");
					
					//Primero abrir el fichero
					vpfichero= fopen("usuarios.txt","r");//Modo lectura para ver usuarios
					
					
					//ComprobaciÛn por si acaso de que existe una vez creado
					if(vpfichero==NULL){
					printf("No se ha podido encontrar el fichero\n");
					return 0;
					}
					
					//Miremos cuantos usuarios ya hay en ese fichero y introduce a un vector
					i=0;
					while(fscanf(vpfichero,"%s %s %c",datos[i].nombreUsuario ,datos[i].contrasena ,&datos[i].genero )!=EOF){
						nusuario++;
						i++;
					}
					printf("Hay %d usuarios dados de alta\n",nusuario);
					
					//Tercer paso cerrar el fichero
					fclose(vpfichero);
					
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
							//system("PAUSE");
						}else{
							printf("Usuario valido\n");
							
							strcpy(datos[nusuario].nombreUsuario,usuarioInicio);
						}
						
					}while(igual==1);
					
					printf("Introduzca contrasena:(con numeros y letras)\n");
					fflush(stdin);
					scanf("%s",datos[nusuario].contrasena);
					printf("Introduce genero(H-Hombre o M-Mujer):\n");
					fflush(stdin);
					scanf("%c",&datos[nusuario].genero);
					
					for(i=0;i<=nusuario;i++){
						printf("%s %s %c\n",datos[i].nombreUsuario,datos[i].contrasena,datos[i].genero);
					}
				
					//Abro en modo escritura
					vpfichero= fopen("usuarios.txt","w");
					
					
					//Ahora lo imprimo al fichero aÒado estos datos.
					for(i=0;i<=nusuario;i++){
				
						fprintf(vpfichero,"%s\n%s\n%c\n",datos[i].nombreUsuario,datos[i].contrasena,datos[i].genero);
					}
					
					//Tercer paso cerrar el fichero
					fclose(vpfichero);
					system("PAUSE");
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
							printf("OpciÛn no disponible\n");
						}
						
						system("PAUSE");
				}while(info!='c');
			
					break;
					
			case 'd':printf("Adios");
					break;
		
			default: 
					printf("Opcion incorrecta\n");
					break;
		}
	
	
	if(opcion=='a' || opcion=='b'){
		do{
			//EDAD BEBE 
			printf("\n");
			printf("---------------ETAPA BEBE------------------------\n");
			printf("Abres los ojos por primera vez y observar a tu alrededor...\nBIENVENIDO A TU NUEVA VIDA!\n");
			printf("Tus padres te han llamado %s y es momento de explorar un poco tu casa\n",usuarioInicio);
		
			printf("----------------------------------------------\n");
			printf("Estas en tu salon y ves en el suelo de tu cuarto varios objetos\n");
			printf("Que decides coger?\n");
			printf("a-Peluche\nb-Potito\nc-Tijeras\n");
			fflush(stdin);
			scanf("%c",&decision);
		
		
			if(decision=='a'){
				printf("Vaya has hecho tu primer amigo\n");
				puntosVida+=10;
			}else if(decision=='b'){
				printf("Oye no es la hora de comer, pero ya sabemos lo que te gusta\n");
				puntosVida+=5;
			}else if(decision=='c'){
				printf("Cuidado!No te cortes el pelo!Menos mal que tu madre ha llegado a tiempo\n");
				puntosVida+=1;
			}else{
				printf("Has introducido mal la opcion. Solo vale a,b o c\n");
			}
			system("PAUSE");
		}while(decision!='a' && decision!='b' && decision!='c');
			
		do{
			printf("----------------------------------------------\n");
			printf("Por fin has andado, has dado tus primeros pasos\n");
			printf("Que te ha animado a hacerlo?\n");
			printf("a-Ha llegado mama, vamos a saludarla\nb-Alcanzar algo\nc-Acariciar al perro\n");
			fflush(stdin);
			scanf("%c",&decision);
		
		
			if(decision=='a'){
				printf("Ella sonrie al verte y te coge en brazos felicitandote\n");
				puntosVida+=10;
			}else if(decision=='b'){
				printf("Te tropiezas y menudo susto para tus padres\n");
				puntosVida+=1;
			}else if(decision=='c'){
				printf("Te lame la cara y quiere jugar contigo\n");
				puntosVida+=5;
			}else{
				printf("Has introducido mal la opcion. Solo vale a,b o c\n");
			}
			system("PAUSE");
		}while(decision!='a' && decision!='b' && decision!='c');
		
		do{
			printf("----------------------------------------------\n");
			printf("Tu padre te esta dando pure de verduras\n");
			printf("Que haces?\n");
			printf("a-No me gusta,lloremos\nb-No me gusta, escupo iugg\nc-Mmm que rico\n");
			fflush(stdin);
			scanf("%c",&decision);
		
			if(decision=='a'){
				printf("Tu padre intenta calmarte, venga abre la boca que viene el avioncito...\n");
				puntosVida+=1;
			}else if(decision=='b'){
				printf("Tu padre se enfada...Venga una mas por mama, otra por papa,otra...\n");
				puntosVida+=5;
			}else if(decision=='c'){
				printf("Tu padre sonrie al ver que te lo tomas.Tienes postre especial!!\n");
				puntosVida+=10;
			}else{
				printf("Has introducido mal la opcion. Solo vale a,b o c\n");
			}
			system("PAUSE");
		}while(decision!='a' && decision!='b' && decision!='c');
		
			printf("----------------------------------------------\n");
			printf("Llega la hora de ir a la guarderia, ya no puedes estar en casa con tus padres\n");
			printf("\n");
			
			longitudUsuario=strlen(usuarioInicio);
			
			if(longitudUsuario%2==0){
				printf("Ha sido toda una aventura tu primer dia. Has hecho amigos y jugado mucho\n");
				puntosVida+=10;
			}else{
				printf("Definitivamente mama era mejor compaÒera de juegos...Menudo dia\n");
				puntosVida+=1;
			}
			system("PAUSE");
		do{
			printf("\n");
			printf("----------------ETAPA INFANCIA------------------------\n");
			printf("Bienvenido al colegio,que nervios\n");
		
			printf("Este es tu primer dÌa de clase:\n");
			printf("a-No lloro ya soy mayor, me pongo a jugar con otros niÒos\nb-Entro timidamente,me pongo a jugar solo pero luego me uno a los dem·s\nc-Me tiro al suelo, me pongo a llorar y me agarro al pie de mi madre. NO QUIEROOO\n");
			fflush(stdin);
			scanf("%c",&decision);
		
		
			if(decision=='a'){
				puntosVida+=10;
			}else if(decision=='b'){
				puntosVida+=5;
			}else if(decision=='c'){
				puntosVida+=1;
			}else{
				printf("Has introducido mal la opcion. Solo vale a,b o c\n");
			}
			system("PAUSE");
		}while(decision!='a' && decision!='b' && decision!='c');
		
		do{
			
			printf("----------------------------------------------\n");
			printf("Ya han pasado muchos aÒos y el perro de la familia a muerto:\n");
			printf("Tus padres te preguntan si quieres otra mascota ya que te ven triste. Que decides?");
			printf("a-No quiero una mascota nueva\nb-Un pez de feria\nc-Un hamster\n");
			fflush(stdin);
			scanf("%c",&decision);
		
		
			if(decision=='a'){
				printf("Parece que aun no superas a tu perro\n");
				puntosVida+=5;
			}else if(decision=='b'){
				printf("Enhorabuena, ha durado tres dias vivo!!\n");
				puntosVida+=10;
			}else if(decision=='c'){
				printf("Tu hamster ha muerto en una trampa para ratas, no debiste dejar la jaula abierta\n");
				puntosVida+=1;
			}else{
				printf("Has introducido mal la opcion. Solo vale a,b o c\n");
			}
			system("PAUSE");
		}while(decision!='a' && decision!='b' && decision!='c');
		
		printf("----------------------------------------------\n");
		printf("Vas a pasar a primaria y temes que te cambien de clase y te separen de tu mejor amigo\n");
		printf("\n");
		if(puntosVida%2==0){
				printf("Vaya tu amigo no est· en la misma clase, mala suerte pero os veis en los recreos\n");
				puntosVida+=1;
			}else{
				printf("Bien!! Ambos estais en la misma clase menuda suerte\n");
				puntosVida+=10;
			}
			system("PAUSE");
		do{
			
			printf("--------------DECISION IMPORTANTE---------------------\n");
			
			printf("Estas en una excursion fuera del colegio.\n");
			printf("Comenzais a cruzar un semaforo pero esta a punto de ponerse en rojo.Que decides?");
			printf("a-No paso y espero a que sea verde\nb-Aun me da tiempo corro\n");
			fflush(stdin);
			scanf("%c",&decision);
		
		
			if(decision=='a'&& puntosVida>=20){
				printf("Es lo m·s sensato, bien hecho\n");
				
			}else if(decision=='b' && puntosVida>=29){
				printf("Vaya has llegado por los pelos, ten m·s cuidado a la proxima!\n");
			
			}else if(decision=='a'&& puntosVida<20){
				printf("Tu no has pasado pero otros de tus compaÒero si. Eso ha asustado a un conductor y ha desviado su coche. Te han atropellado\n");
				
				//Aqui veremos puntos de muerte y destino
				//printf("redactar historia de muerte");
				
				return 0;
			}else if(decision=='b' && puntosVida<29){
				printf("No te ha dado tiempo y un conductor despistado te ha atropellado...\n");
				
				//Aqui veremos puntos de muerte y destino
				//printf("redactar historia de muerte");
				return 0;
			}else{
				printf("Has introducido mal la opcion. Solo vale a,b o c\n");
			}
			system("PAUSE");
		}while(decision!='a' && decision!='b' && decision!='c');
		
		do{
			printf("\n");
			printf("----------------ETAPA ADOLESCENCIA------------------------\n");
			printf("La semana que viene vas a empezar el instituto y tu madre te lleva a comprar ropa\n");
		
			printf(" A por que estilo vas?\n");
			printf("a-Sencillo y basico\nb-Llamativo y moderno, me gusta ser el centro de atencion.\nc-Emo. Odio todo y a todos\n");
			fflush(stdin);
			scanf("%c",&decision);
		
		
			if(decision=='a'){
				puntosVida+=5;
			}else if(decision=='b'){
				puntosVida+=10;
			}else if(decision=='c'){
				puntosVida+=1;
			}else{
				printf("Has introducido mal la opcion. Solo vale a,b o c\n");
			}
			system("PAUSE");
		}while(decision!='a' && decision!='b' && decision!='c');
		
			do{
			
			printf("----------------------------------------------\n");
			printf("Por ?n ha llegado el dÌa, hoy comienzas el instituto! Tienes miedo de que te separen de tus amigos porque os junt·is con gente nueva.\n");
			printf(" Como te relacionas con el resto?:");
			printf("a-me quedo en mi mesa, no soy muy social.\nb-Aunque me cueste un poco hablo con casi todo el mundo, hay que ir conociendo a la gente\nc-Desde el dÌa 1 soy el/la popular de clase, todos me conocen.\n");
			fflush(stdin);
			scanf("%c",&decision);
		
		
			if(decision=='a'){
				printf("Deberias hablar con la gente, podrias llevarte una agradable sorpresa\n");
				puntosVida+=1;
			}else if(decision=='b'){
				printf("Eso es! hay que ir conociendo a la gente nueva\n");
				puntosVida+=10;
			}else if(decision=='c'){
				printf("Ten en cuenta que ahora estas en el punto de mira, ten cuidado...\n");
				puntosVida+=5;
			}else{
				printf("Has introducido mal la opcion. Solo vale a,b o c\n");
			}
			system("PAUSE");
		}while(decision!='a' && decision!='b' && decision!='c');
		
			do{
			printf("----------------------------------------------\n");
			printf("Como es tu grupo de amigos?\n");
			printf("a-muy grande, somos mucha gente porque somos muy sociables\nb-no somos muchos, pero nos bastamos para pasarlo bien.\nc-Amigos?Que es eso?se come?\n");
			fflush(stdin);
			scanf("%c",&decision);
		
			if(decision=='a'){
				puntosVida+=5;
			}else if(decision=='b'){
				puntosVida+=10;
			}else if(decision=='c'){
				puntosVida+=1;
			}else{
				printf("Has introducido mal la opcion. Solo vale a,b o c\n");
			}
			system("PAUSE");
		}while(decision!='a' && decision!='b' && decision!='c');
		
			do{
			printf("----------------------------------------------\n");
			printf("Los estudios se empiezan a poner serios y va siendo hora de ponerse un poco serio para poder elegir una carrera:\n");
			printf("Como llevas el tema de estudiar?\n");
			printf("a-eso de estudiar a mÌ no me gusta nada, si hace falta me pongo a currar pronto\nb-estudio y me esfuerzo, pero no me mato por sacar las mejores notas\nc-Me esfuerzo mucho por sacar las mejores notas posibles, quiero acceder a una buena carrera.\n");
			fflush(stdin);
			scanf("%c",&decision);
		
			if(decision=='a'){
				printf("Tu madre te acaba convenciendo para que estudies, asi podras tener un futuro mejor\n");
				puntosVida+=1;
			}else if(decision=='b'){
				printf("sigue asi, pero no te relajes.\n");
				puntosVida+=5;
			}else if(decision=='c'){
				printf("Animo no te rindas!\n");
				puntosVida+=10;
			}else{
				printf("Has introducido mal la opcion. Solo vale a,b o c\n");
			}
			system("PAUSE");
		}while(decision!='a' && decision!='b' && decision!='c');
		
			do{
			printf("----------------------------------------------\n");
			printf("\n");
			printf("Acabas de terminar 2∫ de Bachiller, no sabes ni como ha pasado tan r·pido, pero ahora toca pasar el mejor verano de tu vida\n");
			printf("En que inviertes tu tiempo?\n");
			printf("a-Me voy de viaje con mis amigos y me paso el verano de fiesta en fiesta, hay que celebrarlo!\nb-viajo con mis amigos y salgo a alguna fiesta, pero tambiÈn disfruto de la tranquilidad del verano\nc-No me gusta el verano, asÌ que me lo paso en casa.\n");
			fflush(stdin);
			scanf("%c",&decision);
		
			if(decision=='a'){
				puntosVida+=10;
			}else if(decision=='b'){
				puntosVida+=5;
			}else if(decision=='c'){
				puntosVida+=1;
			}else{
				printf("Has introducido mal la opcion. Solo vale a,b o c\n");
			}
			system("PAUSE");
		}while(decision!='a' && decision!='b' && decision!='c');
		
		do{
			printf("----------------------------------------------\n");
			printf("\n");
			printf("El verano vuela! Sin darte cuenta ha llegado septiembre y te toca empezar la carrera.\n");
			printf("Que carrera has elegido?\n");
			printf("a-Medicina\nb-Magisterio\nc-Una ingenieria\n");
			fflush(stdin);
			scanf("%c",&decision);
		
			if(decision=='a'){
				printf("Va a ser un camino duro, te saldran callos en los codos");
				puntosVida+=10;
			}else if(decision=='b'){
				printf("Mucha suerte con los collares de macarrones, confiamos en ti.");
				puntosVida+=5;
			}else if(decision=='c'){
				printf("Mucha suerte y mucho animo");
				puntosVida+=1;
			}else{
				printf("Has introducido mal la opcion. Solo vale a,b o c\n");
			}
			system("PAUSE");
		}while(decision!='a' && decision!='b' && decision!='c');
		
		}
	}while(opcion!='d');
}

