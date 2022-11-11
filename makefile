CC := g++
CFLAGS := -I include/ -Wall
BUILD := build/
SRC := src/
TARGET := main.out

all: teste3

reader:
	$(CC) -I include/effects/ -Wall -o build/reader.o -c src/reader.cpp

effect: reader
	$(CC) -I include/effects/ -Wall -o build/effect.o -c src/effects/effect.cpp

lifeeffect: 
	$(CC) -I include/effects/ -Wall -o build/lifeeffect.o -c src/effects/lifeeffect.cpp

damageeffect: 
	$(CC) -I include/effects/ -Wall -o build/damageeffect.o -c src/effects/damageeffect.cpp

defenseeffect: 
	$(CC) -I include/effects/ -Wall -o build/defenseeeffect.o -c src/effects/defenseeffect.cpp

attack: effect lifeeffect damageeffect defenseeffect
	$(CC) $(CFLAGS) -o build/attack.o -c src/attack.cpp

entity: attack
	$(CC) $(CFLAGS) -o build/entity.o -c src/entity.cpp

pc: entity
	$(CC) $(CFLAGS) -o build/pc.o -c src/pc.cpp

npc: pc
	$(CC) $(CFLAGS) -o build/npc.o -c src/npc.cpp

battle: npc
	$(CC) $(CFLAGS) -o build/battle.o -c src/battle.cpp

teste1: npc 
	$(CC) $(CFLAGS) -o build/teste1.o build/*.o src/Testes_de_verificacao/Teste_de_verificacao_1.cpp 

teste2: npc
	$(CC) $(CFLAGS) -o build/teste2.o build/*.o src/Testes_de_verificacao/Teste_de_verificacao_2.cpp

teste3: battle
	$(CC) $(CFLAGS) -o build/teste3.o build/*.o src/Testes_de_verificacao/Teste_de_verificacao_3.cpp

run:
	./build/teste3.o

clean:
	$(RM) -r $(BUILD)/* $(TARGET)

reboot: clean all run