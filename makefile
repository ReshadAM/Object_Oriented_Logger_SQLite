all: generator dumper

generator: generator.o log_message.o logger.o
    g++ generator.o log_message.o logger.o -o generator -lsqlite3

dumper: dumper.o log_message.o logger.o
    g++ dumper.o log_message.o logger.o -o dumper -lsqlite3

log_message.o: log_message.cpp
    g++ -c log_message.cpp

logger.o: logger.cpp
    g++ -c logger.cpp

clean:
    rm *.o generator dumper
