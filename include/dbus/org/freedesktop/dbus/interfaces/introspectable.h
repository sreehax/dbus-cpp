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
#ifndef DBUS_ORG_FREEDESKTOP_DBUS_INTERFACES_INTROSPECTABLE_H_
#define DBUS_ORG_FREEDESKTOP_DBUS_INTERFACES_INTROSPECTABLE_H_

#include "org/freedesktop/dbus/service.h"

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
class Introspectable
{
public:
    virtual ~Introspectable() = default;

    std::string introspect()
    {
        return service->root_object()->invoke_method_synchronously<Introspect, std::string>();
    }

protected:
    Introspectable(const Service::Ptr& service) : service(service)
    {
    }
private:
    struct Introspect
    {
        typedef Introspectable Interface;
        static std::string name()
        {
            return "Introspect";
        }
        static const bool call_synchronously = true;
        static const std::chrono::milliseconds default_timeout;
    };
    Service::Ptr service;
};
const std::chrono::milliseconds Introspectable::Introspect::default_timeout
{
    10*1000
};
}
namespace traits
{
template<>
struct Service<interfaces::Introspectable>
{
    static const std::string& interface_name()
    {
        static const std::string s
        {"org.freedesktop.DBus.Introspectable"
        };
        return s;
    }
};
}
}
}
}


#endif // DBUS_ORG_FREEDESKTOP_DBUS_INTERFACES_INTROSPECTABLE_H_