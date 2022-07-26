#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>

#include <glog/logging.h>
// #include <json/json.h>
#include <jsoncpp/json/json.h>

// 直接使用 <json/json.h>, 那么 cmakelist 里 需要加  include_directories "/usr/local/jsoncpp"
// 或者直接此处  <jsoncpp/json/json.h>, 则不用单独在 cmakelist中添加, 因为默认搜索路径包含/usr/local

std::vector<std::string> split(std::string s, std::string delim) {
  int i = 1;
  std::vector<std::string> result;

  boost::split(result, s, boost::is_any_of(delim.c_str()));

  std::cout << "NEMA FULL: " << s << "\n";
  for (const auto& item : result) {
	  std::cout << "NEMA DELIM[" << i++ << "]:" << item << "\n";
  }

  return result;
}

void init_glog(char *process_name, const char *log_path)
{
    FLAGS_log_dir     = log_path;  //日志文件的存储路径
    FLAGS_minloglevel = google::INFO;

    FLAGS_logbufsecs       = 3;     //缓冲日志输出，默认为30秒，此处改为立即输出
    FLAGS_max_log_size     = 100;   //最大日志大小为 100MB
    FLAGS_colorlogtostderr = true;  //设置输出到屏幕的日志显示相应颜色
    FLAGS_stderrthreshold  = 1;     //将级别为1（以上）日志的输出到终端显示
    FLAGS_alsologtostderr  = true;  //是否输出日志到终端显示

    google::InitGoogleLogging(process_name);
    // google::SetLogDestination(google::GLOG_INFO, log_path);
}


// 测试json库调用
int test_json_lib(std::string &json_str)
{
    int ret = 0;
    Json::Value root;
    std::string err;
    Json::CharReaderBuilder reader_builder;
    std::unique_ptr<Json::CharReader> const reader(reader_builder.newCharReader());

    try
    {
        int size = 0;
        bool res = reader->parse(json_str.c_str(), json_str.c_str() + json_str.size(), &root, &err);
        if (!res || !err.empty())
        {
            LOG(INFO) << "load config fail.";
            return -1;
        }

        LOG(INFO) << "parse json json_str success, name:" << root["name"];
    }
    catch (std::exception &ex)
    {
        LOG(INFO) << "exception, parse json json_str error" << ex.what();
        return -1;
    }

    return 0;
}

int main(int argc, char *argv[])
{
    std::string s = "$GPCHC,0,766.08,0.00,-0.63,-0.73,0.38,-0.04,0.08,0.0127,-0.0111,0.9991,0.00000000,0.00000000,0.00,0.000,0.000,0.000,0.000,0,0,01,0,2*5A";
    std::string delm =",*";

    init_glog(argv[0], "/tmp");

    split(s, delm);

    std::string json_test ="{\"name\":\"my\"}";
    test_json_lib(json_test);

    LOG(INFO)  << "Hello Third Party Include!" << std::endl;

    // use a shared ptr
    boost::shared_ptr<int> isp(new int(4));

    // trivial use of boost filesystem
    boost::filesystem::path path = "/usr/share/cmake/modules";
    if(path.is_relative())
    {
        LOG(INFO) << "Path is relative" << std::endl;
    }
    else
    {
        LOG(INFO) << "Path is not relative" << std::endl;
    }

   return 0;
}
