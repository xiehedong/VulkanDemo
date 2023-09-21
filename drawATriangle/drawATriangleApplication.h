
#include<vulkan/vulkan.h>
#include<Windows.h>
#include<vulkan/vulkan_win32.h>
#include<glfw3.h>
#include<vector>


struct QueueFamilyIndices
{
    int m_graphicsFamily = -1;///<支持绘制指令的队列族
    int m_presentFamily = -1;///<支持显示指令的队列族

    bool isCompleted()
    {
        return m_graphicsFamily >= 0 && m_presentFamily >= 0;
    }
};

class DrawATriangleApplication
{
public:
    DrawATriangleApplication();
    ~DrawATriangleApplication();

    void run();

private:
    void initWindow();
    void initVulkan();
    void mainLoop();
    void cleanup();

    void createInstance();
    void setupDebugMessage();
    void createSurface();
    void pickPhysicalDevice();
    void createLogicDevice();

    bool checkValidationLayerSupport();//检查系统是否支持验证层
    std::vector<const char*> getRequiredExtension();
    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
    VkResult createDebugUtilsMessengerEXT(VkInstance instance, 
        const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, 
        const VkAllocationCallbacks* pAllocator, 
        VkDebugUtilsMessengerEXT* pDebugMessenger);
    void destroyDebugUtilsMessengerEXT(VkInstance instance, 
        VkDebugUtilsMessengerEXT debugMessenger, 
        const VkAllocationCallbacks* pAllocator);
    bool isDeviceSuitable(VkPhysicalDevice device);
    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

private:
    GLFWwindow* m_window;
    VkInstance m_instance;
    VkDebugUtilsMessengerEXT m_debugMessenger;
    VkPhysicalDevice m_physicalDevice;
    VkDevice m_device;
    VkQueue m_graphicsQueue;
    VkQueue m_presentQueue;
    VkSurfaceKHR m_surface;
};