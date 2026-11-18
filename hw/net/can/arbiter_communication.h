typedef struct {
    uint32_t vm_id;
    uint8_t tx_bit;
    uint8_t bit_position;
} ArbiterRequest;

typedef struct {
    uint8_t arbitration_lost;
} ArbiterResponse;

typedef enum {
    ARBITER_MSG_TX_REQUEST = 1,
    ARBITER_MSG_TX_GRANTED,
    ARBITER_MSG_ARBITRATION_LOST,
    ARBITER_MSG_TX_COMPLETE,
    ARBITER_MSG_TX_FAILED
} ArbiterMessageType;

typedef struct {
    ArbiterMessageType type;
} ArbiterMessage;


#define CAN_DEBUG_LOG "/tmp/can-arbiter-debug.log"

static inline void can_log_timestamp(FILE *f)
{
    struct timespec ts;
    struct tm tm;

    clock_gettime(CLOCK_REALTIME, &ts);
    localtime_r(&ts.tv_sec, &tm);

    fprintf(f,
            "[%04d-%02d-%02d %02d:%02d:%02d.%09ld] ",
            tm.tm_year + 1900,
            tm.tm_mon + 1,
            tm.tm_mday,
            tm.tm_hour,
            tm.tm_min,
            tm.tm_sec,
            ts.tv_nsec);
}

#define CAN_LOG(fmt, ...) do {                  \
    FILE *_f = fopen(CAN_DEBUG_LOG, "a");       \
    if (_f) {                                   \
        can_log_timestamp(_f);                 \
        fprintf(_f, fmt "\n", ##__VA_ARGS__);  \
        fclose(_f);                             \
    }                                           \
} while (0)


