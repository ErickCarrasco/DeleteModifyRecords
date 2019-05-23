#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main(){
	//Variables 
	ifstream readr;
	ofstream temp;
	ofstream save;
	int clave, Bpass;
	char nombre[20], nName[20];

	save.open("File.txt", ios::app);


	//Menu
	cout<<"--- Menu --- "<<endl;
	cout<<"1/ Delete "<<endl;
	cout<<"2/ Modify "<<endl;
	cout<<"3/ Exit "<<endl;
	int selection;
	cout<<"Enter your data: "<<endl;
	cin>>selection;

	//Selection 1 -> Delete Record
	if (selection == 1){
		readr.open("File.txt");//Archivo Principal
		temp.open("Temp.txt");//Archivo temp para guardar datos almacenados
		readr>>nombre;
		bool found = false;
		cout<<"Enter a password for elimination: "<<endl;
		cin>>Bpass;//Pass para eliminar un registro del fichero

		while(!readr.eof()){//Verificar fin del archivo

			readr>>clave;

			if (clave==Bpass){//Comparacion de clave si existe dicha clave
				found = true;
				cout<<"Name -> "<<nombre<<endl;
				cout<<"Password ->"<<clave<<endl;
				cout<<endl;
				cout<<"Data eliminated.."<<endl;
			}else{
				temp<<nombre<<" "<<clave<<endl;
			}
			readr>>nombre;
		}
		if (found ==false){
			cout<<"Password not found "<<endl;
		}
		readr.close();
		temp.close();
		remove("File.txt");
		rename("Temp.txt","File.txt");
		//break;
	}

	//Selection 2 -> Modify Record
	if (selection == 2){
		readr.open("File.txt");//Archivo Principal
		temp.open("Temp.txt");//Archivo temp para guardar datos a sobreescribir
		readr>>nombre;
		bool found = false;
		cout<<"Enter a password for record modification: "<<endl;
		cin>>Bpass;
		while(!readr.eof()){
			readr>>clave;
			if (clave==Bpass){
				found = true;
				cout<<"Name-> "<<nombre<<endl;
				cout<<"Pass-> "<<clave<<endl;
				cout<<endl;
				cout<<"New name (can insert the same one) "<<endl;
				cin>>nName;
				temp<<nName<<" "<<clave<<endl;
				cout<<"Modification completed.."<<endl;
			}
			else{
				temp<<nombre<<" "<<clave<<endl;
			}
			readr>>nombre;
		}

		if (found==false){
			cout<<"Password not found on file.. "<<endl;
		}
		readr.close();
		temp.close();
		remove("File.txt");
		rename("Temp.txt", "File.txt");


		
	}




    return 0;
}
