## Problema 

Implemente a função int maior(TNo *raiz) que recebe um ponteiro para a raiz de uma árvore B armazenada em memória principal e retorna a maior chave que está armazenada na árvore. O percurso na árvore deve ser feito de forma a ser o mais otimizado possível. Para que seja possível verificar quais nós foram examinados, sua função deve chamar a função imprime\_no(TNo *a), fornecida no arquivo arvore\_b.c em anexo, para cada nó examinado, na ordem em que eles forem examinados. 

Use o arquivo fornecido nesse exercício, pois ele já contém o tratamento de entrada e saída. 

#### Entrada:
- Inteiro que representa a ordem d da árvore B
- Árvore B a ser analisada. As chaves dos nós da árvore devem ser informadas separadas por traço (sem espaço entre o valor da chave e o traço), na ordem em que devem ser inseridas na árvore (o esqueleto fornecido nesse exercício já realiza a inserção).

#### Saída:
- A linha "Nos examinados:", seguida das chaves de cada nó examinado (uma linha por nó, impressas pela função imprime\_no)
- A linha "Maior chave: " seguida da maior chave da árvore

## Exemplo:

|Entrada|Saída|
|---|---|
|2<BR/>10-20-11-15-14-23-45-60-32|Nos examinados:<BR/>   14   23<BR/>   32   45   60<BR/>Maior chave: 60|
|4<BR/>400-300-150-200|Nos examinados:<BR/>  150  200  300  400<BR/>Maior chave: 400|
|1<BR/>50-30-70-20-40-60-80-10-90-100|Nos examinados:<BR/>   50<BR/>   70   90<BR/>  100<BR/>Maior chave: 100|

## Dicas Importantes:

- A entrada e a saída já são tratadas no arquivo fornecido para ler e imprimir os dados no formato esperado pela questão. Vocês devem APENAS implementar a função solicitada no problema
- A função imprime\_no imprime cada chave ocupando 5 posições, alinhada à direita, por isso as chaves aparecem precedidas de espaços na saída

