#ifndef SUBBUS_H_INCLUDED
#define SUBBUS_H_INCLUDED
#include <list>
#include <stdint.h>
// #include <stdbool.h>

#define uDACS_12
#define USE_SUBBUS 0

#ifdef FCC1
  #define BOARD_REV                   "V10:178:HCHO FCC Rev A V1.1"
  #define SUBBUS_BOARD_ID             10
#endif
#ifdef FCC2
  #define BOARD_REV                   "V11:178:HCHO FCC Rev A V1.1"
  #define SUBBUS_BOARD_ID             11
#endif
#ifdef uDACS_12
  #define BOARD_REV                   "V12:178:HCHO uDACS Rev A V1.1"
  #define SUBBUS_BOARD_ID             12
#endif
#if USE_SUBBUS
#define SUBBUS_BUILD_NUM            1
#define SUBBUS_FAIL_RESERVED        0xF000
#define SUBBUS_INTA_ADDR            0x0001
#define SUBBUS_BDID_ADDR            0x0002
#define SUBBUS_FAIL_ADDR            0x0004
#define SUBBUS_SWITCHES_ADDR        0x0005
#define SUBBUS_CACHE_BASE_ADDR      ((uint16_t)0x10)
#define SUBBUS_CACHE_SIZE           ((uint16_t)9)
#define SUBBUS_INTERRUPTS           0

#define SUBBUS_ADDR_CMDS 0x18

class subbus_driver {
  public:
    subbus_driver(uint16_t low, uint16_t high);
    virtual int read( uint16_t addr, uint16_t *rv ) = 0;
    virtual int write( uint16_t addr, uint16_t data) = 0;
    virtual void reset() = 0;
    uint16_t low, high;
};

class subbus_base : public subbus_driver {
  public:
    inline subbus_base() : subbus_driver(0,SUBBUS_BDID_ADDR+1) {}
    int read( uint16_t addr, uint16_t *rv );
    int write( uint16_t addr, uint16_t data);
    void reset();
};

class subbus_fail_sw : public subbus_driver {
  public:
    inline subbus_fail_sw() :
        subbus_driver(SUBBUS_FAIL_ADDR,SUBBUS_SWITCHES_ADDR) {
      fail_reg = 0;
    }
    int read( uint16_t addr, uint16_t *rv );
    int write( uint16_t addr, uint16_t data);
    void reset();
  private:
    uint16_t fail_reg;
};

typedef struct {
  uint16_t address;
  uint16_t bitmask;
} board_intr_t;

typedef struct {
  uint16_t intr_id;
  int active;
} interrupt_t;

class subbus_t {
  public:
    subbus_t();
    void reset(void);
    void add_driver(subbus_driver *drv);
    int read( uint16_t addr, uint16_t *rv );
    int write( uint16_t addr, uint16_t data);
    inline void set_fail(uint16_t arg) {
      this->write(SUBBUS_FAIL_ADDR, arg);
    }
    inline int read_fail(uint16_t *rv) {
      return this->read(SUBBUS_FAIL_ADDR, rv);
    }
    #if SUBBUS_INTERRUPTS
      void init_interrupts(void);
      int intr_attach(int id, uint16_t addr);
      int intr_detach( uint16_t addr );
      void intr_service(void);
      static volatile uint8_t intr_req;
    #endif
  private:
    std::list<subbus_driver *> drivers;
    #if SUBBUS_INTERRUPTS
      static const board_intr_t bd_intrs[];
      static interrupt_t interrupts[N_INTERRUPTS];
    #endif
};
#endif // USE_SUBBUS
#endif
