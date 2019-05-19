const player = require('play-sound')();
var StepSequencer = require('step-sequencer');
const fs = require('fs');
const SerialPort = require('serialport');
const serialport = new SerialPort('/dev/cu.usbmodem14201', { baudRate: 2000000 });

arrr = new Uint8Array()
arr = new Uint8Array()

serialport.on('open', function () {
    console.log('Serial Port is Open');
    serialport.on('data', function (data) {

        arr = new Uint8Array(data)
        // console.log(arr);

        //read data array
        arrr = JSON.parse(fs.readFileSync("./data.json", "utf8"))

    });

});

// Instantiate a new StepSequencer object
var tempo = 60;
var division = 8;
var sequence_0 = [0, 1, 2, 3, 4, 5, 6, 7];
var stepSequencer_0 = new StepSequencer(tempo, division, sequence_0);

// The StepSequencer emits the number of
// the step when that step is to be played
stepSequencer_0.on('0', function (step) {

    if (arrr[0] == 48) {
        player.play('./kick.wav', (err) => {
            if (err) console.log(`Could not play sound: ${err}`);
        });
    }
    // else {
    //     console.log(step);
    // }

})
    .on('1', function (step) {
        if (arrr[1] == 48) {
            player.play('./kick.wav', (err) => {
                if (err) console.log(`Could not play sound: ${err}`);
            });
        }
        // else {
        //     console.log(step);
        // }
    })
    .on('2', function (step) {
        if (arrr[2] == 48) {
            player.play('./kick.wav', (err) => {
                if (err) console.log(`Could not play sound: ${err}`);
            });
        }
        // else {
        //     console.log(step);
        // }
    })
    .on('3', function (step) {
        if (arrr[3] == 48) {
            player.play('./kick.wav', (err) => {
                if (err) console.log(`Could not play sound: ${err}`);
            });
        }
        // else {
        //     console.log(step);
        // }
    })
    .on('4', function (step) {
        if (arrr[4] == 48) {
            player.play('./kick.wav', (err) => {
                if (err) console.log(`Could not play sound: ${err}`);
            });
        }
        // else {
        //     console.log(step);
        // }
    })
    .on('5', function (step) {
        if (arrr[5] == 48) {
            player.play('./kick.wav', (err) => {
                if (err) console.log(`Could not play sound: ${err}`);
            });
        }
        // else {
        //     console.log(step);
        // }
    })
    .on('6', function (step) {
        if (arrr[6] == 48) {
            player.play('./kick.wav', (err) => {
                if (err) console.log(`Could not play sound: ${err}`);
            });
        }
        // else {
        //     console.log(step);
        // }
    })
    .on('7', function (step) {
        if (arrr[7] == 48) {
            player.play('./kick.wav', (err) => {
                if (err) console.log(`Could not play sound: ${err}`);
            });
        }
        // else {
        //     console.log(step);
        // }
    });

stepSequencer_0.play();
