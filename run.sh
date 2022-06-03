if [ -d "build" ]; then
    cd build
else
    mkdir build
    cd build
fi
cmake ..
make
cd ../src
./../build/LordWorld
