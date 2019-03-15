var colorPicker = new iro.ColorPicker("#color-picker", {
    width: 200
})
colorPicker.on("color:change", onColorChange)

function onColorChange(color, chg) {
    eel.setColor(color.rgb)
}