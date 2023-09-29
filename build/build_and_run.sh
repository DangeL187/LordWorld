g++ ../src/BuffListLoader.cpp -o ../bin/BuffListLoader && ../bin/BuffListLoader
g++ ../src/main.cpp -o ../bin/LW -std=c++20 -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -static-libstdc++ -static-libgcc -lpthread -fpermissive && ../bin/LW
