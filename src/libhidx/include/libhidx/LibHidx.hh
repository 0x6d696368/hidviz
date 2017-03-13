#ifndef HIDVIZ_HIDLIB_HH
#define HIDVIZ_HIDLIB_HH

#include "Device.hh"

#include <libusb-1.0/libusb.h>

#include <vector>
#include <list>

namespace libhidx {

    class LibHidx {
    public:
        LibHidx();
        LibHidx(const LibHidx&) = delete;
        LibHidx(LibHidx&&);
        ~LibHidx();

        void loadDevices();
        const auto& getDevices(){return m_devices;}

    private:
        libusb_context* ctx = nullptr;
        std::vector<Device> m_devices;
        libusb_device** m_deviceList;
    };

}


#endif //HIDVIZ_HIDLIB_HH