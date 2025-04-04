#include <dbus/dbus.h>
#include <stdio.h>

int main() {
    DBusConnection *conn;
    DBusError       err;
    dbus_error_init(&err);

    // 连接到会话总线
    conn = dbus_bus_get(DBUS_BUS_SESSION, &err);
    if (dbus_error_is_set(&err)) {
        fprintf(stderr, "Connection Error: %s\n", err.message);
        dbus_error_free(&err);
        return 1;
    }

    // 构造方法调用消息
    DBusMessage *msg =
        dbus_message_new_method_call("com.example.MyService",   // 目标服务名
                                     "/com/example/MyService",  // 对象路径
                                     "com.example.MyInterface", // 接口名
                                     "SayHello"                 // 方法名
        );

    // 发送消息并等待回复
    DBusMessage *reply =
        dbus_connection_send_with_reply_and_block(conn, msg, 1000, &err);
    if (dbus_error_is_set(&err)) {
        fprintf(stderr, "Method Call Error: %s\n", err.message);
        dbus_error_free(&err);
        return 1;
    }

    // 解析回复
    const char *response;
    dbus_message_get_args(reply, &err, DBUS_TYPE_STRING, &response,
                          DBUS_TYPE_INVALID);
    printf("Server says: %s\n", response);

    // 释放资源
    dbus_message_unref(msg);
    dbus_message_unref(reply);
    return 0;
}