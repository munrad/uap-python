#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "UaParser.h"


namespace py = pybind11;


std::shared_ptr<uap_cpp::UserAgentParser> p;
bool is_parser_initialized = false;

void init_parser(const std::string& regex_file_path) {
    if (!is_parser_initialized) {
        p = std::make_shared<uap_cpp::UserAgentParser>(regex_file_path);
        is_parser_initialized = true;
    }
}

uap_cpp::UserAgent parse(const std::string& ua) {
    if (!is_parser_initialized) {
        throw std::runtime_error("UserAgentParser not initialized. Call init_parser first.");
    }
    return p->parse(ua);
}

PYBIND11_MODULE(pyuapcpp, m) {
	m.doc() = "Python wrapper for the uap-cpp library";

	m.def("init_parser", &init_parser, "Initialize the parser with the regex file path");
    m.def("parse", &parse, "Parse a user agent string");

    py::class_<uap_cpp::Generic>(m, "Generic")
        .def(py::init<>())
        .def_readwrite("family", &uap_cpp::Generic::family);

    py::class_<uap_cpp::Agent>(m, "Agent")
        .def(py::init<>())
        .def("toString", &uap_cpp::Agent::toString)
        .def("toVersionString", &uap_cpp::Agent::toVersionString)
        .def_readwrite("family", &uap_cpp::Agent::family)
      	.def_readwrite("major", &uap_cpp::Agent::major)
        .def_readwrite("minor", &uap_cpp::Agent::minor)
        .def_readwrite("patch", &uap_cpp::Agent::patch)
        .def_readwrite("patch_minor", &uap_cpp::Agent::patch_minor);

    py::class_<uap_cpp::Device>(m, "Device")
      	.def(py::init<>())
      	.def_readwrite("family", &uap_cpp::Device::family)
        .def_readwrite("model", &uap_cpp::Device::model)
        .def_readwrite("brand", &uap_cpp::Device::brand);

    py::class_<uap_cpp::UserAgent>(m, "UserAgent")
        .def(py::init<>())
        .def("toFullString", &uap_cpp::UserAgent::toFullString)
        .def("isSpider", &uap_cpp::UserAgent::isSpider)
        .def_readwrite("device", &uap_cpp::UserAgent::device)
        .def_readwrite("os", &uap_cpp::UserAgent::os)
        .def_readwrite("browser", &uap_cpp::UserAgent::browser);
}