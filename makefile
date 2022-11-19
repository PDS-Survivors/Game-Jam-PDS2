CC := g++
CFLAGS := -I include/ -Wall
BUILD := build/
SRC := src/
TARGET := main.out

NMSFG := -I include/namespaces/ -Wall
EFFFG := -I include/effects/ -Wall
ATTFG := -I include/attacks/ -Wall
ENTFG := -I include/entities/ -Wall

all: teste3

reader:
	$(CC) $(NMSFG) -o build/reader.o -c src/namespaces/reader.cpp

behavior: 
	$(CC) $(NMSFG) -o build/behavior.o -c src/namespaces/behavior.cpp

effect: reader
	$(CC) $(EFFFG) -o build/effect.o -c src/effects/effect.cpp

lifeeffect: 
	$(CC) $(EFFFG) -o build/lifeeffect.o -c src/effects/lifeeffect.cpp

damageeffect: 
	$(CC) $(EFFFG) -o build/damageeffect.o -c src/effects/damageeffect.cpp

defenseeffect: 
	$(CC) $(EFFFG) -o build/defenseeeffect.o -c src/effects/defenseeffect.cpp

attack: effect lifeeffect damageeffect defenseeffect
	$(CC) $(ATTFG) -o build/attack.o -c src/attacks/attack.cpp

defense: attack
	$(CC) $(ATTFG) -o build/defense.o -c src/attacks/defense.cpp

entity: defense
	$(CC) $(ENTFG) -o build/entity.o -c src/entities/entity.cpp

pc: entity
	$(CC) $(ENTFG) -o build/pc.o -c src/entities/pc.cpp

npc: pc
	$(CC) $(ENTFG) -o build/npc.o -c src/entities/npc.cpp

battle: npc behavior
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