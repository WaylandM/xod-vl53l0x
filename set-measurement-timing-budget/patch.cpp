
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `VL53L0X` class instance
    auto sensor = getValue<input_DEV>(ctx);

    // set measurement timing budget
    sensor->setMeasurementTimingBudget(getValue<input_MTB>(ctx));

    // Attempt to set measurement timing budget; if attempt fails emit pulse from error port
    //if (!sensor->setMeasurementTimingBudget(getValue<input_MTB>(ctx))) {
        //emitValue<output_ERR>(ctx, 1);
        //return;
    //}

    emitValue<output_DONE>(ctx,1);
}
