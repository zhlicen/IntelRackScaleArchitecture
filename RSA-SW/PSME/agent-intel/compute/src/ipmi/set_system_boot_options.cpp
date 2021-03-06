/*!
 * @section LICENSE
 *
 * @copyright
 * Copyright (c) 2015 Intel Corporation
 *
 * @copyright
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * @copyright
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * @copyright
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @section DESCRIPTION
 *
 * @file set_system_boot_options.cpp
 *
 * @brief Set System Boot Option Command Implementation.
 * */

#include "set_system_boot_options.hpp"

using namespace agent::compute::ipmi;

request::SetSystemBootOptions::SetSystemBootOptions():
    Request(NetFn::CHASSIS, Cmd::SET_BOOT_ORDER) {}

request::SetSystemBootOptions::SetSystemBootOptions(const SetSystemBootOptions& orig):
    Request(orig) {}

request::SetSystemBootOptions::~SetSystemBootOptions() {}

response::SetSystemBootOptions::SetSystemBootOptions():
    Response(NetFn::CHASSIS, Cmd::SET_BOOT_ORDER, RESPONSE_SIZE) {}

response::SetSystemBootOptions::SetSystemBootOptions(const SetSystemBootOptions& orig):
    Response(orig) {}

response::SetSystemBootOptions::~SetSystemBootOptions() {}
