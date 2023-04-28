# Sistema-de-Gerenciamento-de-Alunos
>Projeto da disciplina de estrutura de dados para exercitar modularização, structs e ponteiros. 

O projeto é um sistema de cadastro de alunos que permite ao usuário realizar diversas operações, como cadastrar novos alunos, alterar dados, buscar alunos, listar alunos aprovados e reprovados por média e por falta, listar a turma e sair do programa.

O sistema também possui validações para garantir a integridade dos dados inseridos pelo usuário, como por exemplo, verificar se a opção selecionada é válida e se a capacidade da turma já foi atingida antes de permitir um novo cadastro.



Funcionalidades:
O sistema deve ter as seguintes funcionalidades:

 – Menu de opções
- o menu imprime mensagens com opções das funcionalidades descritas abaixo e o usuário 
selecionará o índice da opção desejada;
- o menu será apresentado/mostrado sempre que o usuário finalizar uma funcionalidade;
- o sistema terá final quando o usuário selecionar a opção de “Sair”;
- opções inválidas devem gerar um alerta de erro;

1 - Cadastrar novo aluno. 
- cada aluno deve possuir uma matrícula única;
- um aluno só pode ser cadastrado em um espaço vazio do vetor;
- alertas de erro devem ser gerados (exemplos: número de alunos maior que
 o tamanho do vetor, quantidade de faltas maior que o número de aulas, matrículas iguais);

2 –  Alterar dados de alunos.
- a matrícula deve ser informada;
- alertas de erro devem ser gerados (exemplos: matrícula não encontrada, vetor vazio);

3 - Buscar aluno.
- Buscar dados de um aluno de acordo com a matrícula.

5 – Listar alunos aprovados (média igual ou superior a 6,0 e frequência a partir de 75%)

6 – Listar alunos reprovados por média;

7 – Listar alunos reprovados por faltas (frequência abaixo de 60%);
