#include "resource_exception.hpp"

sq::resource_not_found::resource_not_found(sq::resource_type rtype, const std::string &rname) : std::runtime_error("Resource not found."),
                                                                                                name(rname),
                                                                                                type(rtype)
{
}

sq::resource_not_found::resource_not_found(sq::resource_type rtype, const std::string &msg, const std::string &rname) : std::runtime_error(msg.c_str()),
                                                                                                                        name(rname),
                                                                                                                        type(rtype)
{
}

const std::string &sq::resource_not_found::get_resource_name() const
{
    return name;
}

sq::resource_type sq::resource_not_found::get_resource_type() const
{
    return type;
}