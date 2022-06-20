#include <iostream>
#include <locale.h>
#include "cabecalho.h"

using namespace std;

Aluno *Vetor_A;
Aluno *Vetor_A2;
int i=0;
int TAM;
	
void Menu();
int main(){
	setlocale(LC_ALL, "Portuguese");
	
	cout<<"***************************************************************"<<endl;
	cout<<"Bem-vindo ao gerenciador de notas e médias! Cadastre os dados e receba o resultado :)"<<endl;
	cout<<"Informe o número de alunos: "<<endl;
	cin>>TAM;
	Vetor_A=criando_aluno(TAM);
	cout<<"***************************************************************"<<endl;
	Menu();
}

void Menu(){
	char Opcao;
	int i=1;
	while(i != 0){
		cout<<"MENU:\n";
		cout<<"A - Inserir novos alunos;\n";
		cout<<"B - Buscar aluno;\n";
		cout<<"C - Calcular media final da turma;\n";
		cout<<"D - Listar todos os alunos;\n";
		cout<<"Outra Tecla - Sair\n";
		cout<<"Informe a opção que deseja realizar: ";
		cin>>Opcao;
		Opcao = toupper(Opcao);
		switch(Opcao){
			case 'A': 
				Vetor_A=adicionando_aluno(Vetor_A, &TAM);
				break;
			case 'B': 
				buscar_aluno(Vetor_A, TAM);
				break;
			case 'C': 
				calcula_medias(Vetor_A, TAM);
				break;
			case 'D':
				mostra_todos(Vetor_A, TAM);
				break;
			default: 
				cout<<"\nDeseja Realmente Sair? (S-SIM | N-NÃO): ";
				cin>>Opcao;
				Opcao=toupper(Opcao);
				if(Opcao == 'S'){
					cout<<"Execução encerrada!"<<endl;
					limpa_vetor(Vetor_A);
					exit(0);
				} else{
					Menu();
				}
				break;
		}
	}
}


