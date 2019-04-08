#include "resource_exception.hpp"

sq::resourceNotFound::resourceNotFound(sq::resourceType rtype, const std::string &rname) : std::runtime_error("Resource not found."),
                                                                                                name(rname),
                                                                                                type(rtype)
{}

sq::resourceNotFound::resourceNotFound(sq::resourceType rtype, const std::string &msg, const std::string &rname) : std::runtime_error(msg.c_str()),
                                                                                                                        name(rname),
                                                                                                                        type(rtype){
}

const std::string &sq::resourceNotFound::getResourceName() const {
    return name;
}

sq::resourceType sq::resourceNotFound::getResourceType() const {
    return type;
}
