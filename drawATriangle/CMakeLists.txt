set(target "drawATriangle")

set(CMAKE_CXX_STANDARD 17)

add_executable(${target} "main.cpp" "drawATriangleApplication.h" "drawATriangleApplication.cpp")
target_include_directories(${target} PUBLIC
    "D:/VulkanSDK/1.3.261.1/Include"
    "D:/glfw/glfw-3.3.8/glfw-3.3.8/include/GLFW"
    "D:/glm/glm-master/glm-master/glm"
)

find_library(glfw glfw3 "D:/glfw/glfw-3.3.8/glfw-3.3.8/lib")
find_library(vulkan vulkan-1 "D:/VulkanSDK/1.3.261.1/Lib")
target_link_libraries(${target} ${glfw} ${vulkan})