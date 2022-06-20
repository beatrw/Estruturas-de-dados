#include <iostream>
#include <stdlib.h>
#include "cabecalho.h"

using namespace std;

//---------Cadastrando e mostrando primeiros dados-----------
Aluno* criando_aluno(int TAM){
	Aluno *Vetor_A, *A;
	Vetor_A = (Aluno*) malloc(TAM*sizeof(struct Aluno));
	//Vetor_A = (Aluno*) calloc(TAM,sizeof(struct Aluno));
		if (Vetor_A == NULL){
			cout<<"ACONTECEU ALGUM PROBLEMA. MEMORIA NÃO ALOCADA!";
			return 0;}
	A=Vetor_A;
	for(int i=0; i<TAM; i++) {
		cout<<"Informe o nome do aluno "<<i+1<<": "; 
	 	//cin.getline(Vetor_A->Nome, 50);
    	cin>>Vetor_A->Nome;
		cout<<"Informe a idade do aluno "<<i+1<<": ";
		cin>>Vetor_A->Idade;
		cout<<"Informe a matrícula do aluno "<<i+1<<": "; 
		cin>>Vetor_A->Matricula;
		cout<<"Informe a N1 do aluno "<<i+1<<": ";
		cin>>Vetor_A->N1;
	 		while(Vetor_A->N1 <0 || Vetor_A->N1 >10){
				cout<<"Nota inválida, tente novamente:";
				cout<<"\nInforme a N1 do aluno " <<i+1<<": ";
				cin>>Vetor_A->N1;}
		cout<<"Informe a N2 do aluno "<<i+1<<": "; 
		cin>>Vetor_A->N2;
			while(Vetor_A->N2 <0 || Vetor_A->N2 >10){
				cout<<"Nota inválida, tente novamente:";
				cout<<"\nInforme a N2 do aluno " <<i+1<<": ";
				cin>>Vetor_A->N2;}
		cout<<"--------------------------------------------------------\n";
		Vetor_A++;}
	return A;
}



//----------Cadastrando novos alunos - menu A -----------------
Aluno* adicionando_aluno(Aluno *Vetor_A2, int *TAM){
	system("cls");
	Aluno *A2;
	int TAM2;
	cout<<"Informe a quantidade de novos alunos: "<<endl;
	cin>>TAM2;
	TAM2 = *TAM+TAM2;
	A2 = (Aluno*) realloc(Vetor_A2, (TAM2)*sizeof(Aluno));
		if(A2 != NULL){
			Vetor_A2 = A2;
		} else{
			cout<<"ACONTECEU ALGUM PROBLEMA. MEMORIA NÃO ALOCADA!";
			return Vetor_A2;}	
	for(int i=0; i<*TAM; i++){
		Vetor_A2++;}
	for(int i=*TAM; i<TAM2; i++){
		cout<<"Informe o nome do aluno "<<i+1<<": "; 
		cin>>Vetor_A2->Nome;
		cout<<"Informe a idade do aluno "<<i+1<<": ";
		cin>>Vetor_A2->Idade;
		cout<<"Informe a matrícula do aluno "<<i+1<<": "; 
		cin>>Vetor_A2->Matricula;
		cout<<"Informe a N1 do aluno "<<i+1<<": ";
		cin>>Vetor_A2->N1;
	 	while(Vetor_A2->N1 <0 || Vetor_A2->N1 >10){
			cout<<"Nota inválida, tente novamente:";
			cout<<"\nInforme a N1 do aluno " <<i+1<<": ";
			cin>>Vetor_A2->N1;}		
		cout<<"Informe a N2 do aluno "<<i+1<<": "; 
		cin>>Vetor_A2->N2;
		while(Vetor_A2->N2 <0 || Vetor_A2->N2 >10){
			cout<<"Nota inválida, tente novamente:";
			cout<<"\nInforme a N2 do aluno " <<i+1<<": ";
			cin>>Vetor_A2->N2;}
		cout<<"--------------------------------------------------------\n";
	Vetor_A2++;}
	*TAM = TAM2;
	return A2;
}
	
	
	
//----------Buscando alunos - menu B -----------------
int	buscar_aluno(Aluno *Vetor_A, int TAM){
	system("cls");
	int posicao;
	cout<<"Informe a posição do aluno que deseja buscar: ";
	cin>>posicao;
	while(posicao>TAM || posicao<1){
		cout<<"Não existe aluno cadastrado nesta posição!";
		cout<<"\nInforme outra Posição entre (1-"<<TAM<<"): ";
		cin>>posicao;}
	for(int i=0; i<posicao-1; i++){
		Vetor_A++;}
	Vetor_A->Media = Vetor_A->N1*0.4+Vetor_A->N2*0.6;
	cout<<"\nDados do Aluno "<<posicao<<": \n";
	cout<<"Nome: "<<Vetor_A->Nome<<endl;
	cout<<"Matrícula: "<<Vetor_A->Matricula<<endl;
	cout<<"Idade: "<<Vetor_A->Idade<<endl;
	cout<<"Notas: "<<"N1: "<<Vetor_A->N1<<" N2: "<<Vetor_A->N2<<endl;
	cout<<"A média do aluno é: "<<Vetor_A->Media<<endl;
	if(Vetor_A->Media >= 6){
		Vetor_A->Situacao = 1;
		cout<<"A situação do aluno é: APROVADO"<<endl;
	} else { 
		Vetor_A->Situacao = 0;
		cout<<"A situação do aluno é: REPROVADO"<<endl;}
	cout<<"--------------------------------------------------------\n";
	cout<<endl<<endl;
}
	
	
	
//----------Calculando a média de todos os alunos - menu C -----------------
void calcula_medias(Aluno *Vetor_A, int TAM){
		system("cls");
		float soma = 0;
		float media_geral;
		for(int i=0; i<TAM; i++){
			soma = soma + Vetor_A->Media;
			Vetor_A++;}
		media_geral = soma/TAM;
		cout<<"A média geral dos alunos cadastrados é: "<<media_geral<<endl;
		cout<<endl<<endl;
}



//----------Mostrando todos os alunos - menu D -----------------
void mostra_todos(Aluno *Vetor_A, int TAM){
	system("cls");
	cout<<"\nLista de alunos cadastrados:\n";
	for(int i=0; i<TAM; i++){
		Vetor_A->Media = Vetor_A->N1*0.4+Vetor_A->N2*0.6;
		cout<<"\nDados do Aluno "<<i+1<<": \n";
		cout<<"Nome: "<<Vetor_A->Nome<<endl;
		cout<<"Matrícula: "<<Vetor_A->Matricula<<endl;
		cout<<"Idade: "<<Vetor_A->Idade<<endl;
		cout<<"Notas: "<<"N1: "<<Vetor_A->N1<<" N2: "<<Vetor_A->N2<<endl;
		cout<<"A média do aluno é: "<<Vetor_A->Media<<endl;
		if(Vetor_A->Media >= 6){
			Vetor_A->Situacao = 1;
			cout<<"A situação do aluno é: APROVADO"<<endl;
		} else { 
			Vetor_A->Situacao = 0;
			cout<<"A situação do aluno é: REPROVADO"<<endl;}
		cout<<"--------------------------------------------------------\n";
		Vetor_A++;
	}
	cout<<endl<<endl;
}


void limpa_vetor(Aluno *Vetor_A){
	free(Vetor_A);}
