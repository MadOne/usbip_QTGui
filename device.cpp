#include "device.h"
#include "systemCommands.h"
Device::Device(std::string bus, std::string name, std::string vendor, std::string port, std::string ip, bool is_attached, bool is_shared)
{
    busid = busid;
    name = name;
    vendor = vendor;
    port = port;
    ip = ip;
    is_attached = is_attached;
    is_shared = is_shared;
};

void bind()
{
    localBind(QString::fromStdString(Device::busid));
    Device::is_shared = true;
};
void unbind(Device)
{
    localUnbind(QString::fromStdString(Device::busid));
    Device::is_shared = false;
};
void attach(Device)
{
    remoteAttach(QString::fromStdString(Device::ip), QString::fromStdString(Device::busid));
    Device::is_attached = true;
};
void detach(Device)
{
    attachedDetach(QString::fromStdString(Device::port));
    Device::is_attached = true;
};