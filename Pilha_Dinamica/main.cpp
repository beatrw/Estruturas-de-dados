#include <iostream>
#include "cabe.h"

using namespace std;

int main(){
	setlocale(LC_ALL, "Portuguese");
	Pilha *pilha;
	Aluno dados, *P_dados;
	P_dados = &dados;
	int Aux=0, i=1;
	
	char Menu; 
	
	while (i != 0){
		cout<<"Informe o que deseja realizar.\nOpções:"<<endl;
		cout<<"A - Criar uma pilha;"<<endl;
		cout<<"B - Inserir novo aluno;"<<endl;
		cout<<"C - Remover aluno;"<<endl;
		cout<<"D - Consultar aluno;"<<endl;
		cout<<"E - Consultar o tamanho da pilha;"<<endl;
		cout<<"F - Imprimir a pilha;"<<endl;
		cout<<"G - Limpar a pilha;"<<endl;
		cout<<"Qualquer outra opção fechará a execução do Programa!"<<endl;
		cin>>Menu;
		//
		Menu = toupper(Menu); 
		switch (Menu){
			case 'A':
				pilha = Cria_Pilha();
				cout<<"Uma pilha para cadastro de alunos foi criada."<<endl;
				break;
			case 'B':
				cout<<"Informe o nome do aluno a ser inserido na pilha: ";
				cin.ignore();
	 			cin.getline(dados.Nome, 50);
				cout<<"Informe a idade do aluno a ser inserido na pilha: ";
				cin>>dados.Idade;
				cout<<"Informe matrícula do aluno a ser inserido na pilha: ";
				cin>>dados.Matricula;
				cout<<"Informe a N1 do aluno a ser inserido na pilha: ";
				cin>>dados.N1;
				cout<<"Informe a N2 do aluno a ser inserido na pilha: ";
				cin>>dados.N2;
				dados.Situacao = 0;
				Aux = inserir(pilha, dados);
				if (Aux){
					cout<<"Aluno inserido na pilha!"<<endl;
				} else{
				cout<<"Inserção falhou!"<<endl;
				}
				break;
			case 'C':
				Aux = remover(pilha);
				if (Aux){
					cout<<"Aluno removido da pilha!"<<endl;
				} else{
					cout<<"Remoção do aluno falhou!"<<endl;
				}
				break;
			case 'D':
				consultar(pilha);
				break;
			case 'E':
				tamanho(pilha);
				break;
			case 'F':
				imprimir_Pilha(pilha);
				break;
			case 'G':
				limpar_Pilha(pilha);
				cout<<"Pilha apagada!"<<endl;
				break;
			default: 
				cout<<"Execução encerrada. Pilha liberada da memória!"<<endl;
				limpar_Pilha(pilha);
				exit(0);
				break;
		}
		cout<<endl<<endl;
	}
	return 0;
}

