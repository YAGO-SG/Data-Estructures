#### Problema

Dados dois arquivos texto, um contendo registros de departamentos e outro contendo registros de funcionários, implemente a função join, que realiza a junção dos dois arquivos, produzindo como resultado um terceiro arquivo que contém registros de departamentos + funcionários. Um registro deve estar no arquivo resultante quando o valor do atributo cod\_dept do registro de departamento é igual ao valor do atributo cod\_dept do registro de funcionário. Assuma que os arquivos não estão ordenados. A função a ser implementada, além de funções para tratamento de entrada e saída, estão no arquivo join.c em anexo.

#### Exemplo 

##### Arquivo de Departamentos

Cada linha do arquivo de departamentos contém: 

- código do departamento
- sala do departamento
- nome do departamento 

```
1;101;RH;
2;201;TI;
4;102;Diretoria;
```

##### Arquivo de Funcionários

Cada linha do arquivo de funcionários contém: 

- código do funcionário
- código do departamento
- nome do funcionário 

```
1;1;Maria;
2;1;Carlos;
3;2;Ana;
4;3;Bia;
5;1;Joao;
```

##### Arquivo resultante do join: 

Note que no arquivo resultante do join, **o código de departamento aparece apenas uma vez**. Cada linha do arquivo contém: 

- código do departamento
- sala do departamento
- nome do departamento
- código do funcionário
- nome do funcionário

```
1;101;RH;1;Maria;
1;101;RH;2;Carlos;
1;101;RH;5;Joao;
2;201;TI;3;Ana;
```


Todos esses dados são separados por ponto e vírgula. 

#### Entrada 

A função recebe como parâmetro os nomes dos três arquivos a serem manipulados (nome dos dois arquivos de entrada e o nome do arquivo que deve ser gerado pela função). São fornecidos dois arquivos de entrada para testes de implementação (departamentos.txt e funcionarios.txt).

#### Saída

A saída é o conteúdo do arquivo resultante da junção, que já é tratada pelo código fornecido em anexo. 

#### Dicas Importantes:

- A entrada e a saída já são tratadas no arquivo fornecido para ler e imprimir os dados no formato esperado pela questão. Vocês devem APENAS implementar a função solicitada no problema
- Não use arquivos .h (coloque todas as definições de tipo no arquivo .c)
- Veja outras dicas em http://www.ic.uff.br/~vanessa/courses/runcodes.html

Para baixar os arquivos exemplo, faça o seguinte: Clique no arquivo. Na página que seu navegador web abre mostrando o conteúdo do arquivo, clique com o botão da direita em qualquer parte da página. Os próximos passos dependem do navegador que vc está usando.  

No Google Chrome: 
- escolha a opção Salvar Como. Ele salva o arquivo já no formato TXT, direitinho. 

No Safari 
- escolha a opção Salvar Página Como (escolha o formato do arquivo como sendo "Código Fonte da Página). 
