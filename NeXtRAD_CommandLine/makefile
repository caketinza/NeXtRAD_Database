CC = g++
FLAGS = -O2 -Wall
INCLUDE = -I . -I/usr/include/mysql
LIBS = -lm -lmysqlclient
RM = rm -f 


all : net

net :  net.o SaveToTrial.o SaveToPulse.o SaveToNodes.o SaveToWeather.o SaveToTarget.o
	$(CC) -o net net.o SaveToTrial.o SaveToPulse.o SaveToNodes.o SaveToWeather.o SaveToTarget.o $(LIBS)

net.o : net.c
	$(CC) -c net.c $(FLAGS) $(INCLUDE)

SaveToTrial.o : SaveToTrial.c SaveToTrial.h
	$(CC) -c SaveToTrial.c $(FLAGS) $(INCLUDE)

SaveToPulse.o : SaveToPulse.c SaveToPulse.h
	$(CC) -c SaveToPulse.c $(FLAGS) $(INCLUDE)

SaveToNodes.o : SaveToNodes.c SaveToNodes.h
	$(CC) -c SaveToNodes.c $(FLAGS) $(INCLUDE)

SaveToWeather.o : SaveToWeather.c SaveToWeather.h
	$(CC) -c SaveToWeather.c $(FLAGS) $(INCLUDE)

SaveToTarget.o : SaveToTarget.c SaveToTarget.h
	$(CC) -c SaveToTarget.c $(FLAGS) $(INCLUDE)

clean:
	$(RM) *.o $(EXECUTABLES) core


# gcc -I/usr/include/mysql TestSQLConnection.c -lmysqlclient -o TestSQLConnection -Wall
