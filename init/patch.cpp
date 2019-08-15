
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulsei
    if (!isInputDirty<input_INIT>(ctx))
        return;

    Wire.begin();

    // Get a pointer to the `VL53L0X` class instance
    auto sensor = getValue<input_DEV>(ctx);

    // Initialize VL53L0X module
    sensor->init();

    // Don't check for successful initialization - init() returns true even if no VL53L0X connected!
    // Attempt to initialize VL53L0X module; if attempt fails emit pulse from error port
    //if (!sensor->init()) {
        //emitValue<output_ERR>(ctx, 1);
        //return;
    //}

    // set timeout
    sensor->setTimeout(getValue<input_TO>(ctx));

    // Pulse to indicate initialization complete
    emitValue<output_DONE>(ctx, 1);
}
