#ifndef CAMERA_H
#define CAMERA_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>
#include <math.h>

enum CameraMovement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;

class Camera
{
public:
    glm::vec3 position, front, up, right, worldUp;
    float yaw, pitch;
    float movSpeed, mouseSens, zoom;

    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH);
    Camera(float posx, float posy, float posz, float upx, float upy, float upz, float yaw, float pitch);

    glm::mat4 getViewMatrix();
    void processKeys(CameraMovement direction, float deltaTime);
    void processMouseMovement(float xoffset, float yoffset, bool countraintPitch = true);
    void processMouseScroll(float yOffset);

private:
    void updateCameraVectors();
};

#endif // CAMERA_H
