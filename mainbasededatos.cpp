//Este programa fue hecho por:
//Estefany Vanessa Cerritos Zelaya
//Carnet:CZ18006

//Librerias utilizadas

#include <iostream>
#include <cstdlib>
#include <winsock2.h>
#include <mysql.h>
#include <mysqld_error.h>

using namespace std;

//Funciones requeridas
void menu();
void limpiar();
int valid();

int main(int argc, char *argv[])
{
	//Variables
    int opcion;  //para las opciones del menu
    MYSQL *conn; //para las consultas
    MYSQL  mysql; //mysql
    MYSQL_RES *res;
    MYSQL_ROW row;
    mysql_init(&mysql);
    conn=mysql_real_connect(&mysql,"localhost","root","","tareaprograbasededatos",0,0,0);//para conectar con la base de datos
    
    do{
    	//Menu dentro del main 
    	menu();//funcion para el menu
    	cout<<"----------------"<<endl;
    	cout<<"Ingrese opcion: "<<endl;
    	cout<<"----------------"<<endl;
    	cin>>opcion; //ingresar opcion
    	
    	switch (opcion)//ciclo para las opciones del menu
    	{
    		case 1://ver los cliente
    		limpiar();
    		 if(conn==NULL)
             { 
			     cout<<mysql_error(&mysql)<<endl;//para mostrar el errpr
                 system("pause");
                 /// return 1;
		     }
		     
              mysql_query(conn,"select * from clientes");
              res=mysql_store_result(conn);
              
              while((row=mysql_fetch_row(res))!=NULL)//imprime la lista de cliente
             {
                cout<<row[0]<<"\t";
                cout<<row[1]<<"\t";
                cout<<row[2]<<"\t";
                cout<<row[3]<<endl;
             }
        break;
        
        
        case 2://ver los productos
    		limpiar();
    		 if(conn==NULL)
             { 
			     cout<<mysql_error(&mysql)<<endl;//para mostrar el errpr
                 system("pause");
                 /// return 1;
		     }
		     
              mysql_query(conn,"select * from productos");
              res=mysql_store_result(conn);
              
              while((row=mysql_fetch_row(res))!=NULL)//imprime la lista de productos
             {
                cout<<row[0]<<"\t";
                cout<<row[1]<<"\t";
                cout<<row[2]<<"\t";
                cout<<row[3]<<endl;
             }
        break;
        }
        
    }while(opcion!=3);
    
    
           // mysql_real_connect(obj,NULL,'root','','tareaprograbasededatos',3306,NULL,0);
            mysql_close(conn);
            cout<<"se conecto"<<endl;
           system("pause");
           return 0;
}

//---

void menu(){
	
	//Imprime el menu
	cout<< "Opciones" <<endl;
	cout<< "--------------------------" <<endl;
	cout<< "1.Lista de Clientes" <<endl;
	cout<< "2.Lista de Productos" <<endl;
	cout<< "3.Salir" <<endl;
	cout<< "--------------------------" <<endl;
}

void limpiar()
{
	system("cls");
}

int valid(int a){
	if(cin.fail()||a<=8)
	{
		cin.clear();
		cin.ignore();
		cout<< "Error"<<endl;
		system("pause>nul");
	}
	limpiar();
	
	return a;
}






