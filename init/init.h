/*
 * Copyright (C) 2007 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _INIT_INIT_H
#define _INIT_INIT_H

#include <string>

#include <selinux/label.h>

namespace android {
namespace init {

// Note: These globals are *only* valid in init, so they should not be used in ueventd,
// watchdogd, or any files that may be included in those, such as devices.cpp and util.cpp.
// TODO: Have an Init class and remove all globals.
extern const char *ENV[32];
extern std::string default_console;
/* IMPORTANT: THE VALUE OF STORAGE_MEDIA MUST BE CONSISTANT WITH UBOOT */
#define STORAGE_MEDIA_EMMC "storagemedia=emmc"
#define STORAGE_MEDIA_NAND "storagemedia=nand"

extern bool waiting_for_exec;
extern int have_console;
extern std::string console_name;
extern struct selabel_handle *sehandle;
extern struct selabel_handle *sehandle_prop;

void handle_control_message(const std::string& msg, const std::string& arg);

void property_changed(const std::string& name, const std::string& value);

void register_epoll_handler(int fd, void (*fn)());

int add_environment(const char* key, const char* val);

bool start_waiting_for_property(const char *name, const char *value);

void DumpState();

void ResetWaitForProp();

}  // namespace init
}  // namespace android

#endif  /* _INIT_INIT_H */
