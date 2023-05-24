Bomb.o: src/Bomb.cpp src/Bomb.h src/GameObject.h
Crate.o: src/Crate.cpp src/Crate.h src/GameObject.h
EmptyGO.o: src/EmptyGO.cpp src/EmptyGO.h src/GameObject.h
GameMaster.o: src/GameMaster.cpp src/GameMaster.h src/Map.h \
 src/GameObject.h src/Loader.h src/Menu.h src/UI.h
GameObject.o: src/GameObject.cpp src/GameObject.h
Loader.o: src/Loader.cpp src/Loader.h
Map.o: src/Map.cpp src/Map.h src/GameObject.h src/Crate.h src/Wall.h \
 src/EmptyGO.h
Menu.o: src/Menu.cpp src/Menu.h src/Map.h src/GameObject.h
TimeEvents.o: src/TimeEvents.cpp src/TimeEvents.h
UI.o: src/UI.cpp src/UI.h src/Map.h src/GameObject.h
Wall.o: src/Wall.cpp src/Wall.h src/GameObject.h
main.o: src/main.cpp src/GameMaster.h src/Map.h src/GameObject.h
