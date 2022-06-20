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

struct Pilha{
	Elemento *Topo;
	Elemento *Inicio;	
	int quantidade;

};

//---------Criando a pilha-----------
 Pilha* Cria_Pilha(){
	Pilha *pilha = (Pilha*) malloc(sizeof(Pilha));
	if(pilha != NULL){
		pilha->Topo = NULL;
		pilha->Inicio = NULL;
	} else{
		cout<<"Erro na solicitação de criar a pilha!";
	}
	return pilha;
}



//---------INSERINDO -----------
int inserir(Pilha *pilha, Aluno dados){
	if(pilha == NULL){
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
	if(pilha->Topo == NULL){
		pilha->Topo = no;
		pilha->Inicio = no;
	} else {
		no->Proximo = pilha->Topo;
		pilha->Topo->Anterior = no;		
	}
	pilha->Topo = no;
	pilha->quantidade++;
	return 1;
}




//---------REMOVER-----------
int remover(Pilha *pilha){
	if(pilha == NULL){
		cout<<"Erro!";
		return 0;
	} else {
		Elemento *no = pilha->Topo;
		if(pilha->Topo == NULL){
			pilha->Inicio = NULL;
		} else {
		free(no);
		pilha->Topo = pilha->Topo->Proximo;}
		pilha->quantidade--;
		return 1;

	}
}


//---------CONSULTAR-----------
void consultar(Pilha *pilha){
	system("cls");
	if(pilha == NULL){
		cout<<"Erro!";
	} else {
			int nopcao = 0;
			cout<<"Dados do aluno do topo: "<<endl;
			cout<<"Nome: "<<pilha->Topo->Dados.Nome<<endl; 
			cout<<"Matrícula: "<<pilha->Topo->Dados.Matricula<<endl;
			cout<<"Idade: "<<pilha->Topo->Dados.Idade<<endl;
			cout<<"Nota 1: "<<pilha->Topo->Dados.N1<<endl;
			cout<<"Nota 2: "<<pilha->Topo->Dados.N2<<endl;
			pilha->Topo->Dados.Media = pilha->Topo->Dados.N1*0.4+pilha->Topo->Dados.N2*0.6;
			cout<<"Media: "<<pilha->Topo->Dados.Media<<endl;
			if(	pilha->Topo->Dados.Media >= 6){
				pilha->Topo->Dados.Situacao = 1;
				cout<<"A situação do aluno é: APROVADO"<<endl;
			} else { 
				pilha->Topo->Dados.Situacao = 2;
				cout<<"A situação do aluno é: REPROVADO"<<endl;}
		
			cout<<"--------------------------------------------------------\n";
			cout<<"Deseja alterar a N1 do aluno? (1-SIM | 2-NÃO)"<<endl;
			cin>>nopcao;
			if (nopcao == 1){
				cout<<"Atualize a N1 do aluno: ";
				cin>>pilha->Topo->Dados.N1;
				while(pilha->Topo->Dados.N1 <0 || pilha->Topo->Dados.N1 >10){
					cout<<"Nota inválida, tente novamente:";
					cin>>pilha->Topo->Dados.N1;
				}
				cout<<"N1 atualizada: "<<pilha->Topo->Dados.N1<<endl;
			} if (nopcao == 2){
				cout<<"N1 mantida!"<<endl;
			}
			cout<<"Deseja alterar a N2 do aluno? (1-SIM | 2-NÃO)"<<endl;
			cin>>nopcao;
			if (nopcao == 1){
				cout<<"Atualize a N2 do aluno: ";
				cin>>pilha->Topo->Dados.N2;
				while(pilha->Topo->Dados.N2 <0 || pilha->Topo->Dados.N2 >10){
					cout<<"Nota inválida, tente novamente:";
					cin>>pilha->Topo->Dados.N2;
				}
				cout<<"N2 atualizada: "<<pilha->Topo->Dados.N2<<endl;
			} if (nopcao == 2){
				cout<<"N2 mantida!"<<endl;
			}
			pilha->Topo->Dados.Media = pilha->Topo->Dados.N1*0.4+pilha->Topo->Dados.N2*0.6;
			cout<<"A média do aluno é: "<<pilha->Topo->Dados.Media<<endl;
			if(	pilha->Topo->Dados.Media >= 6){
				pilha->Topo->Dados.Situacao = 1;
				cout<<"A situação do aluno é: APROVADO"<<endl;
			} else { 
				pilha->Topo->Dados.Situacao = 2;
				cout<<"A situação do aluno é: REPROVADO"<<endl;
			}
			
		}
}

//---------IMPRIMIR a pilha-----------
void imprimir_Pilha(Pilha *pilha){
	system("cls");
	if(pilha == NULL){
		cout<<"Erro!";
	} else {
		int cont = 1;
		Elemento *no = pilha->Topo;
		while(no != NULL){
			no->Dados.Media = no->Dados.N1*0.4+no->Dados.N2*0.6;
			cout<<"Dados do aluno da posição "<<cont<<" na pilha:"<<endl;
			cout<<"Nome: "<<no->Dados.Nome<<endl;
			cout<<"Matrícula: "<<no->Dados.Matricula<<endl;
			cout<<"Idade: "<<no->Dados.Idade<<endl;
			cout<<"Nota 1: "<<no->Dados.N1<<endl;
			cout<<"Nota 2: "<<no->Dados.N2<<endl;
			cout<<"Media: "<<no->Dados.Media<<endl;
			if(no->Dados.Media >= 6){
				no->Dados.Situacao = 1;
				cout<<"A situação do aluno é: APROVADO"<<endl;
			} else { 
				no->Dados.Situacao = 2;
				cout<<"A situação do aluno é: REPROVADO"<<endl;
			}
			cout<<"--------------------------------------------------------\n";

			no = no->Proximo;
			cont++;
		}
	}
	
}

int tamanho(Pilha *pilha){
	if(pilha  == NULL){
		cout<<"ERRO!";
	}else {
		cout<<"A pilha tem tamanho: "<<pilha->quantidade<<endl;
		return 1;
	}
}

//---------LIMPAR a pilha-----------
void limpar_Pilha(Pilha *pilha){
	if(pilha  == NULL){
		cout<<"ERRO!";
	}else {
		Elemento *no;
		while(pilha->Topo !=NULL){
			no = pilha->Topo;
			pilha->Topo = pilha->Topo->Proximo;
			free(no);
		}
		free(pilha);
	}
}
