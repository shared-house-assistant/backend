enum connection_state {initial, connected, closed} connection_state_t;

int service_pi_socket(const int s, const char *const addr);
