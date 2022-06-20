#include <iostream>
#include <stdlib.h>
#include "cabe.h"

using namespace std;

struct Elemento{
	Aluno Dados;
	Elemento *Proximo;
	Elemento *Anterior;
	Elemento *aux;
};

struct Lista{
	Elemento *Inicio;
	Elemento *Final;	
	int quantidade;

};

//---------Criando a lista-----------
 Lista* Cria_Lista(){
	Lista *lista = (Lista*) malloc(sizeof(Lista));
	if(lista != NULL){
		lista->Inicio = NULL;
		lista->Final = NULL;
	} else{
		cout<<"Erro na solicitação de criar a lista!";
	}
	return lista;
}


//---------INSERINDO novo aluno no INICIO da lista-----------
int insere_Inicio(Lista *lista, Aluno dados){
	if(lista == NULL){
	cout<<"Erro!";
	return -1;
	}
	Elemento *no = (Elemento*) malloc(sizeof(Elemento));
	if(no == NULL){
		cout<<"Erro na alocação do elemento!";
		return 0;
	}
	no->Dados = dados;
	no->Proximo = NULL;
	if(lista->Inicio == NULL){
		lista->Inicio = no;
		lista->Final = no;
	} else {
		no->Proximo = lista->Inicio;
		lista->Inicio->Anterior = no;		
	}
	lista->Inicio = no;
	lista->quantidade++;
	return 1;
}




//---------INSERINDO novo aluno no FINAL da lista-----------
int insere_Final(Lista *lista, Aluno dados){
	if(lista == NULL){
		cout<<"Erro!";
		return 0;
	} else{
		Elemento *no = (Elemento*) malloc(sizeof(Elemento));
		if(no == NULL){
			return 0;
		} 
		no->Dados = dados;
		no->Proximo = NULL;
		if(lista->Final == NULL){
			lista->Inicio = no;
		} else {
			no->Anterior = lista->Final;
			lista->Final->Proximo = no;
		}				
		lista->Final = no;				
		lista->quantidade++;
		return 1;
	}
}


//---------REMOVENDO aluno do Inicio da lista-----------
int remover_Inicio(Lista *lista){
	if(lista == NULL){
		cout<<"Erro!";
		return 0;
	} else {
		Elemento *no = lista->Inicio;
		//fila->Inicial = no->Proximo;
		if(lista->Inicio == NULL){
			lista->Final = NULL;
		} else {
		free(no);
		lista->Inicio = lista->Inicio->Proximo;}
		lista->quantidade--;
		return 1;

	}
}


//---------REMOVER aluno pela MATRICULA na lista-----------
int remove_Matricula(Lista *lista){
	if(lista == NULL){
	cout<<"Erro!";
	return 0;
	} else {
    	int matriculaInformada;
    	cout<<"Informe a matrícula do aluno que deseja remover:"<<endl;
		cin>>matriculaInformada;
		Elemento *no = lista->Inicio;
		while(no != NULL){
			if (matriculaInformada == lista->Inicio->Dados.Matricula){
				remover_Inicio(lista);
			} 
			if(matriculaInformada == lista->Final->Dados.Matricula){
				remover_Final(lista);
			}
			if(matriculaInformada == no->Dados.Matricula){
				no->Anterior->Proximo = no->Proximo;
        		free(no);
				lista->quantidade--;
        	}	
   		no = no->Proximo;
		}
		return 1;	
	}
}

//---------REMOVER aluno no FINAL na lista-----------
int remover_Final(Lista *lista){
	if(lista == NULL){
		cout<<"Erro!";
		return 0;
	} else {
		Elemento *no = lista->Final;
		no->Proximo = NULL;
		if(lista->Inicio == NULL){
			lista->Final = NULL;
		}
		free(no);
		lista->Final = lista->Final->Anterior;
		no = lista->Final;
		no->Proximo = NULL;
		lista->quantidade--;
		return 1;
	}	
}


//---------CONSULTAR pela POSIÇÃO do aluno na lista-----------
void buscar_Posicao(Lista *lista){
	system("cls");
	if(lista == NULL){
		cout<<"Erro!";
	} else {
		int posicaoInformada;
		int flag = 0;
		int posicao;
		int	nopcao;
		cout<<"Informe a posição do aluno que deseja buscar:"<<endl;
		cin>>posicaoInformada;
		Elemento *no = lista->Inicio;
		while (no != NULL){
			if(posicaoInformada == posicao+1){
				flag == 1;	
				cout<<"Dados do aluno de posição "<<posicao+1<<endl;
				cout<<"Nome: "<<no->Dados.Nome<<endl;
				cout<<"Matrícula: "<<no->Dados.Matricula<<endl;
				cout<<"Idade: "<<no->Dados.Idade<<endl;
				cout<<"Nota 1: "<<no->Dados.N1<<endl;
				cout<<"Nota 2: "<<no->Dados.N2<<endl;
				cout<<"Media: "<<no->Dados.Media<<endl;
				if (no->Dados.Situacao == 0){
					cout<<"Situação: CURSANDO"<<endl;
				}
		
				cout<<"--------------------------------------------------------\n";
				cout<<"Deseja alterar a N1 do aluno? (1-SIM | 2-NÃO)"<<endl;
				cin>>nopcao;
				if (nopcao == 1){
					cout<<"Atualize a N1 do aluno: ";
					cin>>no->Dados.N1;
					while(no->Dados.N1 <0 || no->Dados.N1 >10){
						cout<<"Nota inválida, tente novamente:";
						cin>>no->Dados.N1;
					}
					cout<<"N1 atualizada: "<<no->Dados.N1<<endl;
				} if (nopcao == 2){
					cout<<"N1 mantida!"<<endl;
				}
				cout<<"Deseja alterar a N2 do aluno? (1-SIM | 2-NÃO)"<<endl;
				cin>>nopcao;
				if (nopcao == 1){
					cout<<"Atualize a N2 do aluno: ";
					cin>>no->Dados.N2;
					while(no->Dados.N2 <0 || no->Dados.N2 >10){
						cout<<"Nota inválida, tente novamente:";
						cin>>no->Dados.N2;
					}
				cout<<"N2 atualizada: "<<no->Dados.N2<<endl;
				} if (nopcao == 2){
					cout<<"N2 mantida!"<<endl;
				}
				no->Dados.Media = no->Dados.N1*0.4+no->Dados.N2*0.6;
				cout<<"A média do aluno é: "<<no->Dados.Media<<endl;
				if(no->Dados.Media >= 6){
					no->Dados.Situacao = 1;
					cout<<"A situação do aluno é: APROVADO"<<endl;
				} else { 
					no->Dados.Situacao = 2;
					cout<<"A situação do aluno é: REPROVADO"<<endl;
				}
			} 
			no = no->Proximo;
			posicao++;
			}
			if (flag == 0 ){
        	cout<<"Não há aluno nesta posição!";
			}
		}
}

//---------CONSULTAR pela MATRICULA do aluno na lista-----------
void buscar_Matricula(Lista *lista){
	system("cls");
	if(lista == NULL){
		cout<<"Erro!";
	} else {
		int flag = 0;
		int matriculaInformada;
		int	nopcao;
		cout<<"Informe a matricula do aluno que deseja buscar:"<<endl;
		cin>>matriculaInformada;
		Elemento *no = lista->Inicio;
		while(no != NULL){
			if(matriculaInformada == no->Dados.Matricula){	
				flag == 1;
				cout<<"Dados do aluno de matrícula: "<<matriculaInformada<<endl;
				cout<<"Nome: "<<no->Dados.Nome<<endl;
				cout<<"Matrícula: "<<no->Dados.Matricula<<endl;
				cout<<"Idade: "<<no->Dados.Idade<<endl;
				cout<<"Nota 1: "<<no->Dados.N1<<endl;
				cout<<"Nota 2: "<<no->Dados.N2<<endl;
				cout<<"Media: "<<no->Dados.Media<<endl;
				if (no->Dados.Situacao == 0){
					cout<<"Situação: CURSANDO"<<endl;
				}
		
				cout<<"--------------------------------------------------------\n";
				cout<<"Deseja alterar a N1 do aluno? (1-SIM | 2-NÃO)"<<endl;
				cin>>nopcao;
				if (nopcao == 1){
					cout<<"Atualize a N1 do aluno: ";
					cin>>no->Dados.N1;
					while(no->Dados.N1 <0 || no->Dados.N1 >10){
						cout<<"Nota inválida, tente novamente:";
						cin>>no->Dados.N1;
					}
					cout<<"N1 atualizada: "<<no->Dados.N1<<endl;
				} if (nopcao == 2){
					cout<<"N1 mantida!"<<endl;
				}
				cout<<"Deseja alterar a N2 do aluno? (1-SIM | 2-NÃO)"<<endl;
				cin>>nopcao;
				if (nopcao == 1){
					cout<<"Atualize a N2 do aluno: ";
					cin>>no->Dados.N2;
					while(no->Dados.N2 <0 || no->Dados.N2 >10){
						cout<<"Nota inválida, tente novamente:";
						cin>>no->Dados.N2;
					}
				cout<<"N2 atualizada: "<<no->Dados.N2<<endl;
				} if (nopcao == 2){
					cout<<"N2 mantida!"<<endl;
				}
				no->Dados.Media = no->Dados.N1*0.4+no->Dados.N2*0.6;
				cout<<"A média do aluno é: "<<no->Dados.Media<<endl;
				if(no->Dados.Media >= 6){
					no->Dados.Situacao = 1;
					cout<<"A situação do aluno é: APROVADO"<<endl;
				} else { 
					no->Dados.Situacao = 2;
					cout<<"A situação do aluno é: REPROVADO"<<endl;
				}
			} 
			no = no->Proximo;
			}
			if (flag == 0 ){
        	cout<<"Não há aluno com esta matrícula!";
			}	
		}
}

//---------CALCULAR media final de todos os alunos-----------
void calcular_Media(Lista *lista){
	if(lista == NULL){
		cout<<"Erro!";
	} else {
		float soma;
		float media_geral;
		int cont;
		Elemento *no = lista->Inicio;
		while(no != NULL){
			soma = soma + no->Dados.Media;
			no = no->Proximo;
			cont++;
		}
		media_geral = soma/lista->quantidade;
		cout<<"Média geral de todos os alunos cadastrados: "<<media_geral;
	}
}



//---------IMPRIMIR a lista-----------
void imprimir_Lista(Lista *lista){
	system("cls");
	if(lista == NULL){
		cout<<"Erro!";
	} else {
		int cont = 1;
		Elemento *no = lista->Inicio;
		while(no != NULL){
			cout<<"Dados do aluno da posição: "<<cont<<" na lista:"<<endl;
			cout<<"Nome: "<<no->Dados.Nome<<endl;
			cout<<"Matrícula: "<<no->Dados.Matricula<<endl;
			cout<<"Idade: "<<no->Dados.Idade<<endl;
			cout<<"Nota 1: "<<no->Dados.N1<<endl;
			cout<<"Nota 2: "<<no->Dados.N2<<endl;
			cout<<"Media: "<<no->Dados.Media<<endl;
			if (no->Dados.Situacao == 0){
				cout<<"Situação: CURSANDO"<<endl;
			}
			if (no->Dados.Situacao == 1){
				cout<<"Situação: APROVADO"<<endl;
			} if (no->Dados.Situacao == 2){
				cout<<"Situação: REPROVADO"<<endl;
			}
			cout<<"--------------------------------------------------------\n";

			no = no->Proximo;
			cont++;
		}
	}
	
}

//---------LIMPAR a lista-----------
void limpar_Lista(Lista *lista){
	if(lista  == NULL){
		cout<<"ERRO!";
	}else {
		Elemento *no;
		while(lista->Inicio !=NULL){
			no = lista->Inicio;
			lista->Inicio = lista->Inicio->Proximo;
			free(no);
		}
		free(lista);
	}
}
