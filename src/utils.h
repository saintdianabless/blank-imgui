#pragma once

struct ImVec4;
struct GLFWwindow;

GLFWwindow *SetupGuiEnv(const char *title, int w, int h);
void Rendering(GLFWwindow *window, const ImVec4 &clear_color);
void CleanupGuiEnv(GLFWwindow *window);
