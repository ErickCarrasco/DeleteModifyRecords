#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <fstream>
#include <vector>

using namespace std;

vector<int> getByteSize(string);

bool RecordExtractor(string);

int main(){
	//Variables 
	ifstream readr;
	ofstream temp;
	ofstream save;
	int clave, Bpass;
	char nombre[20], nName[20];

	//Variables Records
	char delimiter='|';
	char fielddelimiter=',';
	string recordextract;
	save.open("FileAlpha.txt", ios::app);


	//Menu
	cout<<"--- Menu --- "<<endl;
	cout<<"1/ Delete "<<endl;
	cout<<"2/ Modify "<<endl;
	cout<<"3/ Show Data "<<endl;
	cout<<"4/ Exit "<<endl;
	int selection;
	cout<<"Enter your data: "<<endl;
	cin>>selection;

	//Selection 1 -> Delete Record
	if (selection == 1){
		readr.open("FileAlpha.txt");//Archivo Principal
		temp.open("TempAlpha.txt");//Archivo temp para guardar datos almacenados
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
		remove("FileAlpha.txt");
		rename("TempAlpha.txt","FileAlpha.txt");
		//break;
	}

	//Selection 2 -> Modify Record
	if (selection == 2){
		readr.open("FileAlpha.txt");//Archivo Principal
		temp.open("TempAlpha.txt");//Archivo temp para guardar datos a sobreescribir
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
		remove("FileAlpha.txt");
		rename("TempAlpha.txt", "FileAlpha.txt");
		
	}

	//Selection 3 -> Show Data
	if (selection == 3){
		//readr.open("FileAlpha.txt");//Reading main file
		vector<int> ExtractedBytes;
		ExtractedBytes=getByteSize("FileAlpha.txt");
		readr.open("FileAlpha.txt");
		//int i=0;

		/*
		while(!readr.eof()){
			int sizeB=ExtractedBytes[i];
			i++;
			cout<<"Size "<<sizeB<<endl;
			char extraction[sizeB];
			readr>>extraction;
			cout<<"Record "<<i<<" "<<extraction<<endl;
		}
		*/
		string extractedRecord;
		string str;
		while(getline(readr, str, '|')){
			cout<<str<<endl;
			bool rectify=RecordExtractor(str);
		}



	}

    return 0;
}

vector<int> getByteSize(string filename){
	vector<int> ByteData;
	ifstream Lectura;
	Lectura.open(filename);
	char letter;
	int counter=0;
	while(!Lectura.eof()){
		
		Lectura>>letter;
		//cout<<letter<<" letter"<<endl;
		if (letter!='|'){
			counter++;
			//cout<<counter<<" CONTADOR"<<endl;
		}
		if(letter=='|'){
			ByteData.push_back(counter);
			counter=0;
		}
	}
	return ByteData;
}

bool RecordExtractor(string chain){
	//string str;
	string delimiterD=",";
	string token;
	size_t pos = 0;
	while((pos = chain.find(delimiterD)) != string::npos){
		token = chain.substr(0,pos);//Function returns a substring of the object, starting at pos and lenght of npos
		cout<<"Token "<<token<<endl;
		chain.erase(0, pos + delimiterD.length());
	}
	cout<<chain<<endl;
	return true;
}

