#ifndef CONTROL_H_INCLUDED
#define CONTROL_H_INCLUDED
#include <stdint.h>
#include "usart.h"
#include "subbus.h"

class Control {
  public:
    Control(subbus_t *sb);
    void poll();
    void SendMsg(const char *);			// Send String Back to Host via USB
    void SendCode(int8_t code);
    void SendCodeVal(int8_t, uint16_t);
    void SendErrorMsg(const char *msg);
  private:
    int read_hex( uint8_t **sp, uint16_t *rvp);
    void hex_out(uint16_t data);
    void read_multi(uint8_t *cmd);
    void parse_command(uint8_t *cmd);
    static const int RECV_BUF_SIZE = USART_CTRL_RX_BUFFER_SIZE;
    uint8_t cmd[RECV_BUF_SIZE];							// Current Command
    int cmd_byte_num;
    subbus_t *sb;
    #ifdef CMD_RCV_TIMEOUT
      int cmd_rcv_timer;
    #endif
};

#endif