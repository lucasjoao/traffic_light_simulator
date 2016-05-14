__to-do__
1. escrever código
2. fazer código funcionar bem e tirar memory leaks
3. documentar
4. apresentação

__definições__
Objetos
    - Pista (l):
        - fila de vetor
        - elemento: carros
        - atributos:
            - velocidade
            - uma lista das filas de saída lista de vetor
            - tamanho
            - espaço livre
            - randomizar para qual fila de saída o carro deve ir
    - Cruzamento (l):
        - lista circular simples
        - elemento: semáforos
        - atributos:
            - lista das filas lista de vetor que a compõem
            - lista de probabilidade _(???)_ que é associada com os elementos eferentes da lista das filas
    - Relogio do sistema (l):
        - lista ordenada (lista encadeada simples)
        - elemento: eventos
        - atributos:
            - _(??? precisa possuir uma lista dos semáforos e da pista ???)_
    - Carros (w):
        - atributos
            - tamanho = random(2 a 6) + 3
    - Semáforo (w):
        - atributos
            - status (aberto/fechado)
            - tempo para abrir
    - Evento (w):
        - atributos
            - tempo para ser executado
            - _(??? var que diz qual tipo de evento é ???)_
Entradas
    - tempo de abertura do sinal
    - tempo de execução da simulação
saída
    - quantidade de carros que entrou
    - quantidade de carros que saiu

__algumas observações__
Tempo discreto -> não precisa contar segundo a segundo.

Como o sistema  é baseado em eventos, não interessa a velocidade, e sim o tempo.
- Após a pista começa a rodar, não interessa mais o tamanho dela, e sim o TAMANHO LIVRE!
- Ao adicionar carro, decrementa o tamanho livre da pista, se não houver espaço para o carro a entrar não se chama o metodo adiciona carro. Ao tirar um carro da pista, também necessita-se
incrementar o espaço livre.

Elimina da pista, para tirar os carros do sumidouro, tirar da memoria.

Semáforo marcado, então não é possível fazer ninguem cruzar.

Semáforo abre no sentido horário, só há opção de verde e vermelho.

Haverá um momento em que todos os sinais estarão em vermelho.

Semáforo de quatro tempos

Carro não possui aceleração e trafega na velocidade da velocidade

Fila está ligada em um semáforo que a liga em outra fila








