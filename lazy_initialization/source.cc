#include <mutex>

class X
{
private:
    connection_info connection_details;
    connection_handle connection;
    std::once_flag connection_init_flag;

    void open_connection()
    {
        connection = connection_manager.open(connection_details);
    }

public:
    X(connection_info const &connection_details_)
        : connection_details(connection_details_)
    {
    }

    void send_data(data_packet const &data)
    {
        std::call_once(connection_init_flag, &X::open_connection, this);
        return connection.send_data();
    }

    void receive_data(data_packet const &data)
    {
        std::call_once(connection_init_flag, &X::open_connection, this);
        return connection.receive_data();
    }
};