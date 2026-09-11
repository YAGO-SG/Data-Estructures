#### Problema 

Implemente uma função que recebe como parâmetro um grafo não orientado e retorna 1 caso ele seja bipartido, e 0 caso contrário. Um grafo é bipartido quando seus vértices podem ser pintados de duas cores, de forma que nenhum vértice tenha a mesma cor de um vértice adjacente, conforme ilustrado na figura abaixo. Assuma que o campo cor do vértice vem preenchido com -1, e sua função pode atualizá-lo usando os valores 0 e 1 para representar as cores diferentes.

![Exemplo de grafo bipartido](./image.png)

Use o arquivo fornecido nesse exercício, pois ele já contém o tratamento de entrada e saída. 

#### Entrada: 
Grafo a ser analisado, informado como segue (cada dado deve ser informado em uma nova linha): 
- número de vértices
- um inteiro que representa o id do vértice (x número de vértices)
- número de arestas
- id do vértice origem e id do vértice destino, separados por traço (x número de arestas)

Como o grafo é não orientado, ao informar a aresta 1-2, por exemplo, o código fornecido que trata as entradas e saídas insere no grafo a aresta 1-2 e a aresta 2-1. 

Exemplo de entrada (comentários sobre o significado estão informados entre parênteses no exemplo abaixo): 

```
3 (número de vértices)
1 (primeiro vértice)
2
3
3 (número de arestas) 
1-2 (primeira aresta)
1-3
2-3
```

#### Saída:
- 1, caso o grafo seja bipartido, 0 caso contrário.  

#### Exemplo 1:
##### Entrada
```
3 
1 
2
3
3 
1-2 
1-3
2-3
```

##### Saída
```
0
```

#### Exemplo 2

##### Entrada
```
5
1
2
3
4
5
3
1-2
1-3
2-4
```

##### Saída
```
1
```

#### Dicas Importantes:

- A entrada e a saída já são tratadas no arquivo fornecido para ler e imprimir os dados no formato esperado pela questão. Vocês devem APENAS implementar a função solicitada no problema
