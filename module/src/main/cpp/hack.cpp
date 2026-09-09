//
// Created by Perfare on 2020/7/4.
//

#include "hack.h"
#include "game.h"
#include <cstring>
#include <cstdio>
#include <unistd.h>
#include <sys/system_properties.h>
#include <dlfcn.h>
#include "il2cpp_dump.h"
#include "log.h"
#include "xdl.h"

static int GetAndroidApiLevel() {
    char prop_value[PROP_VALUE_MAX];
    __system_property_get("ro.build.version.sdk", prop_value);
    return atoi(prop_value);
}

void hack_start(const char *game_data_dir) {
    bool load = false;

    for (int i = 0; i < 10; i++) {
        void *handle = xdl_open(GameLibraryName, 0);

        if (handle) {
            load = true;

            il2cpp_api_init(handle);

            LOGI("Waiting 180 seconds for gameplay assemblies...");
            sleep(180);

            LOGI("Starting delayed IL2CPP dump...");
            il2cpp_dump(game_data_dir);

            break;
        } else {
            sleep(1);
        }
    }

    if (!load) {
        LOGI("%s not found in thread %d", GameLibraryName, gettid());
    }
}

void hack_prepare(const char *game_data_dir) {
    LOGI("hack thread: %d", gettid());
    int api_level = GetAndroidApiLevel();
    LOGI("api level: %d", api_level);
    hack_start(game_data_dir);
}
