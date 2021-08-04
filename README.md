A quick stress test tool to test drogon's HTTP server and client working together.

How to use:

`server2` is a dummy servre that simply replies "hello" on the path `/hello`. On port 8848

`server1` is a proxy-like service that sends a request to server2 and replies if the request is successful. On port 8847

To stress test the setup, Launch server2 beforce server1. Then benchmark against server1:

```

./server2 & # Run in background
./server1 & # Run in background

wrk -c 4 -t 4 -d 10 http://localhost:8847/hello
```
