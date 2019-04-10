#include "resource_exception.hpp"

sq::ResourceNotFound::ResourceNotFound(sq::ResourceType rtype, const std::string &rname) : std::runtime_error("Resource not found."),
                                                                                                name(rname),
                                                                                                type(rtype)
{}

sq::ResourceNotFound::ResourceNotFound(sq::ResourceType rtype, const std::string &msg, const std::string &rname) : std::runtime_error(msg.c_str()),
                                                                                                                        name(rname),
                                                                                                                        type(rtype){
}

const std::string &sq::ResourceNotFound::getResourceName() const {
    return name;
}

sq::ResourceType sq::ResourceNotFound::getResourceType() const {
    return type;
}
