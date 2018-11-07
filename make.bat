g++ -v -I. -c ouroboros_pc_interface.cpp -o ouroboros_pc_interface.o -Wfatal-errors
PAUSE
g++ -v -c SerialPort.cpp -o SerialPort.o -Wfatal-errors
windres icon.rc icon.o
g++ -v -o Ouroboros.exe icon.o SerialPort.o ouroboros_pc_interface.o
PAUSE
rm -v *.o