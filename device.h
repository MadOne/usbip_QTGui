#include <string>
#ifndef DEVICE_H
#define DEVICE_H

class Device
{
public:
    static std::string busid;
    static std::string name;
    static std::string vendor;
    static std::string port;
    static std::string ip;
    static bool is_attached;
    static bool is_shared;

    Device(std::string busid, std::string name, std::string vendor, std::string port, std::string ip, bool is_attached, bool is_shared);
    void bind();
    void unbind(std::string busid);
    void attach(Device);
    void detach(Device);
};

#endif // DEVICE_H
