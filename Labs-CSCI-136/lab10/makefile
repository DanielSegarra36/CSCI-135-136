executableName = lab10

all: yass

yass: main.o prompt.o drawPixel.o rectangle.o trapezoid.o lowerTriangle.o circle.o
	g++	-o	$(executableName)		main.o		prompt.o	drawPixel.o	rectangle.o	trapezoid.o	lowerTriangle.o		circle.o

main.o: main.cpp
	g++ -c main.cpp

prompt.o: prompt.cpp
	g++ -c prompt.cpp

drawPixel.o: drawPixel.cpp
	g++ -c drawPixel.cpp

rectangle.o: rectangle.cpp
	g++ -c rectangle.cpp

trapezoid.o: trapezoid.cpp
	g++ -c trapezoid.cpp

lowerTriangle.o: lowerTriangle.cpp
	g++ -c lowerTriangle.cpp

circle.o: circle.cpp
	g++ -c circle.cpp

clean:
	$(RM) *.o *~ $(executableName)

#rm yass

# The following was taken from terminal to copy and paste file names
#g++ -o prompt.o -c prompt.cpp
#g++ -o main.o -c main.cpp
#g++ -o drawPixel.o -c drawPixel.cpp
#g++ -o circle.o -c circle.cpp
#g++ -o trapezoid.o -c trapezoid.cpp
#g++ -o lowerTriangle.o -c lowerTriangle.cpp
#g++ -o rectangle.o -c rectangle.cpp
#g++ -o lab10 main.o drawPixel.o prompt.o circle.o trapezoid.0 lowerTriangle.o rectangle.o
