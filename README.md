# Escape from UFMG 
Este é um jogo de RPG em que os jogadores, assumindo um papel de especialista de anomalias, devem passar por vários prédios da
UFMG e vencer uma sequência de batalhas em cada um deles, formando-se, ao final, caso sejam vitoriosos, ou jubilando, caso percam.

## :mage_woman: Personagens
Os jogadores podem escolher com qual personagem desejam jogar entre as opções: mago, mestre de armas e druída, 
que diferem em atributos e ataques. E os adversários, bosses NPCs em cada prédio, são seres históricos ou mitológicos relacionados ao prédio em que vivem e com ataques característicos. Os atributos e ataques do jogador também podem ser personalizados no decorrer do jogo, a depender das escolhas do jogador.

## :gear: Funcionamento
O programa está organizado de forma que uma partida. A partida contém uma pilha de prédios e em cada prédio há uma pilha de batalhas, que funcionam com o sistema de turnos. 
O jogador é considerado vencedor caso ele complete todos os predios, zere a pilha de prédios, para completar cada predio é nescesario que o jogador zere a sua respectiva pilha de batalhas, vencendo todas elas.
O jogador perde o joga caso morra três vezes, ou seja, zere o número de vidas sem completar o jogo.

## :clipboard: Organização
Para entender mais sobre a organização do programa você pode conferir o diagrama de classes, a documentção e o user stories, que estão disponibilizados abaixo:
* [Diagrama de Classe EFU](https://lucid.app/lucidchart/b54e3f5d-465f-4ce0-92ee-862de4a45c31/edit?invitationId=inv_17022fcf-c75d-48a3-ae5c-8ae11b7aefec&page=HWEp-vi-RSFO#)
* Documentação com Doxygen EFU (abrir o arquivo ./Game-Jam-PDS2/html/index.html)
* [User Stories EFU](https://docs.google.com/document/d/1ZR6FHnB6NyvXxb8IlHSf6qMpoL0bJax4UTGQYGjeI2o/edit?usp=sharing)

## :shipit: Setup
Para executar o jogo no terminal, clone esse repositório em sua máquina. Abra este no Visual Studio (ou outro ambiente de programação) e, após vericar que está no diretório correto, digite os comandos abaixo:
```
make
make start
```
Agora, para executar a interface do jogo faça, é necessário instalar a biblioteca gráfica raylib, como é ensinado no link a seguir
https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux#build-raylib-using-cmake
Uma vez feito, digite os comandos:
```
make gui
./a.out
```

## :brain: Colaboradores
* Beatriz Siqueira Campagnaro;
* Cássio Antônio Magalhães de Souza Almeida;
* Enzo Vídero Pinheiro Bahia;
* Leonardo Antônio Gomes da Silva;
* Pedro Silveira Polesca Boseja;
* Talita Félix Lúcio.
