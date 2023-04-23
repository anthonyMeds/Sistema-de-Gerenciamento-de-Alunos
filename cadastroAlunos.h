
typedef struct cadastroAlunos
{
    int matricula;
    float notas[3];
    float media;
    int faltas;
} ALUNO;

void mensagembemvindo();
void selecionamenu(int *ptr_opcao, int * qtdAlunos);

void funcionalidades(int * ptr_opcao, ALUNO * alunos, int * qtdAlunos);

void cadastraraluno(ALUNO * alunos, int * posicao);

void coletaMatricula(ALUNO * alunos, int * posicao);
void coletaNotas(ALUNO* alunos, int * posicao);
void coletaFaltas(ALUNO* alunos, int * posicao);

int matriculaExiste(ALUNO* alunos, int* posicao);
int verificaMatricula(ALUNO*alunos, int *posicao, int matricula);

void alteraAluno(ALUNO* alunos, int* posicao);
int verificaPosicao(ALUNO* alunos, int * posicao, int matricula);

void buscarAluno(ALUNO* alunos, int* posicao);

void exibirDadosAluno(ALUNO* alunos);

void buscarAprovados(ALUNO* alunos, int * posicao);
void buscarReprovadosMedia(ALUNO* alunos, int * posicao);
void buscarReprovadosFalta(ALUNO* alunos, int * posicao);

void retornarMenu();

void buscarTodosAlunos(ALUNO* alunos, int * posicao);