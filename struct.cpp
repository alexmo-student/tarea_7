#include <iostream>
using namespace std;
const char *nombre_archivo ="archivo.dat";
struct estudiante{
	int codigo;
	char nombres[50];
	char apellidos[50];
	int telefono;
};
void leer();
void crear();
void actualizar();
void  Borrar();
main(){
	leer();
	crear();
	Borrar();
    actualizar();
	
	
	system("pause");
}
void leer(){
	system("cls");
		FILE* archivo = fopen(nombre_archivo,"rb");
		if (!archivo){
			archivo = fopen(nombre_archivo,"w+b");
			
		}
		
		estudiante Estudiante;
		int id=0;//indice o posicion dentro del archivo
		fread(&Estudiante,sizeof(estudiante),1,archivo);
		cout<<"_______________________________________"<<endl;
		cout<<"ID:"<<"|"<<"codigo"<<" |"<<"  Nombres  "<<"|"<<" Apellidos  "<<"|"<<"  Telefono  "<<"|"<<endl;
		cout<<"__________________________________________________"<<endl;
		do{
		cout<<id<<"  |"<<Estudiante.codigo<<"|  "<<Estudiante.nombres<<"  |  "<<Estudiante.apellidos<<"  |  "<<Estudiante.telefono<<"|"<<endl;
		    fread(&Estudiante,sizeof(estudiante),1,archivo);
			id+=1;
			
		}while(feof(archivo)==0);
		fclose(archivo);
		
}
void crear(){
	FILE* archivo = fopen(nombre_archivo,"a+b");
	char res;
	estudiante Estudiante;
	do{
		fflush(stdin);
		cout<<"Ingrese  Codigo: ";
		cin>>Estudiante.codigo;
		cin.ignore();
		cout<<"Ingrese Nombres: ";
		cin.getline(Estudiante.nombres,50);
				cout<<"Ingrese apellidos: ";
				
		cin.getline(Estudiante.apellidos,50);
				cout<<"Ingrese Telefonos: ";
		cin>>Estudiante.telefono;
		
		fwrite(&Estudiante,sizeof(estudiante),1,archivo);
		
		cout<<"Desea Ingresar Otro estudiante (s/n):";
		cin>>res;
		
	}while(res=='s'|| res=='S');	
	fclose(archivo);
	leer();
}
void actualizar(){
		FILE* archivo = fopen(nombre_archivo,"r+b");
	estudiante Estudiante;
	int id=0;
	cout<<"Ingrese el ID que desea Modificar: ";
	cin>>id;
	fseek(archivo,id * sizeof(estudiante),SEEK_SET);
	
		cout<<"Ingrese  Codigo: ";
		cin>>Estudiante.codigo;
		cin.ignore();
		cout<<"Ingrese Nombres: ";
		cin.getline(Estudiante.nombres,50);
				cout<<"Ingrese apellidos: ";
				
		cin.getline(Estudiante.apellidos,50);
				cout<<"Ingrese Telefonos: ";
		cin>>Estudiante.telefono;
		
		fwrite(&Estudiante,sizeof(estudiante),1,archivo);
		
	fclose(archivo);
	leer();
	

}
void  Borrar(){
	const char *nombre_archivo_temp ="archivo_temp.dat";
	FILE* archivo_temp = fopen(nombre_archivo_temp,"w+b");
	FILE* archivo = fopen(nombre_archivo,"rb");
	estudiante Estudiante;
	int id=0, id_n=0;
	cout<<"Ingrese el Id a eliminar:";
	cin>>id;
	while(fread(&Estudiante,sizeof(Estudiante),1,archivo)){
		if(id_n !=id){
			fwrite(&Estudiante,sizeof(estudiante),1,archivo_temp);
		}
		id_n++;
	}
	fclose(archivo);
	fclose(archivo_temp);
	    archivo_temp = fopen(nombre_archivo_temp,"rb");
		archivo = fopen(nombre_archivo,"wb");
        while(fread(&Estudiante,sizeof(estudiante),1,archivo_temp)){
        	fwrite(&Estudiante,sizeof(estudiante),1,archivo);
        	
		}
			fclose(archivo);
	fclose(archivo_temp);
	leer();
}
