#include "log_setting.h"

log_setting::log_setting(){
    Init();
}

log_setting::~log_setting(){
    spdlog::drop_all();
}

log_setting& log_setting::GetInstance(){
    static log_setting log_setting_instance;
    return log_setting_instance;
}

std::shared_ptr<spdlog::logger> log_setting::GetLogger()const{
    return spd_logger_;
}

void log_setting::Init(){
   auto async_console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_st>();
   auto async_logger = std::make_shared<spdlog::async_logger>("async_logger", async_console_sink, spdlog::thread_pool(), spdlog::async_overflow_policy::block);
   async_logger->set_level(spdlog::level::trace);
   async_logger->flush_on(spdlog::level::warn);

   auto rotating_file_sink = std::make_shared<spdlog::sinks::rotating_file_sink_st>("./logs/logs.txt", 5 * 1024 * 1024, 3);
   auto file_logger = std::make_shared<spdlog::logger>("file_logger", rotating_file_sink);
   file_logger->set_level(spdlog::level::trace);
   file_logger->flush_on(spdlog::level::warn);

   spdlog::sinks_init_list sinks = {async_console_sink, rotating_file_sink};
   spd_logger_ = std::make_shared<spdlog::logger>("logger", sinks.begin(), sinks.end());

   spdlog::set_default_logger(spd_logger_);
//    spdlog::set_pattern("[%Y-%m-%d %H:%M:%S:%e] [%n] [%l] [%v] [%t]");
}