#include<stdio.h>
#include<string.h>//Funciones de las cadenas
#define MAX_USUARIOS 100



struct usuario{
	char nombreUsuario[100];
	char contrasena[200];
};
struct final{
	char nombreUsuario[100];
	int puntosMuerte;
};

void bannerRanking();
void Instrucciones(char*info);
void Menu(char *opcion);
int CargarFichero(struct usuario datos[], int *nusuario);
int CargarRanking(struct final resultados[], int *nfinal);
int InicioSesion(char usuarioInicio[], int *nusuario,struct usuario datos[]);
int CrearUsuario(char usuarioInicio[], int *nusuario,struct usuario datos[]);
int Ranking(char usuarioInicio[],int *puntosMuerte, int *nfinal,struct final resultados[]);

int main(){
	char info;
	int longitudUsuario;
	char decision;
	int j;
	int nfinal=0;
	char opcion;
	char usuarioInicio[100];
	int puntosVida=0, puntosMuerte;
	FILE* ffichero;
	struct final resultados[MAX_USUARIOS];
	struct final aux;
	
	FILE * vpfichero;
	int i,igual=0;
	int nusuario=0;
	char contrasenaInicio[200];
	struct usuario datos[MAX_USUARIOS];

	do{
	
	Menu(&opcion);

		switch(opcion)
		{
			case 'a': printf("INICIAR SESION\n");
					
				if(CargarFichero(datos,&nusuario)==0){
					return 0;
				}else{
					InicioSesion(usuarioInicio,&nusuario,datos);
				}	
					break;
			
			case 'b': printf("CREA UN USUARIO\nSigue las instrucciones\n");
					
				if(CargarFichero(datos,&nusuario)==0){
					return 0;
				}else{
					CrearUsuario(usuarioInicio,&nusuario,datos);
				}
				
					break;
		
			case 'c':printf("INSTRUCCIONES:\n");
			
					Instrucciones(&info);
			
					break;
					
			case 'd':printf("Vuelve pronto\n");
					break;
		
			default: 
					printf("Opcion incorrecta\n");
					break;
		}
	
	
	if(opcion=='a' || opcion=='b'){
		do{
			//EDAD BEBE  //1
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
			//2
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
		//3
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
		//4
			printf("----------------------------------------------\n");
			printf("Llega la hora de ir a la guarderia, ya no puedes estar en casa con tus padres\n");
			printf("\n");
			system("PAUSE");
			
			longitudUsuario=strlen(usuarioInicio);
			
			if(longitudUsuario%2==0){
				printf("Ha sido toda una aventura tu primer dia. Has hecho amigos y jugado mucho\n");
				puntosVida+=10;
			}else{
				printf("Definitivamente mama era mejor compañera de juegos...Menudo dia\n");
				puntosVida+=1;
			}
			system("PAUSE");
			//5
		do{
			printf("\n");
			printf("----------------ETAPA INFANCIA------------------------\n");
			printf("Bienvenido al colegio,que nervios\n");
		
			printf("Este es tu primer día de clase:\n");
			printf("a-No lloro ya soy mayor, me pongo a jugar con otros niños\nb-Entro timidamente,me pongo a jugar solo pero luego me uno a los demás\nc-Me tiro al suelo, me pongo a llorar y me agarro al pie de mi madre. NO QUIEROOO\n");
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
		//6
		do{
			
			printf("----------------------------------------------\n");
			printf("Ya han pasado muchos años y el perro de la familia a muerto:\n");
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
		//7
		printf("----------------------------------------------\n");
		printf("Vas a pasar a primaria y temes que te cambien de clase y te separen de tu mejor amigo\n");
		printf("\n");
		if(puntosVida%2==0){
				printf("Vaya tu amigo no está en la misma clase, mala suerte pero os veis en los recreos\n");
				puntosVida+=1;
			}else{
				printf("Bien!! Ambos estais en la misma clase menuda suerte\n");
				puntosVida+=10;
			}
			system("PAUSE");
		do{
			//1 decision importante
			printf("--------------DECISION IMPORTANTE---------------------\n");
			
			printf("Estas en una excursion fuera del colegio.\n");
			printf("Comenzais a cruzar un semaforo pero esta a punto de ponerse en rojo.Que decides?\n");
			printf("a-No paso y espero a que sea verde\nb-Aun me da tiempo corro\n");
			fflush(stdin);
			scanf("%c",&decision);
		
			
			if(decision=='a'&& puntosVida>=20){
				printf("Es lo más sensato, bien hecho\n");
				
			}else if(decision=='b' && puntosVida>=29){
				printf("Vaya has llegado por los pelos, ten más cuidado a la proxima!\n");
			
			}else if(decision=='a'&& puntosVida<20){
				printf("Tu no has pasado pero otros de tus compañero si. Eso ha asustado a un conductor y ha desviado su coche. Te han atropellado\n");
				puntosMuerte=puntosVida;
				
					
				if(CargarRanking(resultados,&nfinal)==0){
					return 0;
				}else{
					Ranking(usuarioInicio,&puntosMuerte,&nfinal,resultados);
					
					//Ordenar el vector
					for(i=0;i<nfinal-1;i++){
						for(j=i+1;j<nfinal;j++){
							if(resultados[i].puntosMuerte <resultados[j].puntosMuerte){
							aux=resultados[i];
							resultados[i]=resultados[j];
							resultados[j]=aux;
							}
						}
					}
				
					bannerRanking();
					for(i=0;i<5;i++){
						printf("%s %d\n",resultados[i].nombreUsuario,resultados[i].puntosMuerte);
					}
					
				}
				return 0;
				
			}else if(decision=='b' && puntosVida<29){
				printf("No te ha dado tiempo y un conductor despistado te ha atropellado...\n");
				puntosMuerte=puntosVida;
				
					
				if(CargarRanking(resultados,&nfinal)==0){
					return 0;
				}else{
					Ranking(usuarioInicio,&puntosMuerte,&nfinal,resultados);
					
					//Ordenar el vector
					for(i=0;i<nfinal-1;i++){
						for(j=i+1;j<nfinal;j++){
							if(resultados[i].puntosMuerte <resultados[j].puntosMuerte){
							aux=resultados[i];
							resultados[i]=resultados[j];
							resultados[j]=aux;
							}
						}
					}
				
					bannerRanking();
					for(i=0;i<5;i++){
						printf("%s %d\n",resultados[i].nombreUsuario,resultados[i].puntosMuerte);
					}
					
				}
				return 0;
			}else{
				printf("Has introducido mal la opcion. Solo vale a,b o c\n");
			}
			system("PAUSE");
		}while(decision!='a' && decision!='b' && decision!='c');
		//8
		do{
			printf("\n");
			printf("----------------ETAPA ADOLESCENCIA-----------------\n");
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
		//9
			do{
			
			printf("----------------------------------------------\n");
			printf("Por fin ha llegado el día, hoy comienzas el instituto! Tienes miedo de que te separen de tus amigos porque os juntáis con gente nueva.\n");
			printf(" Como te relacionas con el resto?:");
			printf("a-me quedo en mi mesa, no soy muy social.\nb-Aunque me cueste un poco hablo con casi todo el mundo, hay que ir conociendo a la gente\nc-Desde el día 1 soy el/la popular de clase, todos me conocen.\n");
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
		//10
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
		//11
			do{
			printf("----------------------------------------------\n");
			printf("Los estudios se empiezan a poner serios y va siendo hora de ponerse un poco serio para poder elegir una carrera:\n");
			printf("Como llevas el tema de estudiar?\n");
			printf("a-eso de estudiar a mí no me gusta nada, si hace falta me pongo a currar pronto\nb-estudio y me esfuerzo, pero no me mato por sacar las mejores notas\nc-Me esfuerzo mucho por sacar las mejores notas posibles, quiero acceder a una buena carrera.\n");
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
		//12
			do{
			printf("----------------------------------------------\n");
			printf("\n");
			printf("Acabas de terminar 2º de Bachiller, no sabes ni como ha pasado tan rápido, pero ahora toca pasar el mejor verano de tu vida\n");
			printf("En que inviertes tu tiempo?\n");
			printf("a-Me voy de viaje con mis amigos y me paso el verano de fiesta en fiesta, hay que celebrarlo!\nb-viajo con mis amigos y salgo a alguna fiesta, pero también disfruto de la tranquilidad del verano\nc-No me gusta el verano, así que me lo paso en casa.\n");
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
		//13
		do{
			printf("----------------ETAPA ADULTO JOVEN----------------\n");
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
		//14
			do{
			printf("----------------------------------------------\n");
			printf("\n");
			printf("La univesidad ha supuesto un cambio en tu vida, nuevo lugar de estudio, nueva gente...\n");
			printf("como te has adaptado?\n");
			printf("a-Me he dejado la vida en aprobarlo todo y lo he conseguido, aunque eso ha supuesto que no haya socializado en exceso.\n");
			printf("b- he conseguido aprobar todo/casi todo y a su vez he podido divertirme .\nc- FIESTAAA!!!!!!\n");
			fflush(stdin);
			scanf("%c",&decision);
		
			if(decision=='a'){
				printf("Estudiar esta bien, pero tambien debeias socializar un poco");
				puntosVida+=5;
			}else if(decision=='b'){
				printf("Ese equilibrio esta bien :)");
				puntosVida+=10;
			}else if(decision=='c'){
				printf("Esta muy bien que disfrutes de la vida universitaria, pero estás alli para aprender...");
				puntosVida+=1;
			}else{
				printf("Has introducido mal la opcion. Solo vale a,b o c\n");
			}
			system("PAUSE");
		}while(decision!='a' && decision!='b' && decision!='c');
		//15
			printf("----------------------------------------------\n");
		printf("Se rumorea por la facultad que hay alguien  a quien le gustas:\n");
		printf("\n");
		if(puntosVida%2==0){
				printf("-¡Es tu crush\n");
				puntosVida+=10;
			}else{
				printf("-No sabias de su existencia hasta ahora ._.\n");
				puntosVida+=1;
			} 
			//16
		do{
			printf("\n");
			printf("Que haras al respecto?\n");
			printf("a-Mira yo paso de compromisos, Tengo toda la vida por delante!\nb-Le contacto inmediatamente, que emocionante!\n-Si tiene que pasar algo que pase, dejo que todo fluya-\n");
			fflush(stdin);
			scanf("%c",&decision);
		
			if(decision=='a'){
				puntosVida+=5;
			}else if(decision=='b'){
				puntosVida+=1;
			}else if(decision=='c'){
				puntosVida+=10;
			}else{
				printf("Has introducido mal la opcion. Solo vale a,b o c\n");
			}
			system("PAUSE");
		}while(decision!='a' && decision!='b' && decision!='c');
			system("PAUSE");
			// 2 decision importante
			do{
			printf("----------DECISION IMPORTANTE----------\n");
			printf("\n");
			printf("Tras muchos esfuerzos y sudores has conseguido acabar la universidad. Ahora toca empezar una nueva etapa\n");
			printf("Que haces?\n");
			printf("a-Soy una persona muy emprendedora y he hecho un estudio de mercado y he llegado a la conclusion de crear una empresa de gomas de pelo a medida\n");
			printf("b-Me tomo un año sabatico, recorrere el mundo y conocere infinitos lugares nuevos\n");
			printf("c-Me dedico a mandar mi curriculum a todos lados, hay que trabajar!\n");
			fflush(stdin);
			scanf("%c",&decision);
		
			if(decision=='a'){
				if(puntosVida<90){
					printf("Sorprendentemente la empresa iba mejor de lo esperado, pero un dia se produce un atraco en la tienda y tu estabas presente.\n");
					printf("El robo se complica y acabas con un tiro en la frente\n");
					
					puntosMuerte=puntosVida;
				
					
				if(CargarRanking(resultados,&nfinal)==0){
					return 0;
				}else{
					Ranking(usuarioInicio,&puntosMuerte,&nfinal,resultados);
					
					//Ordenar el vector
					for(i=0;i<nfinal-1;i++){
						for(j=i+1;j<nfinal;j++){
							if(resultados[i].puntosMuerte <resultados[j].puntosMuerte){
							aux=resultados[i];
							resultados[i]=resultados[j];
							resultados[j]=aux;
							}
						}
					}
				
					bannerRanking();
					for(i=0;i<5;i++){
						printf("%s %d\n",resultados[i].nombreUsuario,resultados[i].puntosMuerte);
					}
					
				}
				return 0;
					
				}else{
					printf("La empresa se estaba arrastrando economicamente, hasta que por motivos que nadie conoce se hizo popular en instagram customizar tus gomas de pelo\n");
				}
			}else if(decision=='b'){
				if(puntosVida<130){
					printf("Dia 168: Hoy toca dia de viaje, acabo de llegar al aeropuerto y en un rato sale el avion\n");
					printf("Esa fue la ultima entrada de tu diario de viaje, en el aeropuerto alguien coloco una bomba y hubo 50 muertos, entre los cueles estas tu.\n");
					
					puntosMuerte=puntosVida;
				
					
				if(CargarRanking(resultados,&nfinal)==0){
					return 0;
				}else{
					Ranking(usuarioInicio,&puntosMuerte,&nfinal,resultados);
					
					//Ordenar el vector
					for(i=0;i<nfinal-1;i++){
						for(j=i+1;j<nfinal;j++){
							if(resultados[i].puntosMuerte <resultados[j].puntosMuerte){
							aux=resultados[i];
							resultados[i]=resultados[j];
							resultados[j]=aux;
							}
						}
					}
				
					bannerRanking();
					for(i=0;i<5;i++){
						printf("%s %d\n",resultados[i].nombreUsuario,resultados[i].puntosMuerte);
					}
					
				}
				return 0;
				}else{
					printf("El viaje fue muy divertido y conociste muchas culturas nuevas. Ahora eres una persona nueva, pero toca empezar a buscar un trabajo\n");
				}
			}else if(decision=='c'){
				if(puntosVida<35){
					printf("De camino a ir a echar mas curriculums fuiste victima de un accidente automovilistico. No sobrevives.\n");
					puntosMuerte=puntosVida;
				
					
				if(CargarRanking(resultados,&nfinal)==0){
					return 0;
				}else{
					Ranking(usuarioInicio,&puntosMuerte,&nfinal,resultados);
					
					//Ordenar el vector
					for(i=0;i<nfinal-1;i++){
						for(j=i+1;j<nfinal;j++){
							if(resultados[i].puntosMuerte <resultados[j].puntosMuerte){
							aux=resultados[i];
							resultados[i]=resultados[j];
							resultados[j]=aux;
							}
						}
					}
				
					bannerRanking();
					for(i=0;i<5;i++){
						printf("%s %d\n",resultados[i].nombreUsuario,resultados[i].puntosMuerte);
					}
					
				}
				return 0;
				}else{
					printf("Por fin te han llegado respuestas de varias empresas, Y quieren entrevistarte!!\n");
				}
			}else{
				printf("Has introducido mal la opcion. Solo vale a,b o c\n");
			}
			system("PAUSE");
		}while(decision!='a' && decision!='b' && decision!='c');
			//17
			do{
			printf("----------------------------------------------\n");
			printf("\n");
			printf("La etapa en tu primer trabajo ha concluido, ahora toca cambiar de lugar\n");
			printf("Como te desenvuelves en el nuevo entorno?\n");
			printf("a-Mi superior es una persona estupida, pero afortunadamente me van a ascender dentro de poco y no tendré que soportarle mas.\n");
			printf("b-En seguida hago migas con mis compañeros y con todo el mundo en general, estoy feliz en este puesto.\n");
			printf("c-No puedo esperar a cambiar de trabajo, estoy pensando en comprar una pequeña empresa con el dinero de una herencia familiar.\n");
			fflush(stdin);
			scanf("%c",&decision);
		
			if(decision=='a'){
				puntosVida+=1;
			}else if(decision=='b'){
				puntosVida+=10;
			}else if(decision=='c'){
				puntosVida+=5;
			}else{
				printf("Has introducido mal la opcion. Solo vale a,b o c\n");
			}
			system("PAUSE");
		}while(decision!='a' && decision!='b' && decision!='c');
		//18
			printf("----------------------------------------------\n");
			printf("\n");
			printf("Tus “queridos compañeros de trabajo” te han organizado una cita a ciegas\n");
			printf("alegando que llevas demasiado tiempo sin pareja porque ninguna de tus relaciones \n");
			printf("pasadas llegaron a ningún lado. Han reservado una cena en un restaurante, incluso \n");
			printf("te han llevado a comprar ropa.\n");
			
			system("PAUSE");
			
			longitudUsuario=strlen(usuarioInicio);
			
			if(longitudUsuario%2==0){
				printf("-La cita fue un completo desastre, la otra persona era insoportable y acabó\n");
				printf("escupiéndote el vino en la cara cuando le comentaste que no te lo estabas pasando \n");
				printf("bien. De camino a casa te paraste en un bar para ahogar las penas y no pasó nada.\n");
				printf("Pero dos días después mientras estabas en la frutería esperando a tu turno te \n");
				printf("reencuentras con tu crush del instituto y salta la chispa\n");
				puntosVida+=1;
			}else{
				printf("-Al final la otra persona resultó ser muy amable y saltó la chispa. Ahora estáis\n");
				printf("comenzando una relación.");
				puntosVida+=10;
			}
			system("PAUSE");
		do{
			//19
			printf("----------------------------------------------\n");
			printf("\n");
			printf("Es hora de decidir que vas a hacer con la casa\n");
			printf("a-Vivir de alquiler y me podre cambiar de casa cuando quiera\nb-Compro casa porque es la que quiero, no tengo dudas, auque tenga que solicitar una hipoteca\nc-De hecho me voy a mudar a otra ciudad\n");
			fflush(stdin);
			scanf("%c",&decision);
		
			if(decision=='a'){
				puntosVida+=1;
			}else if(decision=='b'){
				puntosVida+=5;
			}else if(decision=='c'){
				puntosVida+=10;
			}else{
				printf("Has introducido mal la opcion. Solo vale a,b o c\n");
			}
			system("PAUSE");
		}while(decision!='a' && decision!='b' && decision!='c');
		
		do{
			//20
			printf("----------------------------------------------\n");
			printf("\n");
			printf("Tu relación progresa correctamente, y ha llegado el momento. \n");
			printf("Cuantos hijos tendréis?\n");
			printf("a-2\nb-3\nc-0\n");
			
			fflush(stdin);
			scanf("%c",&decision);
		
			if(decision=='a'){
				printf("Seguro que se llevaran genial\n");
				puntosVida+=10;
			}else if(decision=='b'){
				printf("Ese equilibrio esta bien :)");
				puntosVida+=10;
			}else if(decision=='c'){
				printf("Esta muy bien que disfrutes de la vida universitaria, pero estás alli para aprender...");
				puntosVida+=1;
			}else{
				printf("Has introducido mal la opcion. Solo vale a,b o c\n");
			}
			system("PAUSE");
		}while(decision!='a' && decision!='b' && decision!='c');
		do{
			//EDAD ADULTO FORMADO 21
			printf("\n");
			printf("---------------ETAPA ADULTO FORMADO------------------------\n");
			printf("\n");
			printf("Echas de menos a tu ex\n");
			printf("Que haces?\n");
			printf("a-Llamarle al movil\nb-Ir a su casa a hablar\nc-Quedarme en casa llorando\n");
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
			//22
			printf("----------------------------------------------\n");
			printf("\n");
			printf("Cual te gustaria que fuese tu situacion personal actual?\n");
			printf("a-Ella perrea sola, madurez? Que es eso?\nb- Mi familia lo es todo para mi\nc-Mi pareja y yo no queremos hijos la verdad\n");
			fflush(stdin);
			scanf("%c",&decision);
		
			if(decision=='a'){
				puntosVida+=1;
			}else if(decision=='b'){
				puntosVida+=10;
			}else if(decision=='c'){
				puntosVida+=5;
			}else{
				printf("Has introducido mal la opcion. Solo vale a,b o c\n");
			}
			system("PAUSE");
		}while(decision!='a' && decision!='b' && decision!='c');
		do{
			//23
			printf("----------------------------------------------\n");
			printf("\n");
			printf("En tus ultimos años de trabajo.Cual te gustaria que fuese tu situacion laboral actual?\n");
			printf("a-Estoy creando una pequeña empresa que esta despegando\nb-Trabajo en una gran empresa, aunque mi jefe me tiene mania y no tiene pinta de que me vaya a ascender\nc-Trabajo en la empresa familiar\n");
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
			printf("--------------DECISION IMPORTANTE---------------------\n");
			printf("Estas llegando tarde a una cita con uno de los proveedores mas importantes para la empresa y el mas exigente, sus representantes siempre miran por encima del hombro con superioridad\n");
			printf("Que vas a hacer?");
			printf("a-Cojo el coche y piso el acelerador\nb-Voy andando, hay que mantenerse en forma\n");
			fflush(stdin);
			scanf("%c",&decision);
		
		
			if(decision=='a'&& puntosVida>=30){
				printf("HAS SUFRIDO UN TRAJICO ACCIDENTE Y HAS MUERTO\n");
				puntosMuerte=puntosVida;
				
					
				if(CargarRanking(resultados,&nfinal)==0){
					return 0;
				}else{
					Ranking(usuarioInicio,&puntosMuerte,&nfinal,resultados);
					
					//Ordenar el vector
					for(i=0;i<nfinal-1;i++){
						for(j=i+1;j<nfinal;j++){
							if(resultados[i].puntosMuerte <resultados[j].puntosMuerte){
							aux=resultados[i];
							resultados[i]=resultados[j];
							resultados[j]=aux;
							}
						}
					}
				
					bannerRanking();
					for(i=0;i<5;i++){
						printf("%s %d\n",resultados[i].nombreUsuario,resultados[i].puntosMuerte);
					}
					
				}
				return 0;
			}else if(decision=='b' && puntosVida>=37){
				printf("Muy bien, andar 30 minutos a dia es lo mas recomendable\n");
			
			}else if(decision=='b' && puntosVida<37){
				printf("Bro has llegado tarde, te han despedido\n");
				puntosMuerte=puntosVida;
				
					
				if(CargarRanking(resultados,&nfinal)==0){
					return 0;
				}else{
					Ranking(usuarioInicio,&puntosMuerte,&nfinal,resultados);
					
					//Ordenar el vector
					for(i=0;i<nfinal-1;i++){
						for(j=i+1;j<nfinal;j++){
							if(resultados[i].puntosMuerte <resultados[j].puntosMuerte){
							aux=resultados[i];
							resultados[i]=resultados[j];
							resultados[j]=aux;
							}
						}
					}
				
					bannerRanking();
					for(i=0;i<5;i++){
						printf("%s %d\n",resultados[i].nombreUsuario,resultados[i].puntosMuerte);
					}
					
				}
				return 0;
			}else{
				printf("Has introducido mal la opcion. Solo vale a o b\n");
			}
			system("PAUSE");
			
		}while(decision!='a' && decision!='b' && decision!='c');
		do{
			//24
			printf("----------------------------------------------\n");
			printf("\n");
			printf("Se dice por ahi que va a haber un ascenso, va a haber que hacer una pequeña presentacion y un examen psicologico, lo haces?\n");
			printf("a-Voy a ir a probar\nb-No, ya estoy muy comodo con el sueldo actual\nc-Voy al 100%, van a quedarse boquiabiertos, aunque eso requiera romper con mi pareja y/o familia\n");
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
			//EDAD JUBILACION 4 decision importante
			printf("\n");
			printf("---------------ETAPA JUBILADO------------------------\n");
			printf("La verdad que nadie confiaba en que llegases a ser tan mayor, al menos los que te conocieron de joven ¡ENHORABUENA!\n");
		
			printf("--------------DECISION IMPORTANTE---------------------\n");
			printf("Al final, como has organizado tu vida?\n");
			printf("a- Voy a meter mis ahorros en una cuenta en un paraiso fiscal\nb-He dejado un poco de lado a mi familia por el trabajo\n");
			fflush(stdin);
			scanf("%c",&decision);
		
		
			if(decision=='a'&& puntosVida>=80){
				printf("Ahora a vivir la vida buena, aunque fuera de España, claro esta\n");
				
			}else if(decision=='b' && puntosVida>=70){
				printf("Tu familia te esta agradecida aunque no van a volver a perdonarte si vuelves a alejarte por dinero\n");
			
			}else if(decision=='a'&& puntosVida<80){
				printf("La policia te ha pillado, han congelado tus cuentas, has salido en la tele. Un grupo de jovenes cuyos padres trabajaban a tu cargo se han sentido estafados y te han seguido a casa. Has muerto asesinado\n");
				puntosMuerte=puntosVida;
				
					
				if(CargarRanking(resultados,&nfinal)==0){
					return 0;
				}else{
					Ranking(usuarioInicio,&puntosMuerte,&nfinal,resultados);
					
					//Ordenar el vector
					for(i=0;i<nfinal-1;i++){
						for(j=i+1;j<nfinal;j++){
							if(resultados[i].puntosMuerte <resultados[j].puntosMuerte){
							aux=resultados[i];
							resultados[i]=resultados[j];
							resultados[j]=aux;
							}
						}
					}
				
					bannerRanking();
					for(i=0;i<5;i++){
						printf("%s %d\n",resultados[i].nombreUsuario,resultados[i].puntosMuerte);
					}
					
				}
				return 0;
			}else if(decision=='b' && puntosVida<70){
				printf("Tu familia no ha podido olvidar que los dejaste de lado y ahora te han internado de una residencia y mueres solo\n");
				puntosMuerte=puntosVida;
				
					
				if(CargarRanking(resultados,&nfinal)==0){
					return 0;
				}else{
					Ranking(usuarioInicio,&puntosMuerte,&nfinal,resultados);
					
					//Ordenar el vector
					for(i=0;i<nfinal-1;i++){
						for(j=i+1;j<nfinal;j++){
							if(resultados[i].puntosMuerte <resultados[j].puntosMuerte){
							aux=resultados[i];
							resultados[i]=resultados[j];
							resultados[j]=aux;
							}
						}
					}
				
					bannerRanking();
					for(i=0;i<5;i++){
						printf("%s %d\n",resultados[i].nombreUsuario,resultados[i].puntosMuerte);
					}
					
				}
				return 0;
			}else{
				printf("Has introducido mal la opcion. Solo vale a o b\n");
			}
			system("PAUSE");
		}while(decision!='a' && decision!='b' && decision!='c');
		do{
			//25
			printf("----------------------------------------------\n");
			printf("Uno de tus hijos va a tener un hijo prematuro, te pide ayuda y consejo\n");
			printf("Como reaccionas?\n");
			printf("a-Mi primer nieto!!Todo lo que haga falta voy a hacer\nb-Mi primer nieto!!Estoy mayor pero hare lo que pueda\nc-Tu hijo, tu responsabilidad\n");
			fflush(stdin);
			scanf("%c",&decision);
		
		
			if(decision=='a'){
				printf("Pero recuerda que no es tu hijo eh\n");
				puntosVida+=10;
			}else if(decision=='b'){
				printf("Te agradece mucho el esfuerzo\n");
				puntosVida+=5;
			}else if(decision=='c'){
				printf("Joe de verdad que egoista eres a veces\n");
				puntosVida+=1;
			}else{
				printf("Has introducido mal la opcion. Solo vale a,b o c\n");
			}
			system("PAUSE");
		}while(decision!='a' && decision!='b' && decision!='c');
		do{
			//26
			printf("----------------------------------------------\n");
			printf("Discusion entre tu hijo y tu nieto\n");
			printf("Que haces?\n");
			printf("a-Apoyar a tu nieto contando una historia dejando en evidencia a tu hijo\nb-Apoyar a tu hijo, ser padre es dificil\nc-Te vas y evitas participar\n");
			fflush(stdin);
			scanf("%c",&decision);
		
			if(decision=='a'){
				printf("Tu nieto te adora, pero te espera una bronca por parte de tu hijo\n");
				puntosVida+=1;
			}else if(decision=='b'){
				printf("Gracias papa; EN SERIO ABUELO?\n");
				puntosVida+=10;
			}else if(decision=='c'){
				printf("Chuches para todos, ya habra tiempo de hablarlo\n");
				puntosVida+=5;
			}else{
				printf("Has introducido mal la opcion. Solo vale a,b o c\n");
			}
			system("PAUSE");
		}while(decision!='a' && decision!='b' && decision!='c');
		
		printf("----------------------------------------------\n");
			printf("CORONAVIRUS se recomienda que te quedes en casa\n");
			printf("Que sucede?\n");
			
			longitudUsuario=strlen(usuarioInicio);
			
			if(longitudUsuario%2==0){
				printf("Lo cogiste antes de la alerta, mueres solo en casa\n");
				puntosMuerte=puntosVida;
				
					
				if(CargarRanking(resultados,&nfinal)==0){
					return 0;
				}else{
					Ranking(usuarioInicio,&puntosMuerte,&nfinal,resultados);
					
					//Ordenar el vector
					for(i=0;i<nfinal-1;i++){
						for(j=i+1;j<nfinal;j++){
							if(resultados[i].puntosMuerte <resultados[j].puntosMuerte){
							aux=resultados[i];
							resultados[i]=resultados[j];
							resultados[j]=aux;
							}
						}
					}
				
					bannerRanking();
					for(i=0;i<5;i++){
						printf("%s %d\n",resultados[i].nombreUsuario,resultados[i].puntosMuerte);
					}
					
				}
				return 0;
			}else{
				printf("Ten cuidado, eres poblacion de riesgo\n");
			}
			system("PAUSE");
		do{
			// 5 decision importante
			printf("--------------------DECISION IMPORTANTE--------------------------\n");
			printf("Has de bajar a hacer la compra\n");
			printf("Que haces?\n");
			printf("a-Avisar a tus vecinos\nb-Avisar a tu hijo\nc-Bajar porque tengo dos piernas y dos brazos\n");
			fflush(stdin);
			scanf("%c",&decision);
		
			if(decision=='a'){
				printf("Tus vecinos van a hacerte a compra, no hay de que preocuparse\n");
				puntosVida+=10;
			}else if(decision=='b'){
				printf("Lo siente pero tiene que mirar por su bien, vas a tener que ir tu, el tiene ninos pequenos que no se cuidan solos\n");
				puntosVida+=0;
			}else if(decision=='c'){
				printf("Te lo has buscado tu solo, has muerto\n");
				puntosMuerte=puntosVida;
				
					
				if(CargarRanking(resultados,&nfinal)==0){
					return 0;
				}else{
					Ranking(usuarioInicio,&puntosMuerte,&nfinal,resultados);
					
					//Ordenar el vector
					for(i=0;i<nfinal-1;i++){
						for(j=i+1;j<nfinal;j++){
							if(resultados[i].puntosMuerte <resultados[j].puntosMuerte){
							aux=resultados[i];
							resultados[i]=resultados[j];
							resultados[j]=aux;
							}
						}
					}
				
					bannerRanking();
					for(i=0;i<5;i++){
						printf("%s %d\n",resultados[i].nombreUsuario,resultados[i].puntosMuerte);
					}
					
				}
				return 0;
			}else{
				printf("Has introducido mal la opcion. Solo vale a,b o c\n");
			}
			system("PAUSE");
		}while(decision!='a' && decision!='b' && decision!='c');
		
		printf("----------------------------------------------\n");
		//27
			printf("Feliz 103 cumpleanos!\n");
			printf("En realidad te estas muriendo, tu funeral es\n");
			
			longitudUsuario=strlen(usuarioInicio);
			
			if(longitudUsuario%2==0){
				printf("Multitudinario, todos te quieren mucho, pero es un poco deprimente\n");
			}else{
				printf("Pequeno, solo los mas cercanos estan, te recuerdan y saben que tu deseaba una gran fiesta\n");
			}
			system("PAUSE");
			printf("Enhorabuena!! Has logrado tener una vida longeva y has tomado buenas decisiones( o no)\n");
			puntosMuerte=puntosVida;
				
					
				if(CargarRanking(resultados,&nfinal)==0){
					return 0;
				}else{
					Ranking(usuarioInicio,&puntosMuerte,&nfinal,resultados);
					
					//Ordenar el vector
					for(i=0;i<nfinal-1;i++){
						for(j=i+1;j<nfinal;j++){
							if(resultados[i].puntosMuerte <resultados[j].puntosMuerte){
							aux=resultados[i];
							resultados[i]=resultados[j];
							resultados[j]=aux;
							}
						}
					}
				
					bannerRanking();
					for(i=0;i<5;i++){
						printf("%s %d\n",resultados[i].nombreUsuario,resultados[i].puntosMuerte);
					}
					
				}
				return 0;		
	}
	}while(opcion!='d');
}
void bannerRanking(){
	
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
	printf("%c--RANKING--  %c\n",186,186);
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,188);

}
void Menu(char *opcion){
	
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
	scanf("%c",&*opcion);
	
}
int InicioSesion(char usuarioInicio[], int *nusuario,struct usuario datos[]){
	//FILE * vpfichero;
	int i,igual=0;
	//int nusuario=0;
	char contrasenaInicio[200];
	//struct usuario datos[MAX_USUARIOS];
				
					//Pedir los datos de iniciar sesion al usuario
				do{
					
					printf("Introduzca  nombre de usuario:\n");
					fflush(stdin);
					scanf("%s",usuarioInicio);
					printf("Introduzca contrasena:(con numeros y letras)\n");
					fflush(stdin);
					scanf("%s",contrasenaInicio);
					
					//Tenemos que ver que efectivamente existe ese usuario y contraseña.
					for(i=0;i<*nusuario;i++){
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
					}while(igual==0);//Eso es que serían diferentes y no vuelve a preguntar.
				
}
int CargarFichero(struct usuario datos[], int *nusuario){
	
	FILE * vpfichero;
	int i;
	
		//Primero abrir el fichero
		vpfichero= fopen("usuarios.txt","r");//Modo lectura
					
		//Comprueba si encuentra el fichero si no lo siguiente no va
		if(vpfichero==NULL){
			printf("No se ha podido encontrar el fichero\n");
			return 0;
		}
					
		//Miremos cuantos usuarios ya hay en ese fichero y guardas en vector
			i=0;
			while(fscanf(vpfichero,"%s %s",&datos[i].nombreUsuario,&datos[i].contrasena)!=EOF){
			//*nusuario++;
			i++;
		}
		*nusuario=i;
		//printf("Hay %d usuarios dados de alta\n",*nusuario);
					
		//Tercer paso es siempre cerrar el fichero al final
		fclose(vpfichero);
		return 1;
}
int CrearUsuario(char usuarioInicio[], int *nusuario,struct usuario datos[]){
	
	FILE * vpfichero;
	int i,igual=0;
	char contrasenaInicio[200];
		//Pedir los datos al usuario
		
					//Ahora tenemos que comprobar si el usuario es correcto y no se parece a otro.
					do{
						printf("Introduzca  nombre de usuario:\n");
						fflush(stdin);
						scanf("%s",usuarioInicio);
						for(i=0;i<*nusuario;i++){
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
							
							strcpy(datos[*nusuario].nombreUsuario,usuarioInicio);
						}
						
					}while(igual==1);
					
					printf("Introduzca contrasena:(con numeros y letras)\n");
					fflush(stdin);
					scanf("%s",datos[*nusuario].contrasena);
					
					//Abro en modo escritura
					vpfichero= fopen("usuarios.txt","w");
					
					
					//Ahora lo imprimo al fichero añado estos datos.
					for(i=0;i<=*nusuario;i++){
				
						fprintf(vpfichero,"%s\n%s\n",datos[i].nombreUsuario,datos[i].contrasena);
					}
					
					//Tercer paso cerrar el fichero
					fclose(vpfichero);
					system("PAUSE");
}
void Instrucciones(char*info){
	printf("En este juego recorreras las distintas etapas de tu vida virtual. Comenzaras siendo un\nbebe y mediante la toma de decisiones iras creciendo a lo largo del tiempo. Hay\ndistintos tipos de decisiones, unos te haran ganar puntos de vida que te serviran\npara poder seguir adelante cuando tengas que tomar una decision importante.\nTambien estan los puntos de muerte que te seran utiles a la hora del juicio final para\ndeterminar donde ira tu alma.\n");
	printf("\n");
	printf("IMPORTANTE: Para que el juego funcione debes crear en tu equipo un fichero usuarios.txt y otro llamado ranking.txt\nambos vacios\n");
					
		do{
					
			printf("Para mas informacion pulse:\n");
			printf("-----------------------\n");
			printf("a-Tipos de decisiones\n");
			printf("b-Tipos de puntos\n");
			printf("c-Salir de este menu\n");
			printf("-----------------------\n");
			fflush(stdin);
			scanf("%c",&*info);
					
			if(*info=='a'){
				printf("TIPOS DE DECISIONES\n");
				printf("Decisiones simples: segun las respondas te sumaran puntos a puntos de vida y puntos de muerte\n");
				printf("\n");
				printf("Decisiones importantes: saltara un aviso cuando aparezcan en el juego\ny necesitaras un minimo de puntos de vida para superarlas.\n");
				printf("Ejemplo: sale una decision importante con dos opciones a o b.\nCada una requiere un minimo de puntos de vida para avanzar, solo que el usuario no lo sabe.\nEntonces si no tienes los puntos necesarios mueres.Es cuestion de SUERTE\n");
			}else if(*info=='b'){
				printf("TIPOS DE PUNTOS\n");
				printf("Puntos de vida: puntos obtenidos por tus decisiones realizadas.\nTambien seran necesarios para superar las decisiones importantes\n");
				printf("\n");
				printf("Puntos de muerte: puntos que se iran acumulando segun tus decisiones y en el caso de morir deciden tu destino final\n");
			}else if(*info=='c'){
				break; 
			}else{
				printf("Opción no disponible\n");
			}			
			system("PAUSE");
		}while(*info!='c');
}
int CargarRanking(struct final resultados[], int *nfinal){
	
	FILE * ffichero;
	int i;
	
		//Primero abrir el fichero
		ffichero= fopen("ranking.txt","r");//Modo lectura
					
		//Comprueba si encuentra el fichero si no lo siguiente no va
		if(ffichero==NULL){
			printf("No se ha podido encontrar el fichero\n");
			return 0;
		}
					
		//Miremos cuantos usuarios ya hay en ese fichero y guardas en vector
			i=0;
			while(fscanf(ffichero,"%s %d",&resultados[i].nombreUsuario ,&resultados[i].puntosMuerte)!=EOF){
			//*nusuario++;
			i++;
		}
		*nfinal=i;
		printf("Hay %d usuarios dados muertos\n",*nfinal);
					
		//Tercer paso es siempre cerrar el fichero al final
		fclose(ffichero);
		return 1;
					
}
int Ranking(char usuarioInicio[],int *puntosMuerte, int *nfinal,struct final resultados[]){
	FILE * ffichero;
	int i,j;
	int igual=0;
	struct final aux;
	
	
	//Tenemos que ver que efectivamente existe ese usuario.
	for(i=0;i<*nfinal;i++){
		if(strcmp(usuarioInicio,resultados[i].nombreUsuario)==0){
			igual=1;
			break;
		}else{
			igual=0;
		}
	}
						
	if(igual==0){
		printf("Nuevo usuario muerto\n");
		strcpy(resultados[*nfinal].nombreUsuario,usuarioInicio);
		resultados[*nfinal].puntosMuerte=*puntosMuerte;
							
	}else{
		printf("Ya moriste en otra partida\n");
		resultados[i].puntosMuerte=*puntosMuerte;
	}
	system("PAUSE");
	fclose(ffichero);
	
	ffichero=fopen("ranking.txt","w");
	//Ahora lo imprimo al fichero añado estos datos.
	for(i=0;i<=*nfinal;i++){
				
		fprintf(ffichero,"%s\n%d\n",resultados[i].nombreUsuario,resultados[i].puntosMuerte);
	}			
	//Tercer paso cerrar el fichero
	fclose(ffichero);				
}
	

