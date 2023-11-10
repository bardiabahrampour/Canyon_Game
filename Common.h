#pragma once

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/msvc_sink.h>
#include <spdlog/spdlog.h>

typedef std::shared_ptr<spdlog::sinks::basic_file_sink_mt> fsink;
typedef std::shared_ptr<spdlog::sinks::msvc_sink_mt> msink;

extern std::shared_ptr<spdlog::sinks::basic_file_sink_mt> file_sink;
extern std::shared_ptr<spdlog::sinks::msvc_sink_mt> msvc_sink;

extern void create_logger();