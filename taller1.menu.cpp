#include <iostream>
#include<string.h>
#include<windows.h>
#include<conio.h>
//#include<math.h>
//#include <stdlib.h> 
//#include <time.h> 
using namespace std;
/* */

void cordxy( int x,int y)
{
COORD coord;
coord.X=x;
coord.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);	
}
void cuadropantalla(int ancho, int largo){
	int i;
	//columna
	for(i=0;i<ancho;i++){
		cordxy(5,i);printf("\263");
		cordxy(largo,i);printf("\263");
	}
	//fila
	for(i=6;i<largo;i++){
		cordxy(i,0);printf("\304");
		cordxy(i,ancho);printf("\304");
	}
	//esquina superior izquierda
	cordxy(5,0);printf("\332");
	//esquina superior derecha
	cordxy(largo,0);printf("\277");
	//esquina inferior derecha
	cordxy(5,ancho);printf("\300");
	//esquina inferior izquierda
	cordxy(largo,ancho);printf("\331");
}
struct clients{
	int id_client;
	char cedula[20];
	char name[40];
	char direction[40];
	char tell[20];
	
}client[100],*pclient=client;

struct prodcuts{
	int id_product;
	char name[40];
	float price;
	
}product[50],*pproduct=product;

struct facturas{
	int id_factura;
	int id_client;
	int id_product;
	int product[20];
	int cant[50];
	float total;
	bool stade;	
}factura[100],*pfactura=factura;

int numclients=0,numproducts=0,i,j,cantclients=0,cantproducts=0,cantfacturas=0;
float changed;
void crear_client( ){
	system("color 0a");
	cuadropantalla(24,80);
    cordxy(6,3);printf(" ingrese la cantidad de clientes:");
    cordxy(6,4);scanf("%d",&numclients);
    int sumclients=cantclients+numclients;
   for(i=cantclients;i<=sumclients;i++){
	  (pclient+i)->id_client=i;
	  system("color 0a");
	  cuadropantalla(24,80);
	  cordxy(6,6);printf("Cliente: %d",(pclient+i)->id_client);
	  fflush(stdin);
	  cordxy(6,7);printf("Numero de Cedula: ");
	  cordxy(6,8);fgets((pclient+i)->cedula,20,stdin);
	  cordxy(6,9);printf("Nombre:");
	  cordxy(6,10);fgets((pclient+i)->name,40,stdin);
	  cordxy(6,11);printf("Direccion: ");
	  cordxy(6,12);fgets((pclient+i)->direction,40,stdin);
	  cordxy(6,13);printf("Telefono: ");
	  cordxy(6,14);fgets((pclient+i)->tell,20,stdin);
	  fflush(stdin);
	  system("cls");
}
cantclients=cantclients+numclients;
}

void ver_client(){
	system("color 0a");
	for(i=0;i<=cantclients;i++){
		printf("\n -------------------------------------------------------------- \n");
        printf("Id_Cliente: %d \n",(pclient+i)->id_client);
        printf("Nombre: %s \n",(pclient+i)->name);
        printf("Cedula: %s \n",(pclient+i)->cedula);
        printf("Direccion: %s \n",(pclient+i)->direction);
        printf("Telefono: %s \n",(pclient+i)->tell);
	}

}

void modific_client(){
	cuadropantalla(24,80);
	int id;
	int number;
	char change[30];
	cordxy(6,5);printf("ingrese el id_cliente que desea modificar: ");
	cordxy(6,6);scanf("%d",&id);
	system("cls");
	for(i=1;i<=cantclients;i++){
		if((pclient+i)->id_client==id){
			cuadropantalla(24,80);
			cordxy(6,7);printf("1.Nombre: %s",(pclient+i)->name);
			cordxy(6,8);printf("2.Cedula: %s \n",(pclient+i)->cedula);
            cordxy(6,9);printf("3.Direccion: %s \n",(pclient+i)->direction);
            cordxy(6,10);printf("4.Telefono: %s \n",(pclient+i)->tell);
            cordxy(6,11);printf("ingrese el numero del campo que desea modificar: ");
            cordxy(6,12);scanf("%d",&number);
            switch (number){
            	case 1:{
            		fflush(stdin);
            		cordxy(6,14);printf("Nuevo Nombre: ");
            		cordxy(6,15);fgets(change,40,stdin);
            		cordxy(6,16);strcpy((pclient+i)->name,change);
            		cordxy(6,17);printf("Su Nuevo Nombre es: %s",(pclient+i)->name);
					break;
				}
				case 2:{
					fflush(stdin);
            		cordxy(6,14);printf("Nueva Cedula: ");
            		cordxy(6,15);fgets(change,20,stdin);
            		cordxy(6,16);strcpy((pclient+i)->cedula,change);
            		cordxy(6,17);printf("Su Nueva Cedula es: %s",(pclient+i)->cedula);
					break;
				}
				case 3:{
					fflush(stdin);
            		cordxy(6,14);printf("Nuevo Direccion: ");
            		cordxy(6,15);fgets(change,40,stdin);
            		cordxy(6,16);strcpy((pclient+i)->direction,change);
            		cordxy(6,17);printf("Su Nuevo Nombre es: %s",(pclient+i)->direction);
					break;
				}
				case 4:{
					fflush(stdin);
            		cordxy(6,14);printf("Nuevo Telefono: ");
            		cordxy(6,15);fgets(change,20,stdin);
            		cordxy(6,16);strcpy((pclient+i)->tell,change);
            		cordxy(6,17);printf("Su Nuevo Nombre es: %s",(pclient+i)->tell);
					break;
				}
				default:{
					cordxy(6,14);printf("el campo digitado no existe. ");
					break;
				}
			}
		}
	}
}

void crear_product(){
	system("color 0a");
	cuadropantalla(24,80);
	cordxy(6,4);printf(" ingrese la cantidad de productos: ");
	cordxy(6,5);scanf("%d",&numproducts);
	int sumproducts=cantproducts+numproducts;
	for(i=cantproducts;i<=numproducts;i++){
		(pproduct+i)->id_product=i;
		system("color 0a");
	    cuadropantalla(24,80);
		cordxy(6,7);printf("P R O D U C T O S ");
		cordxy(6,8);printf("Id_Producto: %d",(pproduct+i)->id_product);
		fflush stdin;
		cordxy(6,9);printf("Nombre Producto:");
		cordxy(6,10);fgets((pproduct+i)->name,40,stdin);
		
		cordxy(6,11);printf("Precio unitario:");
		cordxy(6,12);scanf("%f",(&(pproduct+i)->price));
	    fflush stdin;
	    system("cls");
	}
	cantproducts=cantproducts+numproducts;
}

void ver_product(){
	system("color 0a");
	for(i=0;i<=cantproducts;i++){
	printf("\n_____________________________________________\n");
	printf("Id producto: %d \n",(pproduct+i)->id_product);
	printf("Nombre Producto: \n %s",(pproduct+i)->name);
	printf("Valor Unitario: \n %.2f",(pproduct+i)->price);
	}
}

void modific_product(){
	int id;
	float changed;
	int numbers;
	char change[30];
	cordxy(6,5);printf("ingrese el id_producto que desea modificar: ");
	cordxy(6,6);scanf("%d",&id);
	system("cls");
	for(i=1;i<=cantproducts;i++){
		if((pproduct+i)->id_product==id){
			cuadropantalla(24,80);
			cordxy(6,7);printf("1.Nombre: %s",(pproduct+i)->name);
			cordxy(6,8);printf("2.Valor Unitario: %f",(pproduct+i)->price);
            cordxy(6,11);printf("ingrese el numero del campo que desea modificar: ");
            cordxy(6,12);scanf("%d",&numbers);
            switch (numbers){
            	case 1:{
            		fflush(stdin);
            		cordxy(6,14);printf("Nuevo Nombre: ");
            		cordxy(6,15);fgets(change,30,stdin);
            		cordxy(6,16);strcpy((pproduct+i)->name,change);
            		cordxy(6,17);printf("Su Nuevo Nombre es: %s",(pproduct+i)->name);
					break;
				}
				case 2:{
					fflush(stdin);
            		cordxy(6,14);printf("Nuevo Valor: ");
            		cordxy(6,15);scanf("%f",changed);
            		
            		cordxy(6,17);printf("Su Nuevo Valor Unitario es: %f",(pproduct+i)->price=changed);
					break;
				}
			
				default:{
					cordxy(6,14);printf("el campo digitado no existe. ");
					break;
				}
			}
		}
	}
}
int main() {

	int opcion=1;
	while (opcion!=0){
	system("cls");
	system("color 0a");
	cuadropantalla(24,80);
	cordxy(6,8);printf("MENU DE FACTURACION: ");
	cordxy(6,10);printf("1. Clientes ");
	cordxy(6,11);printf("2. Productos ");
	cordxy(6,12);printf("3. Facturas ");
	cordxy(6,13);printf("4. mostrar las facturas ");
	cordxy(6,14);printf("5. mostrar los clientes ");
	cordxy(6,15);printf("6. mostrar las facturas del cliente ");
	cordxy(6,16);printf("7. mostrar los productos con la cantidad vendida de cada uno ");
	cordxy(6,17);printf("8. mostrar facturas pagadas y sin pagar");
	cordxy(6,18);printf("0. SALIR");
	cordxy(6,20);printf("Ingrese la opcion a realizar:");
	cordxy(36,20);scanf("%d",&opcion);
	switch(opcion){
	case 1:{
			system("cls");
			system("color 0a");
			cuadropantalla(24,80);
			int number;
				cordxy(6,5);printf(" CLIENTES : ");
				cordxy(6,7);printf(" 1. Crear cliente.  ");
				cordxy(6,8);printf(" 2. Listar Cliente. ");
			    cordxy(6,9);printf(" 3. Modificar Cliente. ");
			    cordxy(6,10);printf(" Seleccione uno de los numeros: ");
			    cordxy(6,11);scanf("%d",&number);
			    switch(number){
			    	case 1:{
			    		system("cls");
			    	    crear_client();
			    	    break;
					}
					case 2:{
						system("cls");
						ver_client();
						 system("pause");
						break;
					}
					case 3:{
						system("cls");
						system("color 0a");
			    		cuadropantalla(24,80);
					    modific_client();
						system("pause");
						break;
					}
					default :{
						system("cls");
						system("color 0a");
			    		cuadropantalla(24,80);
						cordxy(8,12);printf(" El caracter ingresado no coincide. ");
						break;
					}	
	         	}
	         	break;
	    }
	    case 2:{
	    	system("cls");
	    	system("color 0a");
	    	cuadropantalla(24,80);
	    	int numbers;
				cordxy(6,5);printf(" PRODUCTOS : ");
				cordxy(6,7);printf(" 1. Crear Producto.  ");
				cordxy(6,8);printf(" 2. Listar Producto. ");
			    cordxy(6,9);printf(" 3. Modificar Producto. ");
			    cordxy(6,10);printf(" Seleccione uno de los numeros: ");
			    cordxy(38,10);scanf("%d",&numbers);
			    switch(numbers){
			    	case 1:{
			    		system("cls");
			    	    crear_product();
			    	    system("pause");
			    	    break;
					}
					case 2:{
						system("cls");
						ver_product();
						system("pause");
						break;
					}
					case 3:{
						system("cls");
						system("color 0a");
			    		cuadropantalla(24,80);
					    modific_product();
						system("pause");
						break;
					}
					default :{
						system("cls");
						system("color 0a");
			    		cuadropantalla(24,80);
						cordxy(8,12);printf(" El caracter ingresado no coincide. ");
						break;
					}
				}
			break;
		}
		case 0:{
			system("cls");
			system("color 0a");          
			cuadropantalla(24,80);
			cordxy(8,12);printf(" GOD BYE \n");
			break;
		}
		default :{
			system("color 0a");
			cuadropantalla(24,80);
			cordxy(8,12);printf(" El caracter ingresado no coincide  \n");
			system("pause");
			break;
		}
	}
	}
    system("pause");
	return 0;
}


