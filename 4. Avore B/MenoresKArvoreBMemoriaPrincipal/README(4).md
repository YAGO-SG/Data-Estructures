#### Problema 

Implemente a função TLista *menor_k(TNo *raiz, int k) que recebe um ponteiro para a raiz de uma árvore B armazenada em memória principal e um inteiro k, e retorna uma lista ordenada com as chaves da árvore que são menores do que k. O percurso na árvore deve ser feito de forma a ser o mais otimizado possível. Em outras palavras, só se deve examinar um nó caso ele tenha potencial de ter chaves menores que k. 

Sua função deve usar a função insere\_ordenado(TLista *l) fornecida no arquivo arvore\_b.c em anexo. Essa função faz a inserção de valores na lista de forma a mantê-la ordenada. Note que os casos de teste assumem que os valores da lista estão ordenados, por isso é importante que ela seja usada dentro da sua função.  

Use o arquivo fornecido nesse exercício, pois ele já contém o tratamento de entrada e saída. 

#### Entrada: 
- Inteiro que representa a ordem d da árvore B 
- Árvore B a ser analisada. As chaves dos nós da árvore devem ser informadas separadas por traço (sem espaço entre o valor da chave e o traço), na ordem em que devem ser inseridas na árvore (o esqueleto fornecido nesse exercício já realiza a inserção). 
- Inteiro k

#### Saída:
- Lista contendo as chaves menores do que k

## Exemplo1:

|Entrada|Saída|
|---|---| 
|2<BR/>10-20-11-15-14-23-45-60-32<BR/>15|10 11 14 |
|4<BR/>400-300-150-200<BR/>210|150  200|
|4<BR/>400-300-150-200<BR/>150| |

## Dicas Importantes:

- A entrada e a saída já são tratadas no arquivo fornecido para ler e imprimir os dados no formato esperado pela questão. Vocês devem APENAS implementar a função solicitada no problema
