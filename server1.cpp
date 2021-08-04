#include <drogon/drogon.h>
using namespace drogon;

int main()
{
    auto client = HttpClient::newHttpClient("http://127.0.0.1:8848");
    app().registerHandler("/hello",
        [=](const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback){
            auto request = HttpRequest::newHttpRequest();
            request->setPath("/hello");
            LOG_INFO << "Sending request";
            client->sendRequest(req, [callback = std::move(callback)](ReqResult result, const HttpResponsePtr& resp){
                if(result != ReqResult::Ok || resp->statusCode() != HttpStatusCode::k200OK)
                {
                    LOG_ERROR << "Request failed";
                    auto resp = HttpResponse::newHttpResponse();
                    resp->setStatusCode(HttpStatusCode::k500InternalServerError);
                    callback(resp);
                    return;
                }
                LOG_INFO << "Got response";
                auto r = HttpResponse::newHttpResponse();
		r->setBody("It works");
                callback(r);
            });
        }, {Get});
    app().setThreadNum(0)
        .addListener("127.0.0.1", 8847)
        .run();
}
