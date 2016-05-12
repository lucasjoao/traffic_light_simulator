DICAS E COMENTÁRIOS DO PROF JEAN ACERCA DO TRABALHO DE SEMÁFORO

Pista:    Fila<Carro>
Semáforo: ListaCirc<Semaforo>
Relogio:  ListaOrdenada<Eventos>

Tempo discreto - não precisa contar segundo a segundo...
Um evento gera outros eventos...
Quando se inicializa o sistema cria pistas e etc...é possível em cada uma das pistas criar o primeiro carro...
Cada pista gera carros randomicamente a cada x segundos...
Cada pista tem tamanho e velocidade, por isso é possivel saber quanto tempo "x" depois carro vai chegar no semaforo....
Por isso dá para saber que no tempo "f(x)" ja tem um evento chamado "chegou" no semaforo...
Digamos que o carro chegou no semaforo no tempo 40, e o semaforo só se abre no 60... entao apaga-se o evento 
do 40, e cria-se evento 60. E passa a processar outros dados/pistas.
Após processar a criação do primeiro carro, processa a proxima criação de carro desta pista e a chegada... e passa 
para outra pista.
Criar classe Evento, e especializa ela em cada um dos eventos variados.
Técnicamente, ao chegarem 2 carros no tempo de espera do semaforo, passa-se os dois juntos(um em cima do outr), no mesmo tempo x, chegando ao mesmo tempo na outra pista(pista destino).
O principal problema da forma como encontra-se descrito o problema, gerará congestionamento, momentos de fluxo bloqueado. Se
não gerar isso está errado. Ele pedirá que forcemos tal situação. 
Como conectar uma pista em outra pista: Ao chegar no fim da pista como saber qual pista x carro tem q ir ?
Ter dentro de uma pista um vetor de pista pointer (Pista* Saidas[]), conectando assim uma pista na outra.
     |    |    |   |
_____|    |____|   |_______ Exemplo de pista...

----|   |------|   |-------
    |   |      |   |        

Como o sistema  é baseado em eventos, não interessa a velocidade, e sim o tempo.
Após a pista começa a rodar, não interessa mais o tamanho dela, e sim o TAMANHO LIVRE!
Ao adicionar carro, decrementa o tamanho livre da pista, se não houver espaço para o carro
a entrar não se chama o metodo adiciona carro. Ao tirar um carro da pista, também necessita-se
incrementar o espaço livre. Ou seja o adiciona na pista e o retira da pista, é  semelhando ao
adiciona e retira da fila, porém com verificação de espaço livre.
Elimina da pista, para tirar os carros do sumidouro, tirar da memoria.

Dica: Pensar bastante antes de começar a programar. Bem mais fácil do que sentar e começar a programar.
Trabalho em dupla, mas a apresentação é praticamente individual, perguntas individuais também, necessário
conhecer todo o código.
Semáforo marcado = Não é possível fazer ninguem cruzar.



