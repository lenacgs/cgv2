make:
	g++ -framework OpenGL -framework GLUT -Wno-deprecated initializations.cpp RgbImage.cpp draw.cpp -o main main.cpp