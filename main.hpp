#pragma once

#include <cmath>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <mutex>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "portaudio_backend.hpp"
#include "ShaderProgram.hpp"
#include "Scope.hpp"
#include "Spectrum.hpp"
#include "FFT.hpp"

extern volatile int g_windowWidth;
extern volatile int g_windowHeight;

class MinimalOpenGLApp {
public:
    MinimalOpenGLApp(GLFWwindow* window);

    void setProgram(GLuint program) { m_program = program; }
    void setNumTriangles(int numTriangles) { m_numTriangles = numTriangles; }

private:
    const char* m_windowTitle;
    int m_numTriangles;
    GLFWwindow* m_window;
    GLuint m_program;
};

class VisualizerAudioCallback : public AudioCallback {
public:
    VisualizerAudioCallback(int bufferSize);
    ~VisualizerAudioCallback();
    void process(InputBuffer input_buffer, OutputBuffer output_buffer, int frame_count) override;
    int getBufferSize() { return m_bufferSize; }
    float* getBuffer() { return m_buffer; }
private:
    float* m_buffer;
    const int m_bufferSize;
    int m_writePos;
};
