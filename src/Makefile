all: Warship.o ShipManager.o PlayingField.o FieldView.o Bombing.o DoubleDamage.o Scaner.o AbilityManager.o Exception.o GameOperation.o main.o
	g++ Warship.o ShipManager.o PlayingField.o FieldView.o Bombing.o DoubleDamage.o Scaner.o AbilityManager.o Exception.o GameOperation.o main.o -o war

Warship.o: Warship.cpp Warship.h
	g++ -c Warship.cpp

PlayingField.o: PlayingField.cpp PlayingField.h Warship.h
	g++ -c PlayingField.cpp

ShipManager.o: ShipManager.cpp ShipManager.h Warship.h
	g++ -c ShipManager.cpp

GameOperation.o: GameOperation.cpp GameOperation.h ShipManager.h PlayingField.h FieldView.h AbilityManager.h Exception.h
	g++ -c GameOperation.cpp

main.o: main.cpp GameOperation.h
	g++ -c main.cpp

FieldView.o: FieldView.cpp FieldView.h
	g++ -c FieldView.cpp

AbilityManager.o: AbilityManager.cpp AbilityManager.h Ability.h Bombing.h DoubleDamage.h Scaner.h Exception.h
	g++ -c AbilityManager.cpp

Bombing.o: Bombing.cpp Bombing.h Ability.h
	g++ -c Bombing.cpp

DoubleDamage.o: DoubleDamage.cpp DoubleDamage.h Ability.h
	g++ -c DoubleDamage.cpp

Scaner.o: Scaner.cpp Scaner.h Ability.h
	g++ -c Scaner.cpp

Exception.o: Exception.cpp Exception.h
	g++ -c Exception.cpp
clean:
	rm *.o