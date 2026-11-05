typedef struct {
    uint32_t vm_id;
    uint8_t tx_bit;
    uint8_t bit_position;
} ArbiterRequest;

typedef struct {
    uint8_t bus_bit;
    uint8_t arbitration_lost;
} ArbiterResponse;