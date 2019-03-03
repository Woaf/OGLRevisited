#include "camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
    : front(glm::vec3(0.0f, 0.0f, -1.0f)), movSpeed(SPEED), mouseSens(SENSITIVITY), zoom(ZOOM)
{
    this->position = position;
    this->worldUp = up;
    this->yaw = yaw;
    this->pitch = pitch;
    updateCameraVectors();
}

Camera::Camera(float posx, float posy, float posz, float upx, float upy, float upz, float yaw, float pitch)
    : front(glm::vec3(0.0f, 0.0f, -1.0f)), movSpeed(SPEED), mouseSens(SENSITIVITY), zoom(ZOOM)
{
    this->position = glm::vec3(posx, posy, posz);
    this->worldUp = glm::vec3(upx, upy, upz);
    this->yaw = yaw;
    this->pitch = pitch;
    updateCameraVectors();
}

glm::mat4 Camera::getViewMatrix()
{
    return glm::lookAt(position, position + front, up);
}

void Camera::processKeys(CameraMovement direction, float deltaTime)
{
    float velocity = movSpeed * deltaTime;

    if(direction == FORWARD)
        position += front * velocity;
    if(direction == BACKWARD)
        position -= front * velocity;
    if(direction == LEFT)
        position -= right * velocity;
    if(direction == RIGHT)
        position += right * velocity;

}

void Camera::processMouseMovement(float xoffset, float yoffset, bool constraintPitch)
{
    xoffset *= mouseSens;
    yoffset *= mouseSens;

    yaw += xoffset;
    pitch -= yoffset;

    if(constraintPitch)
    {
        if(pitch > 89.0f)
            pitch = 89.0f;
        if(pitch < -89.0f)
            pitch = -89.0f;
    }
    updateCameraVectors();
}

void Camera::processMouseScroll(float yOffset)
{
    if(zoom >= 1.0f && zoom <= 45.0f)
        zoom -= yOffset;
    if(zoom <= 1.0f)
        zoom = 1.0f;
    if(zoom >= 45.0f)
        zoom = 45.0f;
}

void Camera::updateCameraVectors()
{
    glm::vec3 front;
    front.x = cosf(glm::radians(yaw)) * cosf(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sinf(glm::radians(yaw)) * cosf(glm::radians(pitch));
    this->front = glm::normalize(front);

    this->right = glm::normalize(glm::cross(this->front, worldUp));
    this->up = glm::normalize(glm::cross(right, this->front));
}
