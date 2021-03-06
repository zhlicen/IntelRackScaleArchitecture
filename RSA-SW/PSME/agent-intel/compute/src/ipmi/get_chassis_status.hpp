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
 * @file get_chassis_status.hpp
 *
 * @brief IPMI Get Chassis Status Command.
 * */

#ifndef AGENT_IPMI_GET_CHASSIS_STATUS_HPP
#define	AGENT_IPMI_GET_CHASSIS_STATUS_HPP

#include "request.hpp"
#include "response.hpp"

#include <cstdint>
#include <vector>
#include <map>

#include <iostream>

namespace agent {
namespace compute {
namespace ipmi {

namespace request {

using std::vector;
/*!
 * @brief Request message for IPMI Get Chassis Status command.
 */
class GetChassisStatus: public Request {
public:
    /*!
     * @brief Default constructor.
     */
    GetChassisStatus();

    /*!
     * @brief Copy constructor.
     * @param orig object to be copied.
     */
    GetChassisStatus(const GetChassisStatus& orig);

    /*!
     * @brief Default destructor.
     */
    virtual ~GetChassisStatus();

    virtual void pack(vector<uint8_t>& data) const;

private:

};
}

namespace response {

using std::map;
using std::vector;
using std::string;

/*!
 * @brief Response message for IPMI Get Chassis Status command. Retrieves information about current chassis power status.
 */
class GetChassisStatus: public Response {
public:

    /*!
     * @brief Represents Power Restore Policy for Chassis.
     *
     * Maps behvaior of the Chassis after power loss.
     */
    enum class PowerRestorePolicy: uint8_t {
        STAY_POWERED_OFF = 0x00,
        RETURN_TO_PREVIOUS_STATE,
        ALWAYS_POWERS_UP,
        UNKNOWN = 0x03,
    };

    /*!
     * @brief Represents last occured Power Event.
     */
    enum class PowerEvent: uint8_t {
        AC_FAILED = 0x00,
        POWER_OVERLOADED = 0x02,
        POWER_INTERLOCK_ACTIVATED = 0x04,
        POWER_FAULT = 0x08,
        LAST,
        UNKNOWN,
    };

    enum class ChassisIdentifyState: uint8_t {
        OFF,
        TEMPORARY_ON,
        ON,
        RESERVED = 0x03,
        LAST,
        UNKNOWN,
    };

    /*!
     * @brief Default constructor.
     */
    GetChassisStatus();

    /*!
     * @brief Copy constructor.
     * @param orig object to be copied.
     */
    GetChassisStatus(const GetChassisStatus& orig);

    /*!
     * @brief Default destructor.
     */
    virtual ~GetChassisStatus();

    const string& get_power_state_name() const {
        return m_power_state_name.at(is_power_on());
    }

    /**
     * Checks if Chassis is powered up.
     * @return true if powered up, otherwise false.
     */
    bool is_power_on() const {
        return m_power_on;
    }

    /**
     * Checks if Chassis is powered down.
     * @return true if powered down, otherwise false.
     */
    bool is_power_off() const {
        return !is_power_on();
    }

    virtual void unpack(const vector<uint8_t>& data);

private:
    map <bool, string> m_power_state_name = {
        {true,  "ON"},
        {false, "OFF"}
    };

    bool m_power_on{false};

    static constexpr uint8_t MASK_SYSTEM_POWER = 0x01;
    static constexpr size_t RESPONSE_SIZE = 5;
    static constexpr size_t OFFSET_POWER_STATUS = 1;


};
}

}
}
}

#endif	/* AGENT_IPMI_GET_CHASSIS_STATUS_HPP */

