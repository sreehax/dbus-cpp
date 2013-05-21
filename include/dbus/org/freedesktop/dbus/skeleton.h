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
#ifndef DBUS_ORG_FREEDESKTOP_DBUS_SKELETON_H_
#define DBUS_ORG_FREEDESKTOP_DBUS_SKELETON_H_

#include "org/freedesktop/dbus/bus.h"
#include "org/freedesktop/dbus/service.h"

namespace org
{
namespace freedesktop
{
namespace dbus
{
template<typename T>
class Skeleton : public T
{
public:
    virtual ~Skeleton() noexcept = default;

protected:
    explicit Skeleton(const Bus::Ptr& bus) : bus(bus),
        service(Service::add_service<T>(bus))
    {
    }

    const Bus::Ptr& access_bus() const
    {
        return bus;
    }

    const Service::Ptr& access_service() const
    {
        return service;
    }

private:
    Bus::Ptr bus;
    Service::Ptr service;
};
}
}
}
#endif // DBUS_ORG_FREEDESKTOP_DBUS_SKELETON_H_