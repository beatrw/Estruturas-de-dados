/*Projeto da disciplina de Estrutura de Dados
-- Criar uma TAD que represente um sistema de notas com:
Cadastro, Menu e visualização dos dados.
-- Estudando os assuntos de TAD, struct, vetores, ponteiros e alocação dinâmica de memóriaa.
*/

 struct Aluno{
	char Nome[50];
	int Matricula;
	int Idade;
	float Media;
	float N1, N2;
	int Situacao; 
	
};
Aluno* criando_aluno(int TAM);
Aluno* adicionando_aluno(Aluno *Vetor_A2, int *TAM);
int	buscar_aluno(Aluno *Vetor_A, int TAM);
void calcula_medias(Aluno *Vetor_A, int TAM);
void mostra_todos(Aluno *Vetor_A, int TAM);
void limpa_vetor(Aluno *Vetor_A);


