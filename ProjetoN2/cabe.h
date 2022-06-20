/*
Lista din�mica de alunos
Inserir, remover, buscar, calcular m�dia
*/

struct Aluno{
	char Nome[50];
	int Matricula;
	int Idade;
	float Media;
	float N1, N2;
	int Situacao; 
};

struct Lista;

//Criar lista de alunos
Lista* Cria_Lista();

//Inserir no Inicio da Lista
int insere_Inicio(Lista *lista, Aluno dados);

//Inserir no Final da Lista
int insere_Final(Lista *lista, Aluno dados);

//Remover no Inicio da Lista
int remover_Inicio(Lista *lista);

//Remover Ordenado pela matr�cula na Lista
int remove_Matricula(Lista *lista);

//Remover no Final da Lista
int remover_Final(Lista *lista);

//Imprimir a lista
void imprimir_Lista(Lista *lista);

//Consultar pela posi��o
void buscar_Posicao(Lista *lista);

//Consultar pela matr�cula
void buscar_Matricula(Lista *lista);

//Limpar lista
void limpar_Lista(Lista *lista);

//Consultar m�dia final da turma
void calcular_Media(Lista *lista);





