#ifndef USBDEVICE_H
#define USBDEVICE_H

#include <string>

using namespace std;

class usbdevice
{
private:
    string ID;
    string vendor;
    string busID;

public:
    usbdevice(string ID, string vendor, string busID);
    string getUsbdeviceID() const { return ID; };
    string getUsbdeviceVendor() const { return vendor; };
    string getUsbdeviceBusID() const { return busID; };
    void setUsbdeviceID(string ID);
    void setUsbdeviceVendor(string vendor);
    void setUsbdeviceBusID(string BusID);

};

#endif // USBDEVICE_H
