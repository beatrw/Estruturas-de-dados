/*
Lista dinâmica de alunos
Inserir, remover, buscar, calcular média
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

//Remover Ordenado pela matrícula na Lista
int remove_Matricula(Lista *lista);

//Remover no Final da Lista
int remover_Final(Lista *lista);

//Imprimir a lista
void imprimir_Lista(Lista *lista);

//Consultar pela posição
void buscar_Posicao(Lista *lista);

//Consultar pela matrícula
void buscar_Matricula(Lista *lista);

//Limpar lista
void limpar_Lista(Lista *lista);

//Consultar média final da turma
void calcular_Media(Lista *lista);





