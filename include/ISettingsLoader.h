#pragma once

namespace i_settings_loader {

enum SETTING_TYPE {
    SETTING_TYPE_FIRST = 0,
    SETTING_TYPE_WEB_ADDRESS = SETTING_TYPE_FIRST,
    SETTING_TYPE_HOST_NAME,
    SETTING_TYPE_CHANNEL_NUMBER,

    SETTING_TYPE_LAST,
};

class ISettingsLoader {

public:

    virtual const char *GetAsString(const SETTING_TYPE type) = 0;

};

} /* namespace i_settings_loader */
