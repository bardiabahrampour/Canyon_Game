#include <raylib.h>

#include <string>

#include "Common.h"
#include "FileManager.h"
#include "Framework.h"
#include "raywin.h"

// annoying windows nag fix!
#undef LoadImage

// define logger sinks
fsink file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("log.txt", true);
msink msvc_sink = std::make_shared<spdlog::sinks::msvc_sink_mt>();

// create logger function
void create_logger()
{
    spdlog::logger loge("logger", { msvc_sink, file_sink });
    std::shared_ptr<spdlog::logger> lo = std::make_shared<spdlog::logger>(loge);
    spdlog::set_default_logger(lo);
}

// return the functions name
std::string return_func_name(bool line, bool file,
    const std::source_location& location)
{
    std::string tmp;

    // get current function name
    tmp += location.function_name();
    tmp += ' ';

    // add line and file name if asked
    if (line) {
        tmp += std::to_string(location.line());
        tmp += ' ';
    }

    if (file)
        tmp += location.file_name();

    return tmp;
}

int _stdcall wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine,
    _In_ int nShowCmd)
{
#ifndef NDEBUG
    _log::set_level(_log::level::debug);
#endif

    create_logger();
#ifndef NDEBUG
    _log::set_level(_log::level::debug);
#endif
    // quick_start();
    FileManager tmp;
    tmp.GetConfigFromFile();
    std::unique_ptr<Framework> frm = std::make_unique<Framework>();
    frm->init();
    return 0;
}