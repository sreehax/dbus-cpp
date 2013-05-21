/*
 * Copyright © 2012 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License version 3,
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Thomas Voß <thomas.voss@canonical.com>
 */
#ifndef DBUS_ORG_FREEDESKTOP_DBUS_INTERFACES_PROPERTIES_H_
#define DBUS_ORG_FREEDESKTOP_DBUS_INTERFACES_PROPERTIES_H_

#include "org/freedesktop/dbus/service.h"
#include "org/freedesktop/dbus/traits/service.h"

#include <chrono>
#include <string>

namespace org
{
namespace freedesktop
{
namespace dbus
{
namespace interfaces
{
struct Properties
{
public:
    virtual ~Properties() = default;

    struct GetAll
    {
        typedef Properties Interface;
        static const std::string& name()
        {
            static const std::string s{"GetAll"};
            return s;
        };
        static const std::chrono::milliseconds default_timeout;
    };

    struct Get
    {
        typedef Properties Interface;
        static const std::string& name()
        {
            static const std::string s{"Get"};
            return s;
        };
        static const std::chrono::milliseconds default_timeout;
    };

    struct Set
    {
        typedef Properties Interface;
        static const std::string& name()
        {
            static const std::string s{"Set"};
            return s;
        };
        static const std::chrono::milliseconds default_timeout;
    };
};
const std::chrono::milliseconds Properties::Get::default_timeout
{
    10*1000
};
const std::chrono::milliseconds Properties::GetAll::default_timeout
{
    10*1000
};
const std::chrono::milliseconds Properties::Set::default_timeout
{
    10*1000
};
}

namespace traits
{
template<>
struct Service<interfaces::Properties>
{
    static const std::string& interface_name()
    {
        static const std::string s{"org.freedesktop.DBus.Properties"};
        return s;
    };
};
}
}
}
}
#endif // DBUS_ORG_FREEDESKTOP_DBUS_INTERFACES_INTROSPECTABLE_H_