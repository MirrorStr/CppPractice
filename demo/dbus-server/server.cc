#include <dbus/dbus.h>
#include <stdio.h>
#include <unistd.h>

// 处理客户端调用的方法
DBusHandlerResult handle_method_call(DBusConnection *conn, DBusMessage *msg,
                                     void *user_data) {
    if (dbus_message_is_method_call(msg, "com.example.MyInterface",
                                    "SayHello")) {
        // 从消息中读取参数（示例无参数）
        DBusMessage *reply    = dbus_message_new_method_return(msg);
        const char  *response = "Hello from Server!";
        dbus_message_append_args(reply, DBUS_TYPE_STRING, &response,
                                 DBUS_TYPE_INVALID);

        // 发送回复
        dbus_connection_send(conn, reply, NULL);
        dbus_message_unref(reply);
        return DBUS_HANDLER_RESULT_HANDLED;
    }
    return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
}

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

    // 申请服务名
    int ret = dbus_bus_request_name(conn, "com.example.MyService",
                                    DBUS_NAME_FLAG_REPLACE_EXISTING, &err);
    if (dbus_error_is_set(&err)) {
        fprintf(stderr, "Name Error: %s\n", err.message);
        dbus_error_free(&err);
        return 1;
    }

    // 注册回调函数
    dbus_connection_add_filter(conn, handle_method_call, NULL, NULL);

    // 主循环监听消息
    while (1) {
        dbus_connection_read_write_dispatch(conn, 1000); // 超时1秒
    }

    return 0;
}