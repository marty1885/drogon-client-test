#include <drogon/drogon.h>
using namespace drogon;

int main()
{
    app().registerHandler("/hello",
        [](const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) {
            auto resp = HttpResponse::newHttpResponse();
            resp->setBody("hello");
            callback(resp);
        }, {Get});
    app().setThreadNum(0)
        .addListener("127.0.0.1", 8848)
        .run();
}
