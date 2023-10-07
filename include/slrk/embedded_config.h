#ifndef EMBEDDED_CONFIG_H
#define EMBEDDED_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

static const char *embedded_config = R"(
#module(load="omfwd")
*.* action(type="omfwd" target="192.168.2.252" port="514" protocol="udp"
    action.resumeRetryCount="100" queue.type="linkedList" queue.size="10000")
#stop
)";

#ifdef __cplusplus
}
#endif

#endif

