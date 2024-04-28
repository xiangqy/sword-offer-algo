#ifndef LOG_SETTING_H_
#define LOG_SETTING_H_

#ifndef SPDLOG_TRACE_ON
#define SPDLOG_TRACE_ON
#endif

#ifndef SPDLOG_DEBUG_ON
#define SPDLOG_DEBUG_ON
#endif

#ifdef _WIN32
#define __FILE_NAME__ \
  (strrchr(__FILE__, '\\') ? (strrchr(__FILE__, '\\') + 1) : __FILE__)
#else
#define __FILE_NAME__ \
  (strrchr(__FILE__, '/') ? (strrchr(__FILE__, '/') + 1) : __FILE__)
#endif

#define SPDLOG_LOGGER_CALL_(level, ...)                               \
  log_setting::GetInstance().GetLogger()->log(                        \
      spdlog::source_loc{__FILE__, __LINE__, SPDLOG_FUNCTION}, level, \
      __VA_ARGS__)
#define LogTrace(...) SPDLOG_LOGGER_CALL_(spdlog::level::trace, __VA_ARGS__)
#define LogDebug(...) SPDLOG_LOGGER_CALL_(spdlog::level::debug, __VA_ARGS__)
#define LogInfo(...) SPDLOG_LOGGER_CALL_(spdlog::level::info, __VA_ARGS__)
#define LogWarn(...) SPDLOG_LOGGER_CALL_(spdlog::level::warn, __VA_ARGS__)
#define LogError(...) SPDLOG_LOGGER_CALL_(spdlog::level::err, __VA_ARGS__)
#define LogCritical(...) \
  SPDLOG_LOGGER_CALL_(spdlog::level::critical, __VA_ARGS__)
#define LogCriticalIf(b, ...)                                    \
  do {                                                           \
    if ((b)) {                                                   \
      SPDLOG_LOGGER_CALL_(spdlog::level::critical, __VA_ARGS__); \
    }                                                            \
  } while (0)

#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/async.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ranges.h"

class log_setting {
public:
    log_setting(const log_setting &) = delete;

    void operator=(const log_setting &) = delete;

    static log_setting &GetInstance();

    [[nodiscard]] std::shared_ptr<spdlog::logger> GetLogger() const;

private:
    void Init();

    log_setting();

    ~log_setting();

    std::shared_ptr<spdlog::logger> spd_logger_;
};

#endif