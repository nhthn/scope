all:
	g++ -g FFT.cpp Spectrum.cpp Scope.cpp ShaderProgram.cpp portaudio_backend.cpp main.cpp -o scope -lGL -lGLU -lGLEW -lglfw -lportaudio -lfftw3
