#include <stdio.h>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_opengl3_loader.h"
#include "imnodes.h"
#include "implot.h"
#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>

#include "utils.h"

int main(int, char **) {
  auto window = SetupGuiEnv("Empty ImGui Project", 1200, 800);
  if (window == nullptr) {
    fprintf_s(stderr, "failed to init env");
    return 1;
  }

  ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

  // Main loop
  while (!glfwWindowShouldClose(window)) {
    // Poll and handle events (inputs, window resize, etc.)
    // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to
    // tell if dear imgui wants to use your inputs.
    // - When io.WantCaptureMouse is true, do not dispatch mouse input data to
    // your main application, or clear/overwrite your copy of the mouse data.
    // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input
    // data to your main application, or clear/overwrite your copy of the
    // keyboard data. Generally you may always pass all inputs to dear imgui,
    // and hide them from your application based on those two flags.
    glfwPollEvents();

    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::ShowDemoWindow();
    ImNodes::BeginNodeEditor();
    ImNodes::EndNodeEditor();
    if (ImPlot::BeginPlot("My Plot")) {
      ImPlot::EndPlot();
    }

    // Rendering
    Rendering(window, clear_color);
  }

  CleanupGuiEnv(window);

  return 0;
}
