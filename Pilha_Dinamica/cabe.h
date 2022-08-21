/*
Pilha dinâmica

*/

struct Aluno{
	char Nome[50];
	int Matricula;
	int Idade;
	float Media;
	float N1, N2;
	int Situacao; 
};

struct Pilha;

//Criar pilha de alunos
Pilha* Cria_Pilha();

//Inserir 
int inserir(Pilha *pilha, Aluno dados);

//Remover
int remover(Pilha *pilha);

//Imprimir a pilha
void imprimir_Pilha(Pilha *pilha);

//Consultar topo
void consultar(Pilha *pilha);

//Tamanho da pilha
int tamanho(Pilha *pilha);

//Limpar pilha
void limpar_Pilha(Pilha *pilha);






