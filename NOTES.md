__to-do__
- o que diabos é trabalhoI?
1. Criar esqueleto de todo código
2. escrever código
3. fazer código funcionar e tirar memory leaks
4. documentar
5. apresentação

__definições__
Objetos
    - Pista:
        - fila de vetor
        - elemento: carros
        - atributos:
            - velocidade
            - tamanho
            - uma lista das filas de saída _(??? lista de vetor ???)_
            - espaço
            - randomizar para qual fila de saída o carro deve ir
    - Semáforo:
        - lista circular simples
        - elemento: semáforos
        - atributos:
            - lista das filas _(??? lista de vetor ???)_ que a compõem
            - lista de probabilidade _(???)_ que é associada com os elementos eferentes da lista das filas
    - Relogio do sistema
        - lista ordenada _(??? duplamente encadeada ou a simples ???)_
        - elemento: momento (hora) de ocorrência do evento
        - atributos:
            - lista _(??? lista de vetor ???)_ dos eventos
            - ___(??? precisa possuir uma lista dos semáforos e da pista ???)__
    - Carros:
        - tamanho = random(2 a 6) + 3
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








