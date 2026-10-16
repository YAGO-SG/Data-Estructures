#### Problema

Dados dois arquivos texto contendo números dispostos de forma ordenada, implemente a função **merge**, que gera um arquivo equivalente ao merge dos dois arquivos, contendo todos os números presentes nos dois arquivos de entrada, mas sem repetições. A assinatura da função é **void merge(char *nomeArq1, char *nomeArq2, char *nomeArqMerge)**, onde *nomeArq1* e *nomeArq2* são os nomes dos arquivos de entrada, e *nomeArqMerge* é o nome do arquivo que deve ser gerado pela função com o merge dos dois arquivos de entrada. 

#### Entrada

Não há entrada a ser lida do teclado. Os nomes dos arquivos de entrada são fornecidos como parâmetro da função. Para correção pelo RunCodes, os arquivos a serem processados serão fornecidos por cada caso de teste. Para que você possa testar seu programa, forneço em anexo dois arquivos de exemplo (numeros1.txt e numeros2.txt).

#### Saída

A saída é o conteúdo do arquivo resultante do merge, que já é realizada na função main. Tudo que sua função *merge* precisa fazer é gravar o arquivo em disco. 

#### Exemplo

Caso sejam fornecidos como entrada os dois arquivos anexados a esse exercícios (numeros1.txt e numeros2.txt), a saída deve ser a seguinte: 

```
5
10
15
20
21
23
25
30
37
40
57

```

Note a linha em branco no final do arquivo. 

#### Dicas Importantes:

- A entrada e a saída já são tratadas no arquivo fornecido para ler e imprimir os dados no formato esperado pela questão. Vocês devem APENAS implementar a função solicitada no problema
- Não use arquivos .h (coloque todas as definições de tipo no arquivo .c)
- Veja outras dicas em http://www.ic.uff.br/~vanessa/courses/runcodes.html

Para baixar os arquivos exemplo, faça o seguinte: Clique no arquivo. Na página que seu navegador web abre mostrando o conteúdo do arquivo, clique com o botão da direita em qualquer parte da página. Os próximos passos dependem do navegador que vc está usando.

No Google Chrome:
- escolha a opção Salvar Como. Ele salva o arquivo já no formato TXT, direitinho.

No Safari
- escolha a opção Salvar Página Como (escolha o formato do arquivo como sendo "Código Fonte da Página).
