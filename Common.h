#pragma once

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/msvc_sink.h>
#include <spdlog/spdlog.h>

#include <source_location>

typedef std::shared_ptr<spdlog::sinks::basic_file_sink_mt> fsink;
typedef std::shared_ptr<spdlog::sinks::msvc_sink_mt> msink;

extern std::shared_ptr<spdlog::sinks::basic_file_sink_mt> file_sink;
extern std::shared_ptr<spdlog::sinks::msvc_sink_mt> msvc_sink;

// creates and inits the global logger
extern void create_logger();

//returns the fucntion name
extern std::string return_func_name(
    bool line = false, bool file = false,
    const std::source_location& location = std::source_location::current());

namespace _log = spdlog;
