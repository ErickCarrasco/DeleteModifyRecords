#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

vector<int> getByteSize(string);

bool RecordExtractor(string);

bool RecordVerify(string, string);

vector<string> getMetaData(string);

bool isNumber(string);

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
		/*
		readr.open("FileAlpha.txt");//Archivo Principal
		temp.open("TempAlpha.txt");//Archivo temp para guardar datos temporalmente
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
		*/
		readr.open("FileAlpha.txt");
		temp.open("TempAlpha.txt");//Archivo temp para guardar datos temporalmente
		string str;
		string keyVerify;
		cout<<"Ingrese el username del usuario a eliminar "<<endl;
		cin>>keyVerify;
		bool verifyKey;
		bool processcompleted;
		int processValidate=0;
		while(getline(readr, str, '|')){
			//cout<<str<<endl;
			verifyKey=RecordVerify(str, keyVerify);
			if (verifyKey==true){
				processValidate=1;
				cout<<"Datos encontrados.. "<<endl;
				cout<<str<<endl;
				cout<<"Desea eliminar el registro? [Y/n]"<<endl;
				char decision;
				cin>>decision;
				if (decision='Y'||decision=='y'){
					cout<<"Processing ... "<<endl;
					string strbuild;
					strbuild.append("*");
					strbuild.append(str);
					temp<<strbuild<<"|";
					cout<<endl;
					cout<<"Process Completed"<<endl;
					
				}else{
					cout<<"Record unchanged.. No changes were made to the file"<<endl;
				}
				if (processValidate==1){
					processcompleted=true;
				}
				
				//break;
			}else{
				temp<<str<<"|";
				//cout<<"Process could not be completed (File may be corrupted or record is nonexistent"<<endl;
			}

		}
		if (processcompleted==false){
			cout<<"Data not found. File remains unchanged "<<endl;
		}
		readr.close();
		temp.close();
		remove("FileAlpha.txt");
		rename("TempAlpha.txt","FileAlpha.txt");

	}

	//Selection 2 -> Modify Record
	if (selection == 2){
		/*
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
		*/
		readr.open("FileBeta.txt");
		temp.open("TempBeta.txt");//Archivo temp para guardar datos temporalmente
		string str;
		string keyVerify;

		//Metadata extraction
		vector<string> metadataInfo= getMetaData("FileBeta.txt");

		//Print Vector
		for (int i = 0; i < metadataInfo.size(); ++i)
		{
			/* code */
		}

		//cout<<"Ingrese el username del usuario a eliminar "<<endl;
		//cin>>keyVerify;
		bool verifyKey;
		bool processcompleted;
		int processValidate=0;

		readr.close();
		temp.close();
		remove("FileBeta.txt");
		rename("TempBeta.txt","FileBeta.txt");
	}

	//Selection 3 -> Show Data
	if (selection == 3){
		//readr.open("FileAlpha.txt");//Reading main file
		vector<int> ExtractedBytes;
		ExtractedBytes=getByteSize("FileAlpha.txt");
		readr.open("FileAlpha.txt");

		string extractedRecord;
		string str;
		while(getline(readr, str, '|')){
			cout<<str<<endl;
			bool rectify=RecordExtractor(str);
		}
		readr.close();
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

bool RecordVerify(string chain, string keyComparer){
	//string str;
	string delimiterD=",";
	string token;
	size_t pos = 0;
	bool found=false;
	while((pos = chain.find(delimiterD)) != string::npos){
		token = chain.substr(0,pos);//Function returns a substring of the object, starting at pos and lenght of npos
		//cout<<"Token "<<token<<endl;
		chain.erase(0, pos + delimiterD.length());
		if (token==keyComparer){
			found=true;
		}

	}
	//cout<<chain<<endl;
	return found;
}

vector<string> getMetaData(string filePath){
	ifstream readMD;//Opens file to extract the metadata
	readMD.open(filePath);
	string str;

	//Reading first line containing the MetaData
	bool addtoMetaDataVector;
	int vectorSize=0;

	//Vector containing data
	vector<string> retValVector;


	//Reading the file 
	while(getline(readMD, str, '|')){
		//Tokens to get the information
		string delimiterD=",";
		string token;
		size_t pos = 0;
		bool found=false;
		bool foundnum=true;
		while((pos = str.find(delimiterD)) != string::npos){
			token = str.substr(0,pos);//Function returns a substring of the object, starting at pos and lenght of npos
			cout<<"Token "<<token<<endl;
			bool verifyIfNum=isNumber(token);
			if (token=="campos"){
				addtoMetaDataVector=false;
			}else if (verifyIfNum==true){
				vectorSize=atoi(token.c_str());
				cout<<"Vector size: "<<vectorSize<<endl;

				//Set size to vector
				retValVector.resize(vectorSize);
				addtoMetaDataVector=false;
			}else{
				addtoMetaDataVector=true;
			}

			if (addtoMetaDataVector==true){
				retValVector.push_back(token);
			}

			str.erase(0, pos + delimiterD.length());

		}
		break;
	}
	readMD.close();
}

bool isNumber(string s) { 
    for (int i = 0; i < s.length(); i++){ 
        if (isdigit(s[i]) == false){ 
            return false; 
        }
  	}
    return true; 
} 

