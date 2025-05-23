#コンパイラ
CC = gcc

#出力ファイル名
TARGET = main.out

#依存オブジェクトファイル
OBJS = main.o calc.o

#最終的な実行ファイル
$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) -lm

#main.oを作る
main.o: main.c calc.h
	$(CC) -c main.c

#calc.oを作る
calc.o: calc.c calc.h
	$(CC) -c calc.c -lm

#クリーンアップのルール(make cleanで削除)
clean:
	rm -f $(TARGET) $(OBJS)
