flags = -pedantic-errors -std=c++11
gameMoves.o: gameMoves.cpp gameMoves.h playerInfo.h gameStatus.h
	g++ $(flags) -c $<

destination.o: destination.cpp destination.h gameTexts.h
	g++ $(flags) -c $<

gameStatus.o: gameStatus.cpp gameStatus.h playerInfo.h gameTexts.h
	g++ $(flags) -c $<

gameTexts.o: gameTexts.cpp gameTexts.h
	g++ $(flags) -c $<

playerInfo.o: playerInfo.cpp playerInfo.h
	g++ $(flags) -c $<

main.o: main.cpp gameTexts.h gameMoves.h gameStatus.h playerInfo.h
	g++ $(flags) -c $<

game: main.o playerInfo.o gameTexts.o gameStatus.o destination.o gameMoves.o
	g++ $(flags) $^ -o $@

clean:
	rm -rf *.o game

tar:
	tar -czvf game.tgz *.cpp *.h

.PHONY: clean tar