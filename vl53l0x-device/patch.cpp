// Tell XOD where it could download the library:
#pragma XOD require "https://github.com/pololu/vl53l0x-arduino"

//Include C++ libraries
{{#global}}
#include <VL53L0X.h>
#include <Wire.h>
{{/global}}

// Reserve memory to store an instance of the class,
// and create the instance later:
struct State {
    uint8_t mem[sizeof(VL53L0X)];
};

// Define our custom type as a pointer on the class instance.
using Type = VL53L0X*;

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // It should be evaluated only once on the first (setup) transaction
    if (!isSettingUp())
        return;

    auto state = getState(ctx);

    // Create a new object in the memory area reserved previously.
    Type sensor = new (state->mem) VL53L0X();

    emitValue<output_DEV>(ctx, sensor);
}
