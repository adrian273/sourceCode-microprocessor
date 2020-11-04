/***
 * Adrian Verdugo ( アドリアン　)
 * @github adrian273
 * @since 11/4/2020
 * 
 */
const express = require("express");
const app = express();
const port = 4000;
var five = require("johnny-five"),
    board, button;
// -----------------------------------------------------------------------------------------------------
board = new five.Board();
const server = app.listen(`${port}`, function () {
    console.log(`Server started on port ${port}`);
});
// ------------------------------------------------------------------------------------------------------
const io = require("socket.io")(server);
// ------------------------------------------------------------------------------------------------------

board.on("ready", function () {
    console.log('ready')
})

setTimeout(() => {

    io.on("connection", socket => {
        console.log('yasli')
        // Create a new `button` hardware instance.
        // This example allows the button module to
        // create a completely default instance
        btn12 = new five.Button(12);
        btn11 = new five.Button(11);
        btn10 = new five.Button(10);
        btn9 = new five.Button(9);

        // "up" the button is released
        btn12.on("up", function () {
            io.emit('play', 1);
        });

        // "up" the button is released
        btn11.on("up", function () {
            io.emit('play', 2);
        });

        // "up" the button is released
        btn10.on("up", function () {
            io.emit('play', 3);
        });

        // "up" the button is released
        btn9.on("up", function () {
            io.emit('play', 4);
        });

    });

}, 3000)