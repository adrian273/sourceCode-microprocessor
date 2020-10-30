/***
 * Adrian Verdugo ( アドリアン　)
 * @github adrian273
 * @since 10/29/2020
 * 
 */
const express = require("express");
const app = express();
const port = 4000;
const five = require("johnny-five");
// -----------------------------------------------------------------------------------------------------
const board = new five.Board({ repl: false });
const server = app.listen(`${port}`, function () {
    console.log(`Server started on port ${port}`);
});
// ------------------------------------------------------------------------------------------------------
const io = require("socket.io")(server);
// ------------------------------------------------------------------------------------------------------

board.on("ready", function () {
    console.log('ready')
})

io.on("connection", socket => {
    socket.broadcast.on("ledOn", (data) => {
        var key = Object.keys(data)
        key.forEach((k) => {
            const led = new five.Led(data[k].valu)
            if (data[k].on == "0") {
                led.off()
            } else {
                led.on();
            }
        })
    });
});