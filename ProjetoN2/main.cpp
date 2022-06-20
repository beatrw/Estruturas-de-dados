#include <iostream>
#include "cabe.h"

using namespace std;

int main(){
	setlocale(LC_ALL, "Portuguese");
	Lista *lista;
	Aluno dados, *P_dados;
	P_dados = &dados;
	int Aux=0, i=1;
	
	char Menu; 
	char menuInserir;
	char menuRemover;
	char menuBuscar;
	
	while (i != 0){
		cout<<"Informe o que deseja realizar.\nOp��es:"<<endl;
		cout<<"A - Criar uma lista;"<<endl;
		cout<<"B - Inserir novo aluno;"<<endl;
		cout<<"C - Remover aluno;"<<endl;
		cout<<"D - Buscar aluno;"<<endl;
		cout<<"E - Calcular m�dia total de todos os alunos cadastrados;"<<endl;
		cout<<"F - Imprimir a lista;"<<endl;
		cout<<"G - Limpar a lista;"<<endl;
		cout<<"Qualquer outra op��o fechar� a execu��o do Programa!"<<endl;
		cin>>Menu;
		//
		Menu = toupper(Menu); 
		switch (Menu){
			case 'A':
				lista = Cria_Lista();
				cout<<"Uma lista para cadastro de alunos foi criada."<<endl;
				break;
			case 'B':
				cout<<"PARA INSERIR NOVO ALUNO ESCOLHA: "<<endl;
				cout<<"A - Inserir novo aluno no in�cio da lista; "<<endl;
				cout<<"C - Inserir novo aluno no final da lista; "<<endl;
				cin>>menuInserir;
				menuInserir = toupper(menuInserir);
				switch (menuInserir){
					case 'A':
						cout<<"Informe o nome do aluno a ser inserido na lista: ";
						cin.ignore();
	 					cin.getline(dados.Nome, 50);
						cout<<"Informe a idade do aluno a ser inserido na lista: ";
						cin>>dados.Idade;
						cout<<"Informe matr�cula do aluno a ser inserido na lista: ";
						cin>>dados.Matricula;
						dados.N1 = 0;
						dados.N2 = 0;
						dados.Situacao = 0;
						Aux = insere_Inicio(lista, dados);
						if (Aux){
							cout<<"Aluno inserido na lista!"<<endl;
						} else{
							cout<<"Inser��o falhou!"<<endl;
						}
						break;
					case 'B':
						cout<<"Informe o nome do aluno a ser inserido na lista: ";
						cin.ignore();
	 					cin.getline(dados.Nome, 50);
						cout<<"Informe a idade do aluno a ser inserido na lista: ";
						cin>>dados.Idade;
						cout<<"Informe matr�cula do aluno a ser inserido na lista: ";
						cin>>dados.Matricula;
						dados.N1 = 0;
						dados.N2 = 0;
						dados.Situacao = 0;
						Aux = insere_Final(lista, dados);
						if (Aux){
							cout<<"Aluno inserido na lista!"<<endl;
						} else{
						cout<<"Inser��o falhou!"<<endl;
						}
						break; 
					default: 
						exit(0);
						break;
					}
				break;
			case 'C':
				cout<<"PARA REMOVER ALUNO ESCOLHA: "<<endl;
				cout<<"A - Remover aluno do in�cio da lista; "<<endl;
				cout<<"B - Remover aluno pela matr�cula;"<<endl;
				cout<<"C - Remover aluno do final da lista; "<<endl;
				cin>>menuRemover;
				menuRemover = toupper(menuRemover);
				switch (menuRemover){
				case 'A':
					Aux = remover_Inicio(lista);
					if (Aux){
						cout<<"Aluno removido da lista!"<<endl;
					} else{
						cout<<"Remo��o do aluno falhou!"<<endl;
					}
					break;
				case 'B':
					Aux = remove_Matricula(lista);
					if (Aux){
						cout<<"Aluno removido da lista!"<<endl;
					} else{
						cout<<"Remo��o do aluno falhou!"<<endl;
					}
					break;
				case 'C':
					Aux = remover_Final(lista);
					if (Aux){
						cout<<"Aluno removido da lista!"<<endl;
					} else{
						cout<<"Remo��o do aluno falhou!"<<endl;
					}
					break;
				default: 
					exit(0);
					break;
				}
				break;
			case 'D':
				cout<<"PARA BUSCAR ALUNO ESCOLHA: "<<endl;
				cout<<"A - Buscar aluno pela posi��o na Lista; "<<endl;
				cout<<"B - Buscar aluno matr�cula;"<<endl;
				cin>>menuBuscar;
				menuBuscar = toupper(menuBuscar);
				switch (menuBuscar){
					case 'A':
						buscar_Posicao(lista);
						break;
					case 'B':
						buscar_Matricula(lista);
						break;
					default: 
						exit(0);
						break;
				}
				break;
			case 'E':
				calcular_Media(lista);
				break;
			case 'F':
				imprimir_Lista(lista);
				break;
			case 'G':
				limpar_Lista(lista);
				cout<<"Lista apagada!"<<endl;
				break;
			default: 
				cout<<"Execu��o encerrada. Lista liberada da mem�ria!"<<endl;
				limpar_Lista(lista);
				exit(0);
				break;
		}
		cout<<endl<<endl;
	}
	return 0;
}

